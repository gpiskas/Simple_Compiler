void yyerror(char *s)
{
   fputs(s,stderr); putc('\n',stderr);
}

void Init_Hash_Table(void)
{  int i;

   for(i=0; i<SYM_TABLE_SIZE; i++)
      ht.table[i]=NULL;
}

void Init_Cross_Link_Head(void)
{  int i;

   for(i=0; i<MAX_CROSS_LINKS; i++)
      Cross_Link_Head[i]=NULL;
}

AstNode *MkNode(int tipos,symbol *sn,
              AstNode *z0,AstNode *z1,AstNode *z2,AstNode *z3)
{  AstNode *p;

   p=(AstNode *)malloc(sizeof(AstNode));
   if(!p)
   {
      printf("Out of memory\n");
      exit(1);
   }
   else
   {
      p->NodeType=tipos;
      p->SymbolNode=sn;
      p->pAstNode[0]=z0;
      p->pAstNode[1]=z1;
      p->pAstNode[2]=z2;
      p->pAstNode[3]=z3;
      return(p);
   }
}

void push_vs(symbol *p)
{
   vs[++TopOfStack]=p;
}

symbol *pop_vs(void)
{
   return(vs[TopOfStack--]);
}

symbol *new_symbol(char *name)
{  symbol *symbp;

   if(!Symbol_free)
      symbp=(symbol *)malloc(sizeof(symbol));
   else
   {
      symbp=Symbol_free;
      Symbol_free=Symbol_free->Next_in_Cross_Link;
   }
   memset(symbp,0,sizeof(symbol));
   strncpy(symbp->name,name,(strlen(name)>NAME_MAX)?NAME_MAX:strlen(name));
   symbp->timi=0;
   symbp->disposable=FALSE;
   symbp->memloc=-1;
   symbp->Next_in_Cross_Link=NULL;
   symbp->NextSymbol=NULL;
   symbp->PrevSymbol=NULL;
   return(symbp);
}

int set_class_types(symbol *symbp, int class_tipos)
{
   switch(class_tipos)
   {
      case INTEGER:
         if(symbp->typos) return(1); 
         symbp->typos=class_tipos;
      break;
   }
   return(0);
}

void cpy_attributes(symbol *dst, symbol *src)
{  symbol *p;
   int ret_v;

   if(src)
   {
      for(p=dst; p; p=p->Next_in_Cross_Link)
      {
         if(src->typos)
         {
            ret_v=set_class_types(p,src->typos);
            if(ret_v)
            {
               printf("One type permitted\n");
               exit(1);
            }
         }
      }
   }
}


symbol *reverse_cross_links(symbol *symbp)
{  symbol *previous, *current, *next;
 
   if(!symbp) 
      return(NULL);
   previous=symbp;
   current=symbp->Next_in_Cross_Link;
   while(current)
   {
      next=current->Next_in_Cross_Link;
      current->Next_in_Cross_Link=previous;
      previous=current;
      current=next;
   }
   symbp->Next_in_Cross_Link=NULL;
   return(previous);
}

void Link_Symbol_to_Cross_Link(symbol *symbp)
{  symbol *p;

   if(!symbp)
      return;
   p=Cross_Link_Head[0];
   if(p)
   {
      for(; p->Next_in_Cross_Link; p=p->Next_in_Cross_Link);
      p->Next_in_Cross_Link=symbp;
   }
   else
      Cross_Link_Head[0]=symbp;
}

int mkkey(char *s)
{  char *p;
   int athr=0;
   for(p=s; *p; p++) athr=athr+(*p);
   return (athr % SYM_TABLE_SIZE);
}

void addsymb(symbol *symbp)
{  int i;
   symbol *p;

   i=mkkey(symbp->name);
   p=ht.table[i];
   symbp->NextSymbol=p;
   symbp->PrevSymbol=NULL;
   if(p) p->PrevSymbol=symbp;
   ht.table[i]=symbp;
   ht.numbsymbols++;
   symbp->memloc=ht.numbsymbols;
}

symbol *findsymb(char *onoma)
{  int i;
   symbol *p;

   i=mkkey(onoma);
   p=ht.table[i];
   while(p && (strcmp(p->name,onoma) !=0))
      p=p->NextSymbol;
   return(p);
}

void add_symbols_to_table(symbol *symbp)
{  symbol *exists, *neo;

   neo=symbp;
   while(neo)
   {
      exists=findsymb(neo->name);
      if( !exists )
      {
         addsymb(neo);
         neo=neo->Next_in_Cross_Link;
      }
           /* -- exists -- */
      else
      {
         printf("%s Redeclaration.\n",neo->name);
         exit(1);
      }
   } /* -- end while -- */
}

void discard_symbol(symbol *symbp)
{
   if(symbp)
   {
      if(symbp->disposable)
      {
         symbp->Next_in_Cross_Link=Symbol_free;
         Symbol_free=symbp;
      }
   }
}

symbol *create_id(symbol *symbp)
{  symbol *p;
  
   p=new_symbol("");
   memcpy(p,symbp,sizeof(symbol));
   p->disposable=TRUE;
   p->Next_in_Cross_Link=NULL;
   p->NextSymbol=NULL;
   p->PrevSymbol=NULL;
   return(p);
}

void copy_value(symbol *dst, symbol *src)
{
   dst->timi=src->timi;
}

void copy_symbol(symbol *dst, symbol *src)
{  
   dst->typos=src->typos;
   copy_value(dst,src);
}

symbol *check_unary_minus(symbol *opnd)
{
    symbol *p;
    p=new_symbol("");
    copy_symbol(p,opnd);
    p->disposable=TRUE;
    p->timi=-opnd->timi;
    discard_symbol(opnd);
    return(p);
}

symbol *check_multop(symbol *opnd1, symbol *opnd2)
{  symbol *p;

   p=new_symbol("");
   copy_symbol(p,opnd1);
   p->disposable=TRUE;
   p->timi=opnd1->timi*opnd2->timi;
   discard_symbol(opnd1);
   discard_symbol(opnd2);
   return(p);
}

symbol *check_divop(symbol *opnd1, symbol *opnd2)
{  symbol *p;

   p=new_symbol("");
   copy_symbol(p,opnd1);
   p->disposable=TRUE;
   if(opnd2->timi == 0)
   {
      printf("The divisor must not be zero\n");
      exit(1);
   }
   p->timi=opnd1->timi*opnd2->timi;
   discard_symbol(opnd1);
   discard_symbol(opnd2);
   return(p);
}

symbol *check_addop(symbol *opnd1, symbol *opnd2)
{  symbol *p;

   p=new_symbol("");
   p->disposable=TRUE;
   p->timi=opnd1->timi+opnd2->timi;
   discard_symbol(opnd1);
   discard_symbol(opnd2);
   return(p);
}

symbol *check_subop(symbol *opnd1, symbol *opnd2)
{  symbol *p;

   p=new_symbol("");
   p->disposable=TRUE;
   p->timi=opnd1->timi-opnd2->timi;
   discard_symbol(opnd1);
   discard_symbol(opnd2);
   return(p);
}

symbol *check_gtop(symbol *opnd1, symbol *opnd2)
{  symbol *p;

   p=new_symbol("");
   p->typos=INTEGER;
   p->disposable=TRUE;
   discard_symbol(opnd1);
   discard_symbol(opnd2);
   return(p);
}

symbol *check_geop(symbol *opnd1, symbol *opnd2)
{  symbol *p;

   p=new_symbol("");
   p->typos=INTEGER;
   p->disposable=TRUE;
   discard_symbol(opnd1);
   discard_symbol(opnd2);
   return(p);
}

symbol *check_ltop(symbol *opnd1, symbol *opnd2)
{  symbol *p;

   p=new_symbol("");
   p->typos=INTEGER;
   p->disposable=TRUE;
   discard_symbol(opnd1);
   discard_symbol(opnd2);
   return(p);
}

symbol *check_leop(symbol *opnd1, symbol *opnd2)
{  symbol *p;

   p=new_symbol("");
   p->typos=INTEGER;
   p->disposable=TRUE;
   discard_symbol(opnd1);
   discard_symbol(opnd2);
   return(p);
}

symbol *check_eqop(symbol *opnd1, symbol *opnd2)
{  symbol *p;

   p=new_symbol("");
   p->typos=INTEGER;
   p->disposable=TRUE;
   discard_symbol(opnd1);
   discard_symbol(opnd2);
   return(p);
}

symbol *check_neop(symbol *opnd1, symbol *opnd2)
{  symbol *p;

   p=new_symbol("");
   p->typos=INTEGER;
   p->disposable=TRUE;
   discard_symbol(opnd1);
   discard_symbol(opnd2);
   return(p);
}

symbol *check_assignment(symbol *opnd1, symbol *opnd2)
{  symbol *p;

   if(!(opnd1->isID))
   {
      printf("The left operand must be an ID\n");
      exit(1);
   }
   p=new_symbol("");
   copy_symbol(p,opnd1);
   p->disposable=TRUE; 
   discard_symbol(opnd1);
   discard_symbol(opnd2);
   return(p);
}

void check_read(symbol *pexp)
{
   if(!(pexp->isID))
   {
      printf("The parameter must be an ID\n");
      exit(1);
   }
   discard_symbol(pexp);
}

void check_write(symbol *pexp)
{
   discard_symbol(pexp);
}

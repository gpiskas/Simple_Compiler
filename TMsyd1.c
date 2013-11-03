%{

#include <stdlib.h>
#include <stdio.h>

#define MESSAGE 0

/* ----------------------------------------------------------- */
/* --------- Declarations for Syntax-Semantic Analysis ------- */
/* ----------------------------------------------------------- */

#include "defs.h"

symbol *Cross_Link_Head[MAX_CROSS_LINKS];

typedef struct hash_tab {
   int numbsymbols;
   symbol *table[SYM_TABLE_SIZE];
} HASH_TAB;

HASH_TAB ht;

int TopOfStack=-1;
symbol *vs[30];

symbol *Symbol_free=NULL; /* -- Symbol-list of recycled symbols -- */
symbol *p,*p1,*p2,*p3,*p4,*p5,*p6;

AstNode *TreeRoot;

%}

%union
{
    int   yint;
    char  ystr[81];
    struct AstNode_tag *stnode;
}

/* -- Token and Node Declarations -- */

%token <yint> PROGRAM VAR INTEGER BEGINPROG ENDPROG READ WRITE IF THEN ELSE ENDIF WHILE DO ENDDO
%token <ystr> INT_LITERAL
%token <ystr> LPAREN RPAREN
%token <ystr> SCOL PRD COL ASGN
%token <ystr> LT LE EQ GE GT NE
%token <ystr> PLUS MINUS TIMES DIV
%token <ystr> ID

%type <stnode> program block
%type <stnode> decl_list declaration
%type <stnode> stat_seq statement
%type <stnode> expression 

/* -- Operator Precedence and Associativity -- */

%right ASGN
%left EQ NE
%left LT LE GE GT
%left PLUS MINUS
%left TIMES DIV
%right UNMINUS
%nonassoc PARENS

%%


program            : PROGRAM ID SCOL decl_list block PRD
                     {
#if MESSAGE
                        printf("/1\n");
#endif					
						p=new_symbol($2);
                        TreeRoot=MkNode(astProgram,p,$4,$5,NULL,NULL);
                     }
                   ;
                   
                   
decl_list            : /* EMPTY */
                     {
#if MESSAGE
                        printf("/2\n");
#endif
                        $$=MkNode(astEmptyDecl_list,NULL,NULL,NULL,NULL,NULL);
                     }
                   | decl_list declaration SCOL
                     { 
#if MESSAGE
                        printf("/3\n");
#endif
                        $$=MkNode(astDecl_list,NULL,$1,$2,NULL,NULL);
                     }
                   ;
                   
                   
declaration        : VAR ID COL INTEGER
                     { 
#if MESSAGE
                        printf("/4\n");
#endif
                        p2=new_symbol($2);
                        
                        p4=new_symbol("");
                        set_class_types(p4,$4);
                        p4->disposable=TRUE;
                        cpy_attributes(p2,p4);
                        
                        p2->isID=TRUE;
                        p2=reverse_cross_links(p2);
                        Link_Symbol_to_Cross_Link(p2);
                        add_symbols_to_table(p2);
                        discard_symbol(p4);  
                        $$=MkNode(astDecl,p2,NULL,NULL,NULL,NULL);                       
                     }
                   ;
                   
                   
block              : BEGINPROG stat_seq ENDPROG    	
                     { 
#if MESSAGE
                        printf("/5\n");
#endif
                        $$=MkNode(astBlock,NULL,$2,NULL,NULL,NULL);                                              
                     }
                   ;

                   
                   
stat_seq            : /* EMPTY */
                     {
#if MESSAGE
                        printf("/6\n");
#endif
                        $$=MkNode(astEmptyStat_seq,NULL,NULL,NULL,NULL,NULL);                   
                    }
                   | stat_seq statement SCOL
                     { 
#if MESSAGE
                        printf("/7\n");
#endif
                        $$=MkNode(astStat_seq,NULL,$1,$2,NULL,NULL);
                     }
                   ;
                   
                   
                   
statement          : ID ASGN expression 
                     { 
#if MESSAGE
                        printf("/8\n");
#endif                  
 
                        p1=findsymb($1);
                        if(!p1) {
                           printf(" Identifier not declared\n");
                           exit(1);
                        }
                        $$=MkNode(astStmt_Assign,NULL,MkNode(astExpr_Id,p1,NULL,NULL,NULL,NULL),$3,NULL,NULL);
                        p3=pop_vs();
                        p=check_assignment(p1,p3);
                        p1->timi=p3->timi;
                        push_vs(p); 
                     }
                   | WRITE expression
                     {  
#if MESSAGE
                        printf("/9\n");
#endif
                        $$=MkNode(astStmt_Write,NULL,$2,NULL,NULL,NULL);
                        p2=pop_vs();
                        check_write(p2);               
                     }
                   | READ ID
                     {  
#if MESSAGE
                        printf("/10\n");
#endif
                        p2=findsymb($2);
                        if(!p2) {
                           printf(" Identifier not declared\n");
                           exit(1);
                        }
                        $$=MkNode(astStmt_Read,p2,NULL,NULL,NULL,NULL);
						check_read(p2);
                     }
                   | IF expression THEN stat_seq ELSE stat_seq ENDIF
                     {  
#if MESSAGE
                        printf("/11\n");
#endif
                        $$=MkNode(astStmt_If,NULL,$2,$4,$6,NULL);
                     }
                   | WHILE expression DO stat_seq ENDDO
                     {  
#if MESSAGE
                        printf("/12\n");
#endif
                        $$=MkNode(astStmt_While,NULL,$2,$4,NULL,NULL);
                     }                     
                   ;
                   
                   
                   
expression         : expression PLUS expression
                     { 
#if MESSAGE
                        printf("/13\n");
#endif
                        p2=new_symbol($2);
                        p2->typos=BIN_PLUS;
                        $$=MkNode(astExpr_Binop,p2,$1,$3,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_addop(p1,p3);
                        push_vs(p);                  
                     }       
                   | expression MINUS expression
                     { 
#if MESSAGE
                        printf("/14\n");
#endif
                        p2=new_symbol($2);
                        p2->typos=BIN_MINUS;
                        $$=MkNode(astExpr_Binop,p2,$1,$3,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_subop(p1,p3);
                        push_vs(p);                  
                     }    
                   | expression TIMES expression
                     { 
#if MESSAGE
                        printf("/15\n");
#endif
                        p2=new_symbol($2);
                        p2->typos=BIN_TIMES;
                        $$=MkNode(astExpr_Binop,p2,$1,$3,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_multop(p1,p3);
                        push_vs(p);                  
                     }    
                   | expression DIV expression
                     { 
#if MESSAGE
                        printf("/16\n");
#endif
                        p2=new_symbol($2);
                        p2->typos=BIN_DIV;
                        $$=MkNode(astExpr_Binop,p2,$1,$3,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_divop(p1,p3);
                        push_vs(p);                  
                     }
                   | expression LT expression
                     { 
#if MESSAGE
                        printf("/17\n");
#endif
                        p2=new_symbol($2);
                        p2->typos=BIN_LT;
                        $$=MkNode(astExpr_Binop,p2,$1,$3,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_ltop(p1,p3);
                        push_vs(p);                  
                     }
                   | expression LE expression
                     { 
#if MESSAGE
                        printf("/18\n");
#endif
                        p2=new_symbol($2);
                        p2->typos=BIN_LE;
                        $$=MkNode(astExpr_Binop,p2,$1,$3,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_leop(p1,p3);
                        push_vs(p);                  
                     }
                   | expression EQ expression
                     { 
#if MESSAGE
                        printf("/19\n");
#endif
                        p2=new_symbol($2);
                        p2->typos=BIN_EQ;
                        $$=MkNode(astExpr_Binop,p2,$1,$3,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_eqop(p1,p3);
                        push_vs(p);                  
                     }
                   | expression GE expression
                     { 
#if MESSAGE
                        printf("/20\n");
#endif
                        p2=new_symbol($2);
                        p2->typos=BIN_GE;
                        $$=MkNode(astExpr_Binop,p2,$1,$3,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_geop(p1,p3);
                        push_vs(p);                  
                     }
                   | expression GT expression
                     { 
#if MESSAGE
                        printf("/21\n");
#endif
                        p2=new_symbol($2);
                        p2->typos=BIN_GT;
                        $$=MkNode(astExpr_Binop,p2,$1,$3,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_gtop(p1,p3);
                        push_vs(p);                  
                     }
                   | expression NE expression
                     { 
#if MESSAGE
                        printf("/22\n");
#endif
                        p2=new_symbol($2);
                        p2->typos=BIN_NE;
                        $$=MkNode(astExpr_Binop,p2,$1,$3,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_neop(p1,p3);
                        push_vs(p);                  
                     }             
                   | LPAREN expression RPAREN %prec PARENS
                     {  
#if MESSAGE
                        printf("/23\n");
#endif
                        $$=$2;
                     }                     
                   | MINUS expression %prec UNMINUS
                     {  
#if MESSAGE
                        printf("/24\n");
#endif
                        p1=new_symbol($1);
                        p1->typos=UN_MINUS;
                        $$=MkNode(astExpr_Unary,p1,$2,NULL,NULL,NULL);
                        p2=pop_vs();
                        p=check_unary_minus(p2);
                        push_vs(p);                        
                     }                     
                   | INT_LITERAL
                     {  
#if MESSAGE
                        printf("/25\n");
#endif
                        p1=new_symbol("");
                        p1->typos=INTEGER;
                        p1->disposable=FALSE;
                        p1->timi=atoi($1);
                        push_vs(p1);
                        $$=MkNode(astExpr_Int,p1,NULL,NULL,NULL,NULL);
                     }                     
                   | ID
                     {  
#if MESSAGE
                        printf("/26\n");
#endif
                        p1=findsymb($1);
                        if(!p1) {
                           printf("Identifier not declared\n");
                           exit(1);
                        }
                        $$=MkNode(astExpr_Id,p1,NULL,NULL,NULL,NULL);
                        p1=create_id(p1);
                        push_vs(p1);
                     }                                          
                   ;

%%

#include "tmsyd2.c"

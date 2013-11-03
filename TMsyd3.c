#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "y.tab.h"

extern AstNode *TreeRoot;

/* ----------------------------------------------------------- */
/* ----- Definitions & Declarations for Code Generation ------ */
/* ----------------------------------------------------------- */

/* Flag used in assign proccess*/
int fromAsgn=FALSE;
FILE *code;

/* ----------------------------------------------------------- */
/* ---------------------- FUNCTIONS -------------------------- */
/* ----------------------------------------------------------- */
 
void kena(int n)
{  int i;
   
   for(i=0; i<n; i++) printf(" ");
}

void traverse(AstNode *p,int n)
{  int i;

   n=n+3;
   if(p)
   {
      switch (p->NodeType)
      {
         case astProgram: 
            kena(n); printf("Program: %s\n",(p->SymbolNode)->name); 
         break;
         case astEmptyDecl_list: 
            kena(n); printf("EmptyDecl_list\n"); 
         break;
         case astDecl_list: 
            kena(n); printf("Decl_list\n"); 
         break;
         case astDecl: 
            kena(n); printf("Decl: %s\n",(p->SymbolNode)->name); 
         break;
         case astBlock: 
            kena(n); printf("Block\n"); 
         break;
         case astEmptyStat_seq: 
            kena(n); printf("EmptyStat_seq\n"); 
         break;
         case astStat_seq: 
            kena(n); printf("Stat_seq\n"); 
         break;   
         case astStmt_Assign: 
            kena(n); printf("Stmt_Assign\n"); 
         break;
         case astStmt_Write:
            kena(n); printf("Stmt_Write\n"); 
         break;
         case astStmt_Read: 
            kena(n); printf("Stmt_Read: %s\n",(p->SymbolNode)->name); 
         break;
         case astStmt_If: 
            kena(n); printf("Stmt_If\n"); 
         break;
         case astStmt_While:
            kena(n); printf("Stmt_While\n"); 
         break;
         case astExpr_Binop: 
            kena(n); printf("Expr_Binop: %s\n",(p->SymbolNode)->name); 
         break;
         case astExpr_Unary: 
            kena(n); printf("Expr_Unary: %s\n",(p->SymbolNode)->name); 
         break;
         case astExpr_Int: 
            kena(n); printf("Expr_Int: %d\n",(p->SymbolNode)->timi);
         break;
         case astExpr_Id: 
            kena(n); printf("Expr_Id: %s\n",(p->SymbolNode)->name);  
         break;
         default: 
            printf("Unknown: %d\n",p->NodeType);
      }
      for(i=0; i<4; i++) traverse(p->pAstNode[i],n);
   }
}


/* ---------------------------------------------------- */
/* ------------ TINY MACHINE EMITTING UTILS ----------- */
/* ---------------------------------------------------- */

/* TraceCode toggle*/
int TraceCode = TRUE;
/* tmpOffset for 'mp' manipulation*/
int tmpOffset = 0;

/* TM location number for current instruction emission */
static int emitLoc = 0 ;

/* Highest TM location emitted so far
   For use in conjunction with emitSkip,
   emitBackup, and emitRestore */
static int highEmitLoc = 0;

/* Procedure emitComment prints a comment line 
 * with comment c in the code file
 */
void emitComment( char * c )
{ if (TraceCode) fprintf(code,"* %s\n",c);}

/* Procedure emitRO emits a register-only
 * TM instruction
 * op = the opcode
 * r = target register
 * s = 1st source register
 * t = 2nd source register
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRO( char *op, int r, int s, int t, char *c)
{ fprintf(code,"%3d:  %5s  %d,%d,%d      ",emitLoc++,op,r,s,t);
  if (TraceCode) fprintf(code,"%s",c) ;
  fprintf(code,"\n") ;
  if (highEmitLoc < emitLoc) highEmitLoc = emitLoc ;
} /* emitRO */

/* Procedure emitRM emits a register-to-memory
 * TM instruction
 * op = the opcode
 * r = target register
 * d = the offset
 * s = the base register
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRM( char * op, int r, int d, int s, char *c)
{ fprintf(code,"%3d:  %5s  %d,%d(%d)     ",emitLoc++,op,r,d,s);
  if (TraceCode) fprintf(code,"%s",c) ;
  fprintf(code,"\n") ;
  if (highEmitLoc < emitLoc)  highEmitLoc = emitLoc ;
} /* emitRM */

/* Function emitSkip skips "howMany" code
 * locations for later backpatch. It also
 * returns the current code position
 */
int emitSkip( int howMany)
{  int i = emitLoc;
   emitLoc += howMany ;
   if (highEmitLoc < emitLoc)  highEmitLoc = emitLoc ;
   return i;
} /* emitSkip */

/* Procedure emitBackup backs up to 
 * loc = a previously skipped location
 */
void emitBackup( int loc)
{ if (loc > highEmitLoc) emitComment("BUG in emitBackup");
  emitLoc = loc ;
} /* emitBackup */

/* Procedure emitRestore restores the current 
 * code position to the highest previously
 * unemitted position
 */
void emitRestore(void)
{ emitLoc = highEmitLoc;}

/* Procedure emitRM_Abs converts an absolute reference 
 * to a pc-relative reference when emitting a
 * register-to-memory TM instruction
 * op = the opcode
 * r = target register
 * a = the absolute location in memory
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRM_Abs( char *op, int r, int a, char * c)
{ fprintf(code,"%3d:  %5s  %d,%d(%d) ",
               emitLoc,op,r,a-(emitLoc+1),pc);
  ++emitLoc ;
  if (TraceCode) fprintf(code,"\t%s",c) ;
  fprintf(code,"\n") ;
  if (highEmitLoc < emitLoc) highEmitLoc = emitLoc ;
} /* emitRM_Abs */


/* ------------------------------------------------------------------------ */
/* ProcessProgram */

void ProcessProgram(AstNode *p)
{
   CodeGeneration(p->pAstNode[0]);
   CodeGeneration(p->pAstNode[1]);
}

/* ------------------------------------------------------------------------ */
/* ProcessDeclList */

void ProcessDeclList(AstNode *p)
{
   CodeGeneration(p->pAstNode[0]);
   CodeGeneration(p->pAstNode[1]);
}

/* ------------------------------------------------------------------------ */
/* ProcessDecl */

void ProcessDecl(AstNode *p)
{  
   emitRM("ST",0,p->SymbolNode->memloc,gp,"Declaration");
}

/* ------------------------------------------------------------------------ */
/* ProcessBlock */

void ProcessBlock(AstNode *p)
{
   CodeGeneration(p->pAstNode[0]);
}

/* ------------------------------------------------------------------------ */
/* ProcessStmtSeq */

void ProcessStmtSeq(AstNode *p)
{
   CodeGeneration(p->pAstNode[0]);
   CodeGeneration(p->pAstNode[1]);
}

/* ------------------------------------------------------------------------ */
/* ProcessAssign */

void ProcessAssign(AstNode *p)
{
   fromAsgn=TRUE;
   CodeGeneration(p->pAstNode[0]);
   fromAsgn=FALSE;
   CodeGeneration(p->pAstNode[1]);

   emitRM("ST",ac,p->pAstNode[0]->SymbolNode->memloc,gp,"Assignment");
}

/* ------------------------------------------------------------------------ */
/* ProcessWrite */

void ProcessWrite(AstNode *p)
{
   CodeGeneration(p->pAstNode[0]);

   emitRO("OUT",ac,0,0,"Write");
}

/* ------------------------------------------------------------------------ */
/* ProcessRead */

void ProcessRead(AstNode *p)
{   
   emitRO("IN",ac,0,0,"Read INTEGER");
   emitRM("ST",ac,p->SymbolNode->memloc,gp,"Store INTEGER");
}

/* ------------------------------------------------------------------------ */
/* ProcessIf */

void ProcessIf(AstNode *p)
{     
    int thenLocation,elseLocation,loc;

	// Paragwgh kwdika gia thn synthikh tou if.
    CodeGeneration(p->pAstNode[0]);
    thenLocation = emitSkip(1);

	// Paragwgh kwdika gia to then.
    CodeGeneration(p->pAstNode[1]);
	elseLocation = emitSkip(1);
	
	// "Gemisma" ths theshs thenLocation me elegxo, wste na ektelestei h to THEN h to ELSE analoga me to IF.
    loc = emitSkip(0);
    emitBackup(thenLocation);
    emitRM_Abs("JEQ",ac,loc,"Execute ELSE");
    emitRestore();

    // Paragwgh kwdika gia to else.
    CodeGeneration(p->pAstNode[2]);
	
	//"Gemisma" ths theshs amesws meta to THEN, wste na phgainoume sto ENDIF xwris ektelesh tou ELSE.
    loc = emitSkip(0);
    emitBackup(elseLocation);
    emitRM_Abs("LDA",pc,loc,"Jump to ENDIF after THEN");
    emitRestore();
}

/* ------------------------------------------------------------------------ */
/* ProcessWhile */

void ProcessWhile(AstNode *p)
{
    int WhileLocation,CaseLocation,loc;
	
    // Paragwgh kwdika gia thn synthikh kai apothikefsh ths theshs akrivws prin apo afth.
    CaseLocation = emitSkip(0);
    CodeGeneration(p->pAstNode[0]);
	
    // Omoiws gia to swma tou while.
    WhileLocation = emitSkip(1);
    CodeGeneration(p->pAstNode[1]);
	// Ean h parakatw edolh den ektelestei (den phgame sto ENDDO), epanalamvanetai to while.
    emitRM_Abs("LDA",pc,CaseLocation,"Repeat WHILE");
	
    // "Gemisma" ths theshs whilelocation me thn parakatw edolh, pou kanei alma sto telos tou while
	// ean h synthikh einai FALSE.
    loc = emitSkip(0);
    emitBackup(WhileLocation);
    emitRM_Abs("JEQ",ac,loc,"Jump to ENDDO");
    emitRestore();
}

/* ------------------------------------------------------------------------ */
/* ProcessBinary */

void ProcessBinary(AstNode *p)
{
    CodeGeneration(p->pAstNode[0]);   
    emitRM("ST",ac,tmpOffset--,mp,"Save Temp");

    CodeGeneration(p->pAstNode[1]);
    emitRM("LD",ac1,++tmpOffset,mp,"Load Temp");

   switch(p->SymbolNode->typos)
   {
       case BIN_PLUS:
           emitRO("ADD",ac,ac1,ac,"Execute Binary +");         
           break;
       case BIN_MINUS:
           emitRO("SUB",ac,ac1,ac,"Execute Binary -");         
           break;
       case BIN_TIMES:
           emitRO("MUL",ac,ac1,ac,"Execute Binary *");         
           break;
       case BIN_DIV:
           emitRO("DIV",ac,ac1,ac,"Execute Binary /");         
           break;
       case BIN_LT:
           emitRO("SUB",ac,ac1,ac,"Execute Binary <");
           emitRM("JLT",ac,2,pc,"|");
           emitRM("LDC",ac,0,ac,"|");
           emitRM("LDA",pc,1,pc,"|");
           emitRM("LDC",ac,1,ac,"|");           
           break;
       case BIN_LE:
           emitRO("SUB",ac,ac1,ac,"Execute Binary <=");
           emitRM("JLE",ac,2,pc,"|");
           emitRM("LDC",ac,0,ac,"|");
           emitRM("LDA",pc,1,pc,"|");
           emitRM("LDC",ac,1,ac,"|");   
           break;
       case BIN_EQ:
           emitRO("SUB",ac,ac1,ac,"Execute Binary =");
           emitRM("JEQ",ac,2,pc,"|");
           emitRM("LDC",ac,0,ac,"|");
           emitRM("LDA",pc,1,pc,"|");
           emitRM("LDC",ac,1,ac,"|");           
           break;
       case BIN_GE:
           emitRO("SUB",ac,ac1,ac,"Execute Binary >=");
           emitRM("JGE",ac,2,pc,"|");
           emitRM("LDC",ac,0,ac,"|");
           emitRM("LDA",pc,1,pc,"|");
           emitRM("LDC",ac,1,ac,"|");             
           break;
       case BIN_GT:
           emitRO("SUB",ac,ac1,ac,"Execute Binary >");
           emitRM("JGT",ac,2,pc,"|");
           emitRM("LDC",ac,0,ac,"|");
           emitRM("LDA",pc,1,pc,"|");
           emitRM("LDC",ac,1,ac,"|");                
           break;
       case BIN_NE:
           emitRO("SUB",ac,ac1,ac,"Execute Binary !=");
           emitRM("JNE",ac,2,pc,"|");
           emitRM("LDC",ac,0,ac,"|");
           emitRM("LDA",pc,1,pc,"|");
           emitRM("LDC",ac,1,ac,"|");              
           break;
   }
}

/* ------------------------------------------------------------------------ */
/* ProcessMinus */

void ProcessMinus(AstNode *p)
{
   CodeGeneration(p->pAstNode[0]);
   emitRM("LDC",ac1,-1,0,"Apply Unary -");
   emitRO("MUL",ac,ac1,ac,"|");
}

/* ------------------------------------------------------------------------ */
/* ProcessInt */

void ProcessInt(AstNode *p) 
{
    emitRM("LDC",ac,p->SymbolNode->timi,0,"Load INT");
}

/* ------------------------------------------------------------------------ */
/* ProcessId */

void ProcessId(AstNode *p)
{    
   if(fromAsgn==FALSE)
   {
        emitRM("LD",ac,p->SymbolNode->memloc,gp,"Load ID");
   }
}

/* ------------------------------------------------------------------------ */
/* CodeGeneration */

void CodeGeneration(AstNode *p)
{  
   switch (p->NodeType)
   {
      case astProgram: 
         ProcessProgram(p);
      break;
      case astEmptyDecl_list:
      break;
      case astDecl_list:
         ProcessDeclList(p);
      break;
      case astDecl:
         ProcessDecl(p);
      break;
      case astBlock: 
         ProcessBlock(p);
      break;
      case astEmptyStat_seq:
      break;
      case astStat_seq: 
         ProcessStmtSeq(p);
      break;
      case astStmt_Assign: 
         ProcessAssign(p);
      break;
      case astStmt_Write:
         ProcessWrite(p);
      break;
      case astStmt_Read: 
         ProcessRead(p);
      break;
      case astStmt_If: 
         ProcessIf(p); 
      break;   
      case astStmt_While: 
         ProcessWhile(p); 
      break;    
      case astExpr_Binop: 
         ProcessBinary(p);
      break;
      case astExpr_Unary: 
         ProcessMinus(p);
      break; 
      case astExpr_Int: 
         ProcessInt(p);
      break;
      case astExpr_Id: 
         ProcessId(p);
      break;
      default:
         printf("Unknown: %d\n",p->NodeType);
   }
}

/* ------------------------------------------------------------------------ */
/* Main */

int main( int argc, const char* argv[] )
{   AstNode *p;
    int lathos;
	
   // Arxikopoihseis kai kataskevh tou AST.
   Init_Hash_Table();
   Init_Cross_Link_Head();
   lathos=yyparse();
   printf("\n\nAbstract Syntax Tree: \n\n");
   if(!lathos) 
   {
      p=TreeRoot;
      traverse(p,-3);
   }
   // Anoigma arxeiou kwdika me onomasia afth tou programmatos.
   code=fopen(strcat(p->SymbolNode->name,".tm"),"w");
   // Standar arxh programmatos:
   emitComment((char*)p->SymbolNode->name);
   emitComment("Standard prelude:");
   emitRM("LD",mp,0,ac,"load maxaddress from location 0");
   emitRM("ST",ac,0,ac,"clear location 0");
   emitComment("End of standard prelude.");
   
   // Paragwgh kwdika:
   CodeGeneration(p);
   
   // Standard telos programmatos:
   emitComment("End of execution.");
   emitRO("HALT",0,0,0,"");
   
   // Kleisimo tou arxeiou.
   fclose(code);
}

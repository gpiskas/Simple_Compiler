#define SYM_TABLE_SIZE 41
#define MAX_CROSS_LINKS 1
#define NAME_MAX  32
#define TRUE  1
#define FALSE 0 

/* ------------------------------------------------ */
/* ------------ CONSTANTS FOR AST NODES ----------- */
/* ------------------------------------------------ */

#define astProgram	        400
#define astEmptyDecl_list	401
#define astDecl_list        402
#define astDecl             403
#define astBlock	        404
#define astEmptyStat_seq    405
#define astStat_seq         406
#define astStmt_Assign	    407
#define astStmt_Write  	    408
#define astStmt_Read        409
#define astStmt_If	        410
#define astStmt_While	    411
#define astExpr_Binop	    412
#define astExpr_Unary   	414
#define astExpr_Int         415
#define astExpr_Id	        416


/* ----------------------------------------------------------- */
/* ------------ CONSTANTS FOR BIN AND UN OPERATORS ----------- */
/* ----------------------------------------------------------- */

#define BIN_LT             1000
#define BIN_LE             1001
#define BIN_EQ             1002
#define BIN_GE             1003 
#define BIN_GT             1004
#define BIN_NE             1005
#define BIN_PLUS           1006
#define BIN_MINUS          1007
#define BIN_TIMES          1008
#define BIN_DIV            1009
#define UN_MINUS           1010

/* ----------------------------------------------------------- */
/* ------------ TINY MACHINE EMITTING UTILS HEADER ----------- */
/* -------------------------(CODE.H)-------------------------- */

#define pc 7
#define mp 6
#define gp 5
#define ac 0
#define ac1 1

void emitComment( char * c );
void emitRO( char *op, int r, int s, int t, char *c);
void emitRM( char * op, int r, int d, int s, char *c);
int emitSkip( int howMany);
void emitBackup( int loc);
void emitRestore(void);
void emitRM_Abs( char *op, int r, int a, char * c);

/* ----------------------------------------------------------- */
/* ------------ THE STRUCTURE FOR THE SYMBOL NODES ----------- */
/* ----------------------------------------------------------- */

typedef struct symbol_tag {
   unsigned char name[NAME_MAX+1];  /* -- Variable name .----- */
   int typos;                       /* -- 'OPERATORS' or INTEGER. -- */
   int timi;                        /* -- Value assigned . --- */
   int isID;                        /* -- TRUE or FALSE .----- */
   int disposable;                  /* -- TRUE or FALSE .----- */
   int memloc;			            /* -- MEMORY LOCATION .--- */
   struct symbol_tag *Next_in_Cross_Link;
   struct symbol_tag *NextSymbol;
   struct symbol_tag *PrevSymbol;
} symbol;

/* ----------------------------------------------------------- */
/* ----- THE STRUCTURE FOR THE ABSTRACT SYNTAX TREE NODES ---- */
/* ----------------------------------------------------------- */

typedef struct AstNode_tag {
    int NodeType;
    struct symbol_tag *SymbolNode;
    struct AstNode_tag *pAstNode[4];
} AstNode;

/* ----------------------------------------------------------- */
/* ----------------------- PROTOTYPES ------------------------ */
/* ----------------------------------------------------------- */

void yyerror(char *);
void Init_Hash_Table(void);
void Init_Cross_Link_Head(void);
AstNode *MkNode(int,symbol *,AstNode *,AstNode *,AstNode *,AstNode *);
void push_vs(symbol *);
symbol *pop_vs(void);
symbol *new_symbol(char *);
int set_class_types(symbol *, int);
void cpy_attributes(symbol *, symbol *);
symbol *reverse_cross_links(symbol *);
void Link_Symbol_to_Cross_Link(symbol *);
int mkkey(char *);
void addsymb(symbol *);
symbol *findsymb(char *);
void add_symbols_to_table(symbol *);
void discard_symbol(symbol *);
symbol *create_id(symbol *);
void copy_value(symbol *, symbol *);
void copy_symbol(symbol *, symbol *);

symbol *check_unary_minus(symbol *);
symbol *check_multop(symbol *, symbol *);
symbol *check_divop(symbol *, symbol *);
symbol *check_addop(symbol *, symbol *);
symbol *check_subop(symbol *, symbol *);
symbol *check_gtop(symbol *, symbol *);
symbol *check_geop(symbol *, symbol *);
symbol *check_ltop(symbol *, symbol *);
symbol *check_leop(symbol *, symbol *);
symbol *check_eqop(symbol *, symbol *);
symbol *check_neop(symbol *, symbol *);
symbol *check_assignment(symbol *,symbol *);
void check_read(symbol *);
void check_write(symbol *);

void kena(int);
void traverse(AstNode *,int);

void ProcessProgram(AstNode *);
void ProcessDeclList(AstNode *);
void ProcessDecl(AstNode *);
void ProcessBlock(AstNode *);
void ProcessStatSeq(AstNode *);
void ProcessAssign(AstNode *);
void ProcessWrite(AstNode *);
void ProcessRead(AstNode *);
void ProcessIf(AstNode *);
void ProcessWhile(AstNode *);
void ProcessBinary(AstNode *);
void ProcessMinus(AstNode *);
void ProcessInt(AstNode *);
void ProcessId(AstNode *);
void CodeGeneration(AstNode *);

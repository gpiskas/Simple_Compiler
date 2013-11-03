#define PROGRAM 257
#define VAR 258
#define INTEGER 259
#define BEGINPROG 260
#define ENDPROG 261
#define READ 262
#define WRITE 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDDO 270
#define INT_LITERAL 271
#define LPAREN 272
#define RPAREN 273
#define SCOL 274
#define PRD 275
#define COL 276
#define ASGN 277
#define LT 278
#define LE 279
#define EQ 280
#define GE 281
#define GT 282
#define NE 283
#define PLUS 284
#define MINUS 285
#define TIMES 286
#define DIV 287
#define ID 288
#define UNMINUS 289
#define PARENS 290
typedef union
{
    int   yint;
    char  ystr[81];
    struct AstNode_tag *stnode;
} YYSTYPE;
extern YYSTYPE yylval;

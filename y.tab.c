#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "TMsyd1.c"

#include <stdlib.h>
#include <stdio.h>

#define MHNYMA 0

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

#line 33 "TMsyd1.c"
typedef union
{
    int   yint;
    char  ystr[81];
    struct AstNode_tag *stnode;
} YYSTYPE;
#line 43 "y.tab.c"
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
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    2,    2,    3,    1,    4,    4,    5,    5,    5,
    5,    5,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,
};
short yylen[] = {                                         2,
    6,    0,    3,    4,    3,    0,    3,    3,    2,    2,
    7,    5,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    1,    1,
};
short yydefred[] = {                                      0,
    0,    0,    0,    2,    0,    0,    6,    0,    0,    0,
    0,    1,    3,    0,    5,    0,    0,    0,    0,    0,
    0,    4,   10,   25,    0,    0,   26,    0,    0,    0,
    0,    7,    0,   24,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    6,    6,    0,   23,    0,    0,
    0,    0,    0,    0,    0,    0,   15,   16,    0,    0,
    6,   12,    0,   11,
};
short yydgoto[] = {                                       2,
    8,    5,    9,   11,   21,   28,
};
short yysindex[] = {                                   -251,
 -278,    0, -248,    0, -205, -245,    0, -227, -225, -222,
 -261,    0,    0, -202,    0, -230, -263, -263, -263, -215,
 -211,    0,    0,    0, -263, -263,    0,  -56, -206, -154,
 -263,    0,  -66,    0, -263, -263, -263, -263, -263, -263,
 -263, -263, -263, -263,    0,    0,  -56,    0,  -42,  -42,
  -46,  -42,  -42,  -46, -273, -273,    0,    0, -224, -247,
    0,    0, -217,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -191,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -190,    0, -213, -131,
  -74, -112,  -93,  -72, -183, -162,    0,    0,    0,    0,
    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    0,    0,  -41,    0,   -7,
};
#define YYTABLESIZE 245
short yytable[] = {                                      15,
   16,   17,   18,   59,   60,    1,   19,   24,   25,    3,
   29,   30,   43,   44,   16,   17,   18,   33,   34,   63,
   19,   26,   62,   47,   27,    4,   20,   49,   50,   51,
   52,   53,   54,   55,   56,   57,   58,   16,   17,   18,
   20,   61,   10,   19,   16,   17,   18,   12,   13,   64,
   19,   17,    6,   14,    7,   17,   22,   23,   45,   17,
   17,   31,   32,   20,   17,   17,   17,   17,   17,   17,
   20,   35,   36,   37,   38,   39,   40,   41,   42,   43,
   44,   13,    9,    8,    0,   13,    0,    0,    0,   13,
   13,    0,    0,    0,   13,   13,   13,   13,   13,   13,
   13,   13,   14,    0,    0,    0,   14,    0,    0,    0,
   14,   14,    0,    0,   46,   14,   14,   14,   14,   14,
   14,   14,   14,   35,   36,   37,   38,   39,   40,   41,
   42,   43,   44,   18,    0,    0,    0,   18,    0,    0,
    0,   18,   18,    0,    0,    0,   18,   18,   18,   18,
   18,   18,   20,    0,    0,    0,   20,    0,    0,    0,
   20,   20,    0,    0,    0,   20,   20,   20,   20,   20,
   20,   21,    0,    0,    0,   21,    0,    0,    0,   21,
   21,    0,    0,    0,   21,   21,   21,   21,   21,   21,
   19,    0,   22,    0,   19,    0,   22,    0,   19,   19,
   22,   22,    0,    0,    0,   19,   48,   22,   19,    0,
   22,   35,   36,   37,   38,   39,   40,   41,   42,   43,
   44,   35,   36,   37,   38,   39,   40,   41,   42,   43,
   44,   35,   36,    0,   38,   39,    0,   41,   42,   43,
   44,   41,   42,   43,   44,
};
short yycheck[] = {                                     261,
  262,  263,  264,   45,   46,  257,  268,  271,  272,  288,
   18,   19,  286,  287,  262,  263,  264,   25,   26,   61,
  268,  285,  270,   31,  288,  274,  288,   35,   36,   37,
   38,   39,   40,   41,   42,   43,   44,  262,  263,  264,
  288,  266,  288,  268,  262,  263,  264,  275,  274,  267,
  268,  265,  258,  276,  260,  269,  259,  288,  265,  273,
  274,  277,  274,  288,  278,  279,  280,  281,  282,  283,
  288,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  287,  265,  274,  274,   -1,  269,   -1,   -1,   -1,  273,
  274,   -1,   -1,   -1,  278,  279,  280,  281,  282,  283,
  284,  285,  265,   -1,   -1,   -1,  269,   -1,   -1,   -1,
  273,  274,   -1,   -1,  269,  278,  279,  280,  281,  282,
  283,  284,  285,  278,  279,  280,  281,  282,  283,  284,
  285,  286,  287,  265,   -1,   -1,   -1,  269,   -1,   -1,
   -1,  273,  274,   -1,   -1,   -1,  278,  279,  280,  281,
  282,  283,  265,   -1,   -1,   -1,  269,   -1,   -1,   -1,
  273,  274,   -1,   -1,   -1,  278,  279,  280,  281,  282,
  283,  265,   -1,   -1,   -1,  269,   -1,   -1,   -1,  273,
  274,   -1,   -1,   -1,  278,  279,  280,  281,  282,  283,
  265,   -1,  265,   -1,  269,   -1,  269,   -1,  273,  274,
  273,  274,   -1,   -1,   -1,  280,  273,  280,  283,   -1,
  283,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  287,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  287,  278,  279,   -1,  281,  282,   -1,  284,  285,  286,
  287,  284,  285,  286,  287,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"PROGRAM","VAR","INTEGER",
"BEGINPROG","ENDPROG","READ","WRITE","IF","THEN","ELSE","ENDIF","WHILE","DO",
"ENDDO","INT_LITERAL","LPAREN","RPAREN","SCOL","PRD","COL","ASGN","LT","LE",
"EQ","GE","GT","NE","PLUS","MINUS","TIMES","DIV","ID","UNMINUS","PARENS",
};
char *yyrule[] = {
"$accept : program",
"program : PROGRAM ID SCOL decl_list block PRD",
"decl_list :",
"decl_list : decl_list declaration SCOL",
"declaration : VAR ID COL INTEGER",
"block : BEGINPROG stat_seq ENDPROG",
"stat_seq :",
"stat_seq : stat_seq statement SCOL",
"statement : ID ASGN expression",
"statement : WRITE expression",
"statement : READ ID",
"statement : IF expression THEN stat_seq ELSE stat_seq ENDIF",
"statement : WHILE expression DO stat_seq ENDDO",
"expression : expression PLUS expression",
"expression : expression MINUS expression",
"expression : expression TIMES expression",
"expression : expression DIV expression",
"expression : expression LT expression",
"expression : expression LE expression",
"expression : expression EQ expression",
"expression : expression GE expression",
"expression : expression GT expression",
"expression : expression NE expression",
"expression : LPAREN expression RPAREN",
"expression : MINUS expression",
"expression : INT_LITERAL",
"expression : ID",
};
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 382 "TMsyd1.c"

#include "tmsyd2.c"
#line 253 "y.tab.c"
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d (%s)\n",
                    yystate, yytable[yyn],yyrule[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 69 "TMsyd1.c"
{
#if MHNYMA
                        printf("/1\n");
#endif					
						p=new_symbol(yyvsp[-4].ystr);
                        TreeRoot=MkNode(astProgram,p,yyvsp[-2].stnode,yyvsp[-1].stnode,NULL,NULL);
                     }
break;
case 2:
#line 80 "TMsyd1.c"
{
#if MHNYMA
                        printf("/2\n");
#endif
                        yyval.stnode=MkNode(astEmptyDecl_list,NULL,NULL,NULL,NULL,NULL);
                     }
break;
case 3:
#line 87 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/3\n");
#endif
                        yyval.stnode=MkNode(astDecl_list,NULL,yyvsp[-2].stnode,yyvsp[-1].stnode,NULL,NULL);
                     }
break;
case 4:
#line 97 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/4\n");
#endif
                        p2=new_symbol(yyvsp[-2].ystr);
                        
                        p4=new_symbol("");
                        set_class_types(p4,yyvsp[0].yint);
                        p4->disposable=TRUE;
                        cpy_attributes(p2,p4);
                        
                        p2->isID=TRUE;
                        p2=reverse_cross_links(p2);
                        Link_Symbol_to_Cross_Link(p2);
                        add_symbols_to_table(p2);
                        discard_symbol(p4);  
                        yyval.stnode=MkNode(astDecl,p2,NULL,NULL,NULL,NULL);                       
                     }
break;
case 5:
#line 119 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/5\n");
#endif
                        yyval.stnode=MkNode(astBlock,NULL,yyvsp[-1].stnode,NULL,NULL,NULL);                                              
                     }
break;
case 6:
#line 130 "TMsyd1.c"
{
#if MHNYMA
                        printf("/6\n");
#endif
                        yyval.stnode=MkNode(astEmptyStat_seq,NULL,NULL,NULL,NULL,NULL);                   
                    }
break;
case 7:
#line 137 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/7\n");
#endif
                        yyval.stnode=MkNode(astStat_seq,NULL,yyvsp[-2].stnode,yyvsp[-1].stnode,NULL,NULL);
                     }
break;
case 8:
#line 148 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/8\n");
#endif                  
 
                        p1=findsymb(yyvsp[-2].ystr);
                        if(!p1) {
                           printf(" Identifier not declared\n");
                           exit(1);
                        }
                        yyval.stnode=MkNode(astStmt_Assign,NULL,MkNode(astExpr_Id,p1,NULL,NULL,NULL,NULL),yyvsp[0].stnode,NULL,NULL);
                        p3=pop_vs();
                        p=check_assignment(p1,p3);
                        p1->timi=p3->timi;
                        push_vs(p); 
                     }
break;
case 9:
#line 165 "TMsyd1.c"
{  
#if MHNYMA
                        printf("/9\n");
#endif
                        yyval.stnode=MkNode(astStmt_Write,NULL,yyvsp[0].stnode,NULL,NULL,NULL);
                        p2=pop_vs();
                        check_write(p2);               
                     }
break;
case 10:
#line 174 "TMsyd1.c"
{  
#if MHNYMA
                        printf("/10\n");
#endif
                        p2=findsymb(yyvsp[0].ystr);
                        if(!p2) {
                           printf(" Identifier not declared\n");
                           exit(1);
                        }
                        yyval.stnode=MkNode(astStmt_Read,p2,NULL,NULL,NULL,NULL);
						check_read(p2);
                     }
break;
case 11:
#line 187 "TMsyd1.c"
{  
#if MHNYMA
                        printf("/11\n");
#endif
                        yyval.stnode=MkNode(astStmt_If,NULL,yyvsp[-5].stnode,yyvsp[-3].stnode,yyvsp[-1].stnode,NULL);
                     }
break;
case 12:
#line 194 "TMsyd1.c"
{  
#if MHNYMA
                        printf("/12\n");
#endif
                        yyval.stnode=MkNode(astStmt_While,NULL,yyvsp[-3].stnode,yyvsp[-1].stnode,NULL,NULL);
                     }
break;
case 13:
#line 205 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/13\n");
#endif
                        p2=new_symbol(yyvsp[-1].ystr);
                        p2->typos=BIN_PLUS;
                        yyval.stnode=MkNode(astExpr_Binop,p2,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_addop(p1,p3);
                        push_vs(p);                  
                     }
break;
case 14:
#line 218 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/14\n");
#endif
                        p2=new_symbol(yyvsp[-1].ystr);
                        p2->typos=BIN_MINUS;
                        yyval.stnode=MkNode(astExpr_Binop,p2,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_subop(p1,p3);
                        push_vs(p);                  
                     }
break;
case 15:
#line 231 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/15\n");
#endif
                        p2=new_symbol(yyvsp[-1].ystr);
                        p2->typos=BIN_TIMES;
                        yyval.stnode=MkNode(astExpr_Binop,p2,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_multop(p1,p3);
                        push_vs(p);                  
                     }
break;
case 16:
#line 244 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/16\n");
#endif
                        p2=new_symbol(yyvsp[-1].ystr);
                        p2->typos=BIN_DIV;
                        yyval.stnode=MkNode(astExpr_Binop,p2,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_divop(p1,p3);
                        push_vs(p);                  
                     }
break;
case 17:
#line 257 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/17\n");
#endif
                        p2=new_symbol(yyvsp[-1].ystr);
                        p2->typos=BIN_LT;
                        yyval.stnode=MkNode(astExpr_Binop,p2,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_ltop(p1,p3);
                        push_vs(p);                  
                     }
break;
case 18:
#line 270 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/18\n");
#endif
                        p2=new_symbol(yyvsp[-1].ystr);
                        p2->typos=BIN_LE;
                        yyval.stnode=MkNode(astExpr_Binop,p2,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_leop(p1,p3);
                        push_vs(p);                  
                     }
break;
case 19:
#line 283 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/19\n");
#endif
                        p2=new_symbol(yyvsp[-1].ystr);
                        p2->typos=BIN_EQ;
                        yyval.stnode=MkNode(astExpr_Binop,p2,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_eqop(p1,p3);
                        push_vs(p);                  
                     }
break;
case 20:
#line 296 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/20\n");
#endif
                        p2=new_symbol(yyvsp[-1].ystr);
                        p2->typos=BIN_GE;
                        yyval.stnode=MkNode(astExpr_Binop,p2,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_geop(p1,p3);
                        push_vs(p);                  
                     }
break;
case 21:
#line 309 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/21\n");
#endif
                        p2=new_symbol(yyvsp[-1].ystr);
                        p2->typos=BIN_GT;
                        yyval.stnode=MkNode(astExpr_Binop,p2,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_gtop(p1,p3);
                        push_vs(p);                  
                     }
break;
case 22:
#line 322 "TMsyd1.c"
{ 
#if MHNYMA
                        printf("/22\n");
#endif
                        p2=new_symbol(yyvsp[-1].ystr);
                        p2->typos=BIN_NE;
                        yyval.stnode=MkNode(astExpr_Binop,p2,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
                        p3=pop_vs();
                        p1=pop_vs();
                        p=check_neop(p1,p3);
                        push_vs(p);                  
                     }
break;
case 23:
#line 335 "TMsyd1.c"
{  
#if MHNYMA
                        printf("/23\n");
#endif
                        yyval.stnode=yyvsp[-1].stnode;
                     }
break;
case 24:
#line 342 "TMsyd1.c"
{  
#if MHNYMA
                        printf("/24\n");
#endif
                        p1=new_symbol(yyvsp[-1].ystr);
                        p1->typos=UN_MINUS;
                        yyval.stnode=MkNode(astExpr_Unary,p1,yyvsp[0].stnode,NULL,NULL,NULL);
                        p2=pop_vs();
                        p=check_unary_minus(p2);
                        push_vs(p);                        
                     }
break;
case 25:
#line 354 "TMsyd1.c"
{  
#if MHNYMA
                        printf("/25\n");
#endif
                        p1=new_symbol("");
                        p1->typos=INTEGER;
                        p1->disposable=FALSE;
                        p1->timi=atoi(yyvsp[0].ystr);
                        push_vs(p1);
                        yyval.stnode=MkNode(astExpr_Int,p1,NULL,NULL,NULL,NULL);
                     }
break;
case 26:
#line 366 "TMsyd1.c"
{  
#if MHNYMA
                        printf("/26\n");
#endif
                        p1=findsymb(yyvsp[0].ystr);
                        if(!p1) {
                           printf("Identifier not declared\n");
                           exit(1);
                        }
                        yyval.stnode=MkNode(astExpr_Id,p1,NULL,NULL,NULL,NULL);
                        p1=create_id(p1);
                        push_vs(p1);
                     }
break;
#line 735 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}

%{
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "y.tab.h"

#define N  14
%}

%%

[0-9]+                    {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(INT_LITERAL);
                            }
"+"                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(PLUS);
                            }
"-"                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(MINUS);
                            }                            
"*"                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(TIMES);
                            }
"/"                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(DIV);
                            }
"<"                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(LT);
                            }
"<="                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(LE);
                            }
"="                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(EQ);
                            }
">="                        {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(GE);
                            }
">"                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(GT);
                            }
"!="                        {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(NE);
                            }
";"                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(SCOL);
                            }
"."                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(PRD);
                            }                            
":"                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(COL);
                            }
":="                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(ASGN);
                            }                          
"("                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(LPAREN);
                            } 
")"                         {
                               printf("%s",yytext);
                               strcpy(yylval.ystr,yytext);
                               return(RPAREN);
                            }                             
                        
[a-zA-Z]([a-zA-Z]|[0-9])*   {  int i;

                               printf("%s",yytext);
                               i=id_or_keyword(yytext);
                               if(i==ID) 
                                  strcpy(yylval.ystr,yytext);
                               else 
                                  yylval.yint=i;
                               return(i);
                            }
[ \f\n\r\t]+                {
                                printf("%s",yytext); 
                            }
.                           {
                               printf("UNKNOWN TOKEN: %s\n",yytext);
                            }    

%%

static char *kid[N]={"PROGRAM","VAR","INTEGER","BEGIN","END","READ","WRITE","IF","THEN","ELSE","ENDIF","WHILE","DO","ENDDO"};

static int kval[N]={PROGRAM,VAR,INTEGER,BEGINPROG,ENDPROG,READ,WRITE,IF,THEN,ELSE,ENDIF,WHILE,DO,ENDDO};

int id_or_keyword(char *s)
{  int i,k;

   for(i=0; (i < N) && (strcmp(s,kid[i]) != 0); i++);
   if(i < N)
      return kval[i];
   else
      return ID;
}

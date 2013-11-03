CC = cl
CCFLAGS = /nologo /link Tools\Link\zyywrap.obj
LEX = Tools\flex
YACC = Tools\byacc

start: all

st.l.o:
        $(YACC) -dv TMsyd1.c
        $(LEX) TMlex.c

all: st.l.o
        $(CC) -o Bin\_ST.exe lex.yy.c y.tab.c TMsyd3.c $(CCFLAGS)      
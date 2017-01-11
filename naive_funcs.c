#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "naive.h"
FILE* in = NULL;
static unsigned int symhash(char *sym)
{
	unsigned int hash = 0;
	unsigned int c;
	while(c = *sym++) hash = hash * 9 ^ c;
	
	return hash;
}
enum type gettype(enum type t1, enum type t2)
{
    switch(t1){
    case BOOL:
        switch(t2){
        case BOOL:
            return BOOL:
        case INT:
            return INT;
        case DOUBLE:
            return DOUBLE;
        }
    case INT:
            switch(t2){
            case INT:
            case BOOL:
                return INT;
            case DOUBLE:
                return DOUBLE;
            }
    case DOUBLE:
        return DOUBLE;
    }
}


struct ast *newfunc(int funcype, struct ast* l);
struct ast *newcall(struct symbol* s, struct ast* l);
struct ast *newref(struct symbol *s);
struct ast *newasgn(struct symbol *s, struct ast *v);
struct ast *newnum(double d);
void yyerror(char*s,...)
{
	va_list ap;
	va_start(ap,s);
	fprintf(stderr,"%d: error: ", yylineno);
	vfprintf(stderr, s,ap);
	fprintf(stderr, "\n");
}
int main(int argc, char** argv)
{
	if(argc > 1){
		in = fopne(argv[1],"rw");
		if(in == NULL){
			printf("cannot open file %s\n",argv[1]);
		}
	}else{
		in = stdin;
	}
}

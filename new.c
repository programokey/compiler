#include  "naive.h"
#include  <stdlib>
struct ast* newast(int nodetype,struct ast* l, struct ast* r)
{
	struct ast* a = malloc(sizeof(struct ast));

	if(!a){
		yyerror("run out of memory!");
		exit(0);
	}
	a->nodetype = nodetype;
    a->type = get_type(l->type, r->type);
	a->l = l;
	a->r = r;
	return a;
}
struct ast* newcmp(int cmptype, struct ast* l, struct ast* r)
{
	struct ast* a = malloc(sizeof(struct ast));
	if(!a){
		yyerror("run out of memory!");
		exit(0);
	}
	a->nodetype = '0' + cmptype;
    a->type = BOOL;
	a->l = l;
	a->r = r;
	return a;
}
struct ast *newint(int i)
{
	struct intval* a = malloc(sizeof(struct intval));
	if(!a)
		yyerror("run out of memory!");
		exit(0);
	}
	a->nodetype = INTEGER;
	a->type = INTEGER;
	a->integer = i;
	return a;
}
struct ast *newbool(enum bool b)
{
	struct boolval* a = malloc(sizeof(struct boolval));
	if(!a){
		yyerror("run out of memory!");
		exit(0);
	}
	a->nodetype = BOOL;
	a->type = BOOL;
	a->truth = b;
	return a;
}
struct ast *newdouble(double d)
{
	struct doubleval* a = malloc(sizeof(struct doubleval));
	if(!a){
		yyerror("run out of memory!");
		exit(0);
	}
	a->nodetype = DOUBLE;
	a->type = DOUBLE;
	a->real = d;
	return a;
}

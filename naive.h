#ifndef NAIVA_H
#define NAIVA_H
enum type{
	BOOL,
	INT,
	DOUBLE,
	VOID
};
enum bool{
	true = 1,
	false = 0
};
struct ast{
	int nodetype;
    	enum type type;
	struct ast* l,*r;
};
struct exp_list{
	int nodetype;
	struct list* list;
}
struct fncall{
	int nodetype;
	struct ast *l;
	char* functype;
};
struct flow{
	int nodetype;
	struct ast *cond;
	struct ast *tl;
	struct ast *el;
};
struct intval{
	int nodetype;
	int integer;
};
struct doubleval{
	int nodetype;
	double real;
};
struct boolval{
	int nodetype;
	double truth;
};
struct var{
	int nodetype;
	char* label;
	enum type type;	
	int dis;//displacement
};
struct func{
	char* name;
	enum type type;
	struct list* para_list;
	struct list* ins_list;
};
struct vardef{
	char* name;
	struct* ast v;
	struct vardef* next;
};
extern struct vardef *vardef_head, *vardef_tail;

struct put_vardef(char* name, struct ast* v);
struct varref{
	int nodetype;
	struct var *v;
};
struct varasgn{
	int nodetype;
	struct var *var;
	struct ast *v;
};
#define NHASH 9997
struct var global_vars[NHASH];
struct symbol *lookup(char*);
void globalvardef(char* s, enum type type, struct ast* v);
void localvardef(char* s, enum type type, struct ast* v);
struct ast *newast(int nodetype, struct ast* l, struct ast* r);
struct ast *newcmp(int cmptype, struct ast* l, struct ast* r);
struct ast *newfunc(int funcype, struct ast* l);
struct ast *newcall(struct symbol* s, struct ast* l);
struct ast *newvarref(char *s);

struct ast *newasgn(char *s, struct ast *v);
struct ast *newasgnarithmetric(int nodetype, char* s, struct ast *v);
struct ast *newinc(char *s);
struct ast *newdec(char *s);

struct ast *newint(int i);
struct ast *newbool(enum bool b);
struct ast *newdouble(double d);
struct ast *newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *tr);

enum type gettype(enum type t1, enum type t2);

double eval(struct ast* );

void treefree(struct ast* );

extern int yylineno;
void yyerror(char* s,...);
#endif

%option noyywrap nodefault yylineno
%{
	#include "naive.h"
	#include "naive.tab.h"
	#include <stdio.h>
%}
EXP ([Ee][+-]?[0-9]+)

%%
"display" { return DIS; }
"++"	{ return INC; }
"--"	{ return DEC; }
"+=" 	{ return ADD_ASGN; }
"-=" 	{ return SUB_ASGN; }
"*=" 	{ return MUL_ASGN; }
"/=" 	{ return DIV_ASGN; }
"&&"	{ return AND; }
"||"	{ return OR; }
"+" |
"-" |
"*" |
"/" |
"=" |
"|" |
"," |
";" |
"(" |
")" |
"{" |
"}" { return yytext[0]; }

">"  { yylval.cmptype = 1; return CMP; }
"<"  { yylval.cmptype = 2; return CMP; }
"!=" { yylval.cmptype = 3; return CMP; }
"==" { yylval.cmptype = 4; return CMP; }
">=" { yylval.cmptype = 5; return CMP; }
"<=" { yylval.cmptype = 6; return CMP; }

"int" 		{ yylval.type = INT; return TYPE; }
"double" 	{ yylval.type = DOUBLE; return TYPE; }
"bool" 		{ yylval.type = BOOL; return TYPE; }
"true" 		{ return TRUE; }
"false" 	{ return FALSE; }
"if"		{ return IF; }
"else"		{ return ELSE; }
"while"		{ return WHILE; }
"for"		{ return FOR; }
"return"	{ return RETURN; }
[a-zA-Z_][a-zA-Z0-9_]*	{ yylval.s = strdup(yytext); return NAME; }
[0-9]+			{ yylval.integer = atoi(yytext); return INTEGER; }
[0-9]+{EXP} |
[0-9]*"."[0-9]+{EXP}?	{ yylval.d = atof(yytext); return REAL;}

"//".*
[ \t]
\\[ \t]*\n
\n
. {yyerror("Mystery character %c\n",yytext[0]);}
%%

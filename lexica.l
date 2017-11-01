%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
BOOLEAN "true"|"false"
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"boolean"	{return TK_TIPO_BOOLEAN;}

"if"		{ return TK_IF; }

"else"		{ return TK_ELSE; }

"int"		{return TK_TIPO_INT;}

"float"		{return TK_TIPO_FLOAT;}

"char"		{return TK_TIPO_CHAR;}

[(){}[\];,]	{return *yytext;}

[+\-*/]		{return *yytext;}

"="			{return *yytext;}

">"			{return TK_MAIOR;}

">=" 		{return TK_MAIOR_IGUAL;}

"<"			{return TK_MENOR;}

"<=" 		{return TK_MENOR_IGUAL;}

"=="		{return TK_IGUAL;}

"!=" 		{return TK_DIFERENTE;}

"||"		{return TK_OU;}

"&&"		{return TK_E;}

"!"			{return TK_NEGACAO;}

"(int)"		{ yylval.tipo = "int"; return TK_CAST;}

"(float)"	{ yylval.tipo = "float"; return TK_CAST;}

{NUM}		{ yylval.label = yytext; yylval.tipo = "int" ;return TK_INT;}

{BOOLEAN}	{ yylval.label = yytext; yylval.tipo = "boolean" ;return TK_BOOLEAN;}

{REAL}		{ yylval.label = yytext; yylval.tipo = "float"; return TK_FLOAT;}

{CHAR}		{ yylval.label = yytext; yylval.tipo = "char"; return TK_CHAR;}

{ID}		{ yylval.label = yytext; return TK_ID;}

.			{ *yytext;}

%%

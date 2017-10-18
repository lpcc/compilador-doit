%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
INT {DIGITO}+

BOOLEAN "TRUE"|"FALSE"
REAL {INT}+("."{INT}+)?
CHAR \'({LETRA}|{INT})\'
ID {LETRA}({LETRA}|{INT})*

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"boolean"	{return TK_TIPO_BOOLEAN;}

"int"		{return TK_TIPO_INT;}

"float"		{return TK_TIPO_REAL;}

"char"		{return TK_TIPO_CHAR;}

[(){}[\];,]	{return *yytext;}

[+\-*/]		{return *yytext;}

">"			{return TK_MAIOR;}

">=" 		{return TK_MAIOR_IGUAL;}

"<"			{return TK_MENOR;}

"<=" 		{return TK_MENOR_IGUAL;}

"=="		{return TK_IGUAL;}

"!=" 		{return TK_DIFERENTE;}

"||"		{return TK_OU;}

"&&"		{return TK_E;}

"!"			{return TK_NEGACAO;}

{INT}		{ yylval.label = yytext; yylval.tipo = "int" ;return TK_INT;}

{BOOLEAN}	{ yylval.label = yytext; yylval.tipo = "boolean" ;return TK_BOOLEAN;}

{REAL}		{ yylval.label = yytext; yylval.tipo = "float"; return TK_REAL;}

{CHAR}		{ yylval.label = yytext; yylval.tipo = "char"; return TK_CHAR;}

{ID}		{ yylval.label = yytext; yylval.tipo = "id"; return TK_ID;}

.			{ *yytext; }

%%

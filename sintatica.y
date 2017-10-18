%{
#include <iostream>
#include <string>
#include <sstream>

#define YYSTYPE atributos

using namespace std;
int static numero = -1;

struct atributos
{
	string label;
	string traducao;
	string tipo;
};

int yylex(void);
void yyerror(string);

string geradora();
%}


%token TK_MAIN
%token TK_TIPO_BOOLEAN TK_TIPO_REAL TK_TIPO_CHAR TK_TIPO_INT
%token TK_BOOLEAN TK_REAL TK_CHAR TK_INT TK_ID
%token TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_IGUAL
%token TK_DIFERENTE TK_OU TK_E TK_NEGACAO
%token TK_FIM

%start START

%left '+' '-' '*' '/'
%left TK_E TK_OU TK_NEGACAO
%left TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_IGUAL TK_DIFERENTE

%%

START		: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "\n/*Compilador DOIT*/\n\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			| 
			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			;

E 			: E '+' E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label +";\n\n";
			}
			|E '-' E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label +";\n\n";
			}
			|E '*' E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label +";\n\n";
			}
			|E '/' E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label +";\n\n";
			}
			|'(' E ')'
			{
				$$.label = "(" + $3.label +")";
				$$.traducao = $2.traducao;
			}
			| T
			| LOGICA
			| RELACIONAL
			;

T    		: TK_INT
			{
				$$.label = geradora();
				$$.traducao = "\t" + $$.tipo + " " + $$.label + " = " + $1.label + ";\n\n";
			}
			| TK_BOOLEAN
			{
				$$.label = geradora();
				$$.traducao = "\t" + $$.tipo + " " + $$.label + " = " + $1.label + ";\n\n";
			}
			| TK_CHAR
			{
				$$.label = geradora();
				$$.traducao = "\t" + $$.tipo + " " + $$.label + " = " + $1.label + ";\n\n";
			}
			| TK_ID
			{
				$$.label = geradora();
				$$.traducao = "\t" + $$.tipo + " " + $$.label + " = " + $1.label + ";\n\n";
			}
			| TK_REAL
			{
				$$.label = geradora();
				$$.traducao = "\t" + $$.tipo + " " + $$.label + " = " + $1.label + ";\n\n";
			}
			;

LOGICA 		: E TK_E E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + "\t" +
				$$.label + " = " + $1.label + " and " + $3.label + " ;\n\n";
			}
			| E TK_OU E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + "\t" +
				$$.label + " = " + $1.label + " or " + $3.label + " ;\n\n";
			}
			| TK_NEGACAO E
			{
				$$.label = geradora();
				$$.traducao = $2.traducao + "\t" +
				$$.label + " = " + " not " + $2.label + ";\n\n" ;
			}
			;

RELACIONAL 	: E TK_MAIOR E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + '\t' +
				$$.label + " = " + $1.label + " > "  + $3.label + ";\n\n";	
			}
			| E TK_MAIOR_IGUAL E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + '\t' +
				$$.label + " = " + $1.label + " >= " + $3.label + ";\n\n";	
			}
			| E TK_MENOR E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + '\t' +
				$$.label + " = " + $1.label + " < " + $3.label + ";\n\n";	
			}
			| E TK_MENOR_IGUAL E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + '\t' +
				$$.label + " = " + $1.label + " < " + $3.label + ";\n\n";	
			}
			| E TK_IGUAL E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + '\t' +
				$$.label + " = " + $1.label + " == " + $3.label + ";\n\n";	
			}
			| E TK_DIFERENTE E
			{
				$$.label = geradora();
				$$.traducao = $1.traducao + $3.traducao + '\t' +
				$$.label + " = " + $1.label + " != " + $3.label + ";\n\n";	
			}

			;

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

string geradora(){
	
	char buffer[50];
	string temp;

	numero++;

	sprintf(buffer,"temp%d",numero);

	temp = buffer;

	return temp;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				

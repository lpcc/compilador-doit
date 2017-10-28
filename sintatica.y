%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <list>

#define YYSTYPE atributos

using namespace std;
int static numero = -1;
int qtd = 0;

struct atributos
{
	string label;
	string tipo;
	string traducao;
	string valor;
};

typedef struct atributos Atributos;
typedef map<string, Atributos> STRINGMAP;
list<STRINGMAP*> pilhaDeMapas;
string variaveis;

int yylex(void);
void yyerror(string);
string converter();
string geradora();

STRINGMAP* buscarTkId(string label);
bool pertenceAoAtualEscopo(string label);
string declaracoes();


%}
%token TK_MAIN
%token TK_TIPO_BOOLEAN TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_INT
%token TK_BOOLEAN TK_FLOAT TK_CHAR TK_INT TK_ID
%token TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_IGUAL
%token TK_DIFERENTE TK_OU TK_E TK_NEGACAO
%token TK_FIM TK_ERROR

%start START

%left '+' '-' '*' '/'
%left TK_E TK_OU TK_NEGACAO
%left TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_IGUAL TK_DIFERENTE

%%

START			: ESCOPO_GLOBAL MAIN
				{ 
					cout << "*Compilador DOIT* \n#include<string.h>\n#include<iostream>\n#include<stdio.h>\nusing namespace std;\n" << endl;
					cout << variaveis << endl;
					declaracoes();			
					cout << $2.traducao << endl;
				}
				;

MAIN			: TK_TIPO_INT TK_MAIN  '(' ')' BLOCO {$$.traducao = "int main(void)\n{\n" + $5.traducao + "\treturn 0;\n}\n\n"; };

ESCOPO_GLOBAL	:
				{
					STRINGMAP* mapa = new STRINGMAP();
					pilhaDeMapas.push_front(mapa);
				} 
				;

INICIO_ESCOPO	: '{'
				{	STRINGMAP* mapa = new STRINGMAP();
					pilhaDeMapas.push_front(mapa);
					cout << "\nAbertura: "<< pilhaDeMapas.size() << endl;
					$$.traducao = "";
				}
				;

FIM_ESCOPO		: '}'
				{	
					declaracoes();				
					pilhaDeMapas.pop_front();
					cout << "\nFechamento: " << pilhaDeMapas.size()<< "\n " << endl;
					$$.traducao = "";

				}
				;

BLOCO			: INICIO_ESCOPO COMANDOS FIM_ESCOPO
				{
					$$.traducao = $2.traducao;
				}
				;

COMANDOS		: COMANDO COMANDOS 
				{ 
					$$.traducao = $1.traducao +  "\n" + $2.traducao;
				}
				|
				{
					$$.traducao = "";
				}
				;				


COMANDO 		: E ';'
				| DECLARACAO ';'
				| ATRIBUICAO ';'
				;

TIPO			: TK_TIPO_INT
				{
					$$.label = "int";
					$$.tipo = "int";
				}
				|	TK_TIPO_FLOAT
				{
					$$.label = "float";
					$$.tipo = "float";
				}
				|	TK_TIPO_BOOLEAN
				{
					$$.label = "boolean";
					$$.tipo = "boolean";
				}
				|	TK_TIPO_CHAR
				{
					$$.label = "char";
					$$.tipo = "char";
				}
				; 

DECLARACAO		: TIPO TK_ID
				{
					STRINGMAP* mapa = pilhaDeMapas.front();
					(*mapa)[$2.label].label = converter();
					(*mapa)[$2.label].tipo = $1.tipo;
					
					$$.traducao = $2.traducao + $$.tipo + " " + $2.label;
					$$.traducao = "";
						
				}
				| DECLARACAO ',' TK_ID
				{
					STRINGMAP* mapa = pilhaDeMapas.front();
					if(!pertenceAoAtualEscopo($3.label))
					{
						(*mapa)[$3.label].label = converter();
						(*mapa)[$3.label].tipo = $1.tipo;
					}
					$$.tipo = (*mapa)[$3.label].tipo;
					$3.label = (*mapa)[$3.label].label;
					$$.traducao = "";

					
				}		
				| DECLARACAO ',' TK_ID '=' E 
				{	
					STRINGMAP* mapa = pilhaDeMapas.front();
					(*mapa)[$3.label].label = converter();
					(*mapa)[$3.label].tipo = $1.tipo;
					$$.traducao = $1.traducao + "\n" + $5.traducao + "\t" + $3.label + " = (" + $$.tipo + ") " + $5.label + ";\n";
				}
				
				| TIPO TK_ID '=' E 
				{	STRINGMAP* mapa = pilhaDeMapas.front();
					(*mapa)[$2.label].label = converter();
					(*mapa)[$2.label].tipo = $1.tipo;
					$$.traducao = $4.traducao + "\t" + $2.label + " = (" + $$.tipo + ") " + $4.label + ";\n";
				}
				;

ATRIBUICAO		: TK_ID '=' E
				{	STRINGMAP* mapa = pilhaDeMapas.front();
					(*mapa)[$1.label].label = converter();
					(*mapa)[$1.label].tipo = $$.tipo;
					$$.traducao = $3.traducao + '\t' + $1.label + " = ("+ $$.tipo + ") " + $3.label + ";\n" ;

				}
				;

E				: E '+' E
				{
					$$.label = converter();		
					$$.traducao = $1.traducao + $3.traducao;
					if($1.tipo == "int" && $3.tipo == "int")
					{
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " +$3.label +";\n";
						$$.tipo = "int";
					}
					if($1.tipo == "float" && $3.tipo == "int")
					{
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " +"(float)"+ $3.label +";\n";
						$$.tipo = "float";
					}
					if($1.tipo == "int" && $3.tipo == "float")
					{
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + "(float)"+ $1.label + " + " + $3.label +";\n";
						$$.tipo = "float";
					}
					if($1.tipo == "float" && $3.tipo == "float")
					{
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label +";\n";
						$$.tipo = "float";
					}				
				}
				|E '-' E
				{
					STRINGMAP* mapa = pilhaDeMapas.front();
					//STRINGMAP* mapa = buscarTkId($1.label);
					$$.label = converter();
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label +";\n";
				}
				|E '*' E
				{
					STRINGMAP* mapa = pilhaDeMapas.front();
					//STRINGMAP* mapa = buscarTkId($1.label);
					$$.label = converter();
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label +";\n";		
				}
				|E '/' E
				{
					STRINGMAP* mapa = pilhaDeMapas.front();
					//STRINGMAP* mapa = buscarTkId($1.label);
					$$.label = converter();
					(*mapa)[$$.label].label = $1.label;
					(*mapa)[$$.label].tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label +";\n";
				}
				|'(' E ')'
				{	$$.label = converter();
					$$.label = "(" + $2.label + ")";
					$$.traducao = $2.traducao;	
				}
				| TK_INT 
				{
					STRINGMAP* mapa = pilhaDeMapas.front();
					$$.label = converter();

					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].traducao = $1.traducao;
					(*mapa)[$$.label].tipo = $$.tipo;

					$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label+ ";\n";
				}
				| TK_BOOLEAN
				{
					STRINGMAP* mapa = pilhaDeMapas.front();
					$$.label = converter();
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].traducao = $1.traducao;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label+ ";\n";
				}
				| TK_CHAR
				{
					STRINGMAP* mapa = pilhaDeMapas.front();
					$$.label = converter();
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].traducao = $1.traducao;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label+ ";\n";
				}
				| TK_ID
				{	
					STRINGMAP* mapa = pilhaDeMapas.front();		
					//STRINGMAP* mapa = buscarTkId($1.label);
					$$.label=(*mapa)[$1.label].label;
					$$.tipo=(*mapa)[$1.label].tipo;
					$$.traducao = "";
				}
				| TK_FLOAT
				{
					STRINGMAP* mapa = pilhaDeMapas.front();
					$$.label = converter();
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].traducao = $1.traducao;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label+ ";\n";
				}
				|E TK_E E
				{
					$$.label = converter();
					//$$.label = geradora() ;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " && " + $3.label + ";\n";
				}
				| E TK_OU E
				{
					$$.label = converter();
					//$$.label = geradora() ;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " || " + $3.label + ";\n";
				}
				| TK_NEGACAO E
				{
					$$.label = converter();
					//$$.label = geradora() ;
					$$.traducao = $2.traducao + "\t" +$$.label + " = " + "!" + $2.label + ";\n";
				}
				| E TK_MAIOR E
				{
					STRINGMAP* mapa = pilhaDeMapas.front();
					//STRINGMAP* mapa = buscarTkId($1.label);
					$$.label = converter();
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.label = (*mapa)[$$.label].label; 
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " > " + $3.label +";\n";	
				}
				| E TK_MAIOR_IGUAL E
				{
					$$.label = converter(); 
					//$$.label = geradora() ;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";	
				}
				| E TK_MENOR E
				{
					$$.label = converter();
					//$$.label = geradora() ;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " < " + $3.label + ";\n";	
				}
				| E TK_MENOR_IGUAL E
				{
					$$.label = converter();
					//$$.label = geradora() ;
					$$.traducao = $1.traducao + $3.traducao + "\t" +$$.label + " = " + $1.label + " <= " + $3.label + ";\n";	
				}
				| E TK_IGUAL E
				{
					$$.label = converter();
					//$$.label = geradora() ;				
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " == " + $3.label + ";\n";	
				}
				| E TK_DIFERENTE E
				{
					$$.label = converter();
					//$$.label = geradora() ;
					$$.traducao = $1.traducao + $3.traducao + "\t" +$$.label + " = " + $1.label + " != " + $3.label + ";\n";	
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


string converter(){
	   
	stringstream ss;
	ss << qtd;
	string str = ss.str();
	qtd++;
	return "TEMP" +str; 
}

string geradora(){
	
	char buffer[50];
	string temp;
	numero++;
	sprintf(buffer,"temp %d",numero);
	temp = buffer;
	return temp;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}		

STRINGMAP* buscarTkId(string label)
{
	list<STRINGMAP*>::iterator i;
	for(i = pilhaDeMapas.begin(); i != pilhaDeMapas.end(); i++)
	{
		STRINGMAP* mapa = *i;
		if(mapa->find(label) != mapa->end()) {return mapa;}
	}
	return NULL;
}		

bool pertenceAoAtualEscopo(string label)
{
	STRINGMAP* mapa = pilhaDeMapas.front();
	if(mapa->find(label) == mapa->end()) return false;
	else return true;	
}

string declaracoes()
{
	STRINGMAP mapa = *pilhaDeMapas.front();
	STRINGMAP::iterator i;
	stringstream s;
	for(i = mapa.begin(); i != mapa.end(); i++){
		s << i->second.tipo << " " << i->second.label << ";\n";
	}
	variaveis += s.str() + "\n";
	return variaveis;
}

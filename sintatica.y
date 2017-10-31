%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <list>

#define YYSTYPE atributos

using namespace std;
int q = 0;

struct atributos
{
	string label;
	string tipo;
	string traducao;
};

typedef struct atributos Atributos;
typedef map<string, Atributos> MAPA;
list<MAPA*> pilhaDeMapas;
string variaveis;

int yylex(void);
void yyerror(string);
string gerarVarTemp();
//string geradora();
MAPA* buscaMapa (string label);
string declaracoes();
bool verificarDeclaracao(string label);
string gerarBloco();
string decidirValorBool(string a);

%}
%token TK_MAIN
%token TK_TIPO_BOOLEAN TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_INT
%token TK_BOOLEAN TK_FLOAT TK_CHAR TK_INT TK_ID
%token TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_IGUAL
%token TK_DIFERENTE TK_OU TK_E TK_NEGACAO
%token TK_FIM TK_ERROR
%token TK_IF TK_ELSE

%start START

%left '+' '-' '*' '/'
%left TK_E TK_OU TK_NEGACAO
%left TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_IGUAL TK_DIFERENTE

%%

START			: ESCOPO_GLOBAL MAIN
				{ 
					cout << "\n*Compilador DOIT* \n#include<string.h>\n#include<iostream>\n#include<stdio.h>\nusing namespace std;\n" << endl;
					cout << variaveis << endl;
					declaracoes();			
					cout << $2.traducao << endl;
				}
				;

MAIN			: TK_TIPO_INT TK_MAIN  '(' ')' BLOCO 
				{
					$$.traducao = "int main(void)\n{\n" + $5.traducao + "\treturn 0;\n}\n\n"; 
				}
				;

ESCOPO_GLOBAL	:
				{
					MAPA* mapa = new MAPA();
					pilhaDeMapas.push_front(mapa);
				} 
				;

INICIO_ESCOPO	: '{'
				{	
					MAPA* mapa = new MAPA();
					pilhaDeMapas.push_front(mapa);
					$$.traducao = "";
				}
				;

FIM_ESCOPO		: '}'
				{	
					declaracoes();				
					pilhaDeMapas.pop_front();
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
				| IF
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
					MAPA* mapa = pilhaDeMapas.front();
					if(!verificarDeclaracao($2.label))
					{
						(*mapa)[$2.label].label = gerarVarTemp();
						(*mapa)[$2.label].tipo = $1.tipo;
					}
					$$.tipo = (*mapa)[$2.label].tipo;
					$2.label = (*mapa)[$2.label].label;
					$$.traducao = $2.traducao + $$.tipo + " " + $2.label;
					$$.traducao = "";
				}
				| DECLARACAO ',' TK_ID
				{
					MAPA* mapa = pilhaDeMapas.front();
					if(!verificarDeclaracao($3.label))
					{
						(*mapa)[$3.label].label = gerarVarTemp();
						(*mapa)[$3.label].tipo = $1.tipo;
					}

					$$.tipo = (*mapa)[$3.label].tipo;
					$3.label = (*mapa)[$3.label].label;
					$$.traducao = "";
					
				}		
				| DECLARACAO ',' TK_ID '=' E 
				{	
					MAPA* mapa = pilhaDeMapas.front();
					if(!verificarDeclaracao($3.label))
					{
						(*mapa)[$3.label].label = gerarVarTemp();
						(*mapa)[$3.label].tipo = $1.tipo;
					}
					$$.tipo = (*mapa)[$3.label].tipo;
					$3.label = (*mapa)[$3.label].label;
					if ($$.tipo!=$5.tipo){ $$.traducao = $1.traducao + "\n" + $5.traducao + "\t" + $3.label + " = (" + $$.tipo + ") " + $5.label + ";\n";}	
					else $$.traducao = $1.traducao + "\n" + $5.traducao + "\t" + $3.label + " = " + $5.label + ";\n";
				}
				| TIPO TK_ID '=' E 
				{	
					MAPA* mapa = pilhaDeMapas.front();
					if(!verificarDeclaracao($2.label))
					{
						(*mapa)[$2.label].label = gerarVarTemp();
						(*mapa)[$2.label].tipo = $1.tipo;
					}
					$$.tipo = (*mapa)[$2.label].tipo;
					$2.label = (*mapa)[$2.label].label;
					if ($$.tipo!=$4.tipo){$$.traducao = $4.traducao + "\t" + $2.label + " = (" + $$.tipo + ") " + $4.label + ";\n";}
					else $$.traducao = $4.traducao + "\t" + $2.label + " = " + $4.label + ";\n";	
				}
				;

ATRIBUICAO		: TK_ID '=' E
				{	
					MAPA* mapa = buscaMapa($1.label);
					MAPA* mapa2 = buscaMapa($3.label);
					if(mapa == NULL)
						yyerror("ERRO: Variável não foi declarada!");
					if(mapa2==NULL)
						yyerror("ERRO: Variável não foi declarada!");
					$$.label = (*mapa)[$1.label].label;
					$$.tipo = (*mapa)[$1.label].tipo;
					$1.label = $$.label;
					$$.traducao = $3.traducao + '\t' + $1.label + " = " + $3.label + ";\n" ;

				}
				;

E				: E '+' E
				{	
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
									
					if ($1.tipo != $3.tipo)
					{
						$$.tipo = "float";
						if ($1.tipo == "int" && $3.tipo == "float"){ $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = ("+ $$.tipo +")" + $1.label + " + " + $3.label +";\n";
						} else if ($1.tipo == "float" && $3.tipo == "int"){ $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + "  + " (" + $$.tipo +")" +  $3.label +";\n";}
					}else
					{	
						(*mapa)[$$.label].label = $$.label;
						(*mapa)[$$.label].tipo = $$.tipo;
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label +";\n";					
					}
				}
				|E '-' E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
									
					if ($1.tipo != $3.tipo){
						$$.tipo = "float";
						if ($1.tipo == "int" && $3.tipo == "float"){ $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = ("+$$.tipo+")" + $1.label + " - " + $3.label +";\n";
						} else if ($1.tipo == "float" && $3.tipo == "int"){ $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - "  + "("+ $$.tipo +")" + $3.label +";\n";}
					}else
					{	
						(*mapa)[$$.label].label = $$.label;
						(*mapa)[$$.label].tipo = $$.tipo;
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label +";\n";					
					}
				}
				|E '*' E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
									
					if ($1.tipo != $3.tipo){
						$$.tipo = "float";
						if ($1.tipo == "int" && $3.tipo == "float"){ $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = ("+$$.tipo+")" + $1.label + " * " + $3.label +";\n";
						} else if ($1.tipo == "float" && $3.tipo == "int"){ $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * "  + "("+ $$.tipo +")" + $3.label +";\n";}
					}else
					{	
						(*mapa)[$$.label].label = $$.label;
						(*mapa)[$$.label].tipo = $$.tipo;
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label +";\n";					
					}
				}
				|E '/' E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
									
					if ($1.tipo != $3.tipo)
					{
						$$.tipo = "float";
						if ($1.tipo == "int" && $3.tipo == "float"){ $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = ("+$$.tipo+")" + $1.label + " / " + $3.label +";\n";
						} else if ($1.tipo == "float" && $3.tipo == "int"){ $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / "  + "("+ $$.tipo +")" + $3.label +";\n";}
					}else
					{	
						(*mapa)[$$.label].label = $$.label;
						(*mapa)[$$.label].tipo = $$.tipo;
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label +";\n";					
					}
				}
				|'(' E ')'
				{	
					$$.label = gerarVarTemp();
					$$.label = "(" + $2.label + ")";
					$$.traducao = $2.traducao;	
				}
				| TK_INT 
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();

					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].traducao = $1.traducao;
					(*mapa)[$$.label].tipo = $$.tipo;

					$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label+ ";\n";
				}
				| TK_BOOLEAN
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].traducao = $1.traducao;
					(*mapa)[$$.label].tipo = $$.tipo;

					$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label+ ";\n";
				}
				| TK_CHAR
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].traducao = $1.traducao;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label+ ";\n";
				}
				| TK_ID
				{	
					MAPA* mapa = buscaMapa($1.label);
					mapa = pilhaDeMapas.front();		
					$$.label = (*mapa)[$1.label].label;
					$$.tipo = (*mapa)[$1.label].tipo;
					$$.traducao = "";
				}
				| TK_FLOAT
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].traducao = $1.traducao;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label+ ";\n";
				}
				|E TK_E E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = "boolean";
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					//$$.label = (*mapa)[$$.label].label; 
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " && " + $3.label+ ";\n"; 
				}
				| E TK_OU E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = "boolean";
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " || " + $3.label + ";\n";
				}
				| TK_NEGACAO E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = "boolean";
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao =  $1.traducao + $2.traducao + "\t" + $$.label + " = " + " !  " + $2.label +";\n";	

				}
				| E TK_MAIOR E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = "boolean";
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + decidirValorBool($3.traducao) + "\t" + $$.label + " = " + $1.label + " > " + $3.label +";\n";
	
				}
				| E TK_MAIOR_IGUAL E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = "boolean";
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + decidirValorBool($3.traducao) + "\t" + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";	
				}
				| E TK_MENOR E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = "boolean";
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + decidirValorBool($3.traducao) + "\t" + $$.label + " = " + $1.label + " < " + $3.label + ";\n";	
				}
				| E TK_MENOR_IGUAL E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = "boolean";
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + decidirValorBool($3.traducao) + "\t" +$$.label + " = " + $1.label + " <= " + $3.label + ";\n";	
				}
				| E TK_IGUAL E
				{	
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = "boolean";
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;				
					$$.traducao = $1.traducao + decidirValorBool($3.traducao) + "\t" + $$.label + " = " + $1.label + " == " + $3.label + ";\n";	
				}
				| E TK_DIFERENTE E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = "boolean";
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + decidirValorBool($3.traducao) + "\t" +$$.label + " = " + $1.label + " != " + $3.label + ";\n";	
				}
				;

IF 				: TK_IF '(' E ')' BLOCO
				{	
					string fimbloco = gerarBloco();
					$$.traducao = $3.traducao + "\n\tif("+ $3.label +") goto " + fimbloco + ";\n\n" + $5.traducao + "\t" + fimbloco + ":\n";		
				}
				| TK_IF '(' E ')' BLOCO TK_ELSE BLOCO
				{
					string blocoIf = gerarBloco();
					string blocoElse = gerarBloco();
					string fimbloco= gerarBloco();
					$$.traducao = $3.traducao + "\n\tif (" + $3.label +" == true) goto " + blocoElse + ";\n" + $5.traducao  + "\telse goto " + fimbloco  + ";\n\n\t" + blocoElse + ":\n"+$7.traducao + "\t" + fimbloco + ":\n";
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

string decidirValorBool(string a)
{
	if (a == "verdadeiro") return "true";
	else if (a == "falso") return "false";
} 

string gerarVarTemp()
{	   
	stringstream ss;
	ss << q;
	string str = ss.str();
	q++;
	return "TEMP" +str; 
}

/*string geradora(){
	
	char buffer[50];
	string temp;
	numero++;
	sprintf(buffer,"temp %d",numero);
	temp = buffer;
	return temp;
}*/

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}		

MAPA* buscaMapa(string label)
{
	list<MAPA*>::iterator i;
	for(i = pilhaDeMapas.begin(); i != pilhaDeMapas.end(); i++)
	{
		MAPA* mapa = *i;
		if(mapa->find(label) != mapa->end()) {return mapa;}
	}
	return NULL;
}

string gerarBloco()
{	
	static int bloco = 0;
	stringstream label;
	label << "bloco " << bloco++;
	return label.str();
}
	
bool verificarDeclaracao(string label)
{
	MAPA* mapa = pilhaDeMapas.front();
	if(mapa->find(label) == mapa->end())
	return false;
	else return true;	
}

string declaracoes()
{
	MAPA mapa = *pilhaDeMapas.front();
	MAPA::iterator i;
	stringstream s;
	for(i = mapa.begin(); i != mapa.end(); i++){
		s << i->second.tipo << " " << i->second.label << ";\n";
	}
	variaveis += s.str() + "\n";
	return variaveis;
}

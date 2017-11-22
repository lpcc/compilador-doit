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
	string valor;
};

typedef struct atributos Atributos;
typedef map<string, Atributos> MAPA;
list<MAPA*> pilhaDeMapas;
string variaveis;

int yylex(void);
string gerarVarTemp();
//string geradora();
MAPA* buscaMapa (string label);
string declaracoes();
bool verificarDeclaracao(string label);
string gerarBloco();
string gerarfimbloco();
string valorBoolean(string a);
void yyerror(string MSG);
int tipoToIndice(string tipo);
string intToString(int label);
string op[6][6];
bool loopFor = false;
bool loopForWhile = false;
list<string> labelOpen;
list<string> labelClose;
list<string> labelAdd;

%}
%token TK_MAIN
%token TK_TIPO_BOOLEAN TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_INT TK_TIPO_STRING
%token TK_BOOLEAN TK_FLOAT TK_CHAR TK_INT TK_ID TK_STRING
%token TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_IGUAL
%token TK_DIFERENTE TK_OU TK_E TK_NEGACAO
%token TK_FIM TK_ERROR
%token TK_IF TK_ELSE TK_WHILE TK_SWITCH TK_CASE TK_DO TK_FOR
%token TK_COUT
%token TK_INC TK_INC_ABREV 

%nonassoc TK_IF
%nonassoc TK_ELSE

%start START

%left '+' '-' '*' '/'
%left TK_E TK_OU TK_NEGACAO
%left TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_IGUAL TK_DIFERENTE
%left TK_CAST


%%

START			: ESCOPO_GLOBAL MAIN
				{ 
					cout << "\n*Compilador DOIT* \n#include<string.h>\n#include<iostream>\n#include<stdio.h>\n" << endl;
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
				| WHILE
				| FOR
				| DO
				| COUT ';'
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
				
				|	TK_TIPO_STRING
				{
					$$.label = "string";
					$$.tipo = "string";
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
				/*{	
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
				}*/
				{
					MAPA* mapa = pilhaDeMapas.front();
					if(!verificarDeclaracao($3.label))
					{
						(*mapa)[$3.label].label = gerarVarTemp();
						(*mapa)[$3.label].tipo = $1.tipo;
					}
					$$.tipo = (*mapa)[$3.label].tipo;
					$3.label = (*mapa)[$3.label].label;

					if ($$.tipo == $5.tipo)
					{
						$$.traducao = $1.traducao + "\n" + $5.traducao + "\t" + $3.label + " = " + $5.label + ";\n";
					}
					else
					{
						if ($$.tipo!=$5.tipo)
						{	
							yyerror("ERRO: ATRIBUICAO ILEGAL!");
						}
						else
						{
							$$.traducao = $1.traducao + "\n" + $5.traducao + "\t" + $3.label + " = " + $5.label + ";\n";
						}
					}
				}

				| TIPO TK_ID '=' E 
				/*{	
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
				;*/
				{
					MAPA* mapa = pilhaDeMapas.front();
					if(!verificarDeclaracao($2.label))
					{	
						(*mapa)[$2.label].label = gerarVarTemp();
						(*mapa)[$2.label].tipo = $1.tipo;
					}

					$$.tipo = (*mapa)[$2.label].tipo;
    				$2.label = (*mapa)[$2.label].label;

					if ($$.tipo!=$4.tipo) 
					{
						yyerror("ERRO: ATRIBUICAO ILEGAL!");
					}
					else
					{
						$$.traducao = $4.traducao + "\t" + $2.label + " = " + $4.label + ";\n";						
					}
				}
				;

ATRIBUICAO		: TK_ID '=' E
				/*{	
					MAPA* mapa = buscaMapa($1.label);
					if(mapa == NULL)
						yyerror("ERRO: Variável não foi declarada!");

					$$.tipo = (*mapa)[$1.label].tipo;

					//Caso Diferente faz a cast, senão faz atribuição normal
					if($$.tipo != $3.tipo){
						$$.label = (*mapa)[$1.label].label;
						$$.tipo = (*mapa)[$1.label].tipo;
						$1.label = $$.label;
						$$.traducao = $3.traducao + '\t' + $1.label + " = (" + $$.tipo + ")"+ $3.label + ";\n" ;
					}else{
						$$.label = (*mapa)[$1.label].label;
						$$.tipo = (*mapa)[$1.label].tipo;
						$1.label = $$.label;
						$$.traducao = $3.traducao + '\t' + $1.label + " = " + $3.label + ";\n" ;
					}
					

				}*/
				{
					MAPA* mapa = buscaMapa($1.label);
					if(mapa == NULL)
						yyerror("ERRO: VARIAVEL NAO DECLARADA.");

					$$.tipo = (*mapa)[$1.label].tipo;	

					if ($$.tipo!=$3.tipo) 
					{
						yyerror("ERRO: ATRIBUICAO ILEGAL!");
					}
					else
					{
						$$.label = (*mapa)[$1.label].label;
						$$.tipo = (*mapa)[$1.label].tipo;
						$1.label = $$.label;
						$$.traducao = $3.traducao + '\t' + $1.label + " = " + $3.label + ";\n" ;
					}
					
				}
				| TK_ID TK_INC
				{	
					MAPA* mapa = buscaMapa($1.label);
					$1.label = (*mapa)[$1.label].label;
				
					if(mapa == NULL)
					{
						yyerror("ERRO: VARIAVEL NAO DECLARADA!");
					}
					
					else
					{
						$$.traducao = "\t" + $1.label + " = " + $1.label + " " + $2.traducao[0] + "1;\n";
					}
				}


E				: E '+' E
				{	
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t";

					if ($1.tipo != $3.tipo)
					{	
						if ($$.tipo == "ilegal") 
						{
								yyerror("ERRO: SOMA ILEGAL!");
						}
						else if ($$.tipo == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+$$.tipo+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = $$.tipo;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " + " + $3.label +";\n";
						}
						else if ($$.tipo == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+$$.tipo+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = $$.tipo;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " + " + $3.label +";\n";
						}
					}
					else
					{ 	
						$$.traducao += $$.label + " = " + $1.label + " + " + $3.label + ";\n";
					}
				}
				|E '-' E
				{	
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t";

					if ($1.tipo != $3.tipo)
					{	
						if ($$.tipo == "ilegal") 
						{
								yyerror("ERRO: SUBTRACAO ILEGAL!");
						}
						else if ($$.tipo == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+$$.tipo+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = $$.tipo;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " - " + $3.label +";\n";
						}
						else if ($$.tipo == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+$$.tipo+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = $$.tipo;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " - " + $3.label +";\n";
						}
					}
					else
					{ 	
						$$.traducao += $$.label + " = " + $1.label + " - " + $3.label + ";\n";
					}
				}
				|E '*' E
				{	
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t";

					if ($1.tipo != $3.tipo)
					{	
						if ($$.tipo == "ilegal") 
						{
								yyerror("ERRO: MULTIPLICACAO ILEGAL!");
						}
						else if ($$.tipo == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+$$.tipo+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = $$.tipo;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " * " + $3.label +";\n";
						}
						else if ($$.tipo == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+$$.tipo+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = $$.tipo;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " * " + $3.label +";\n";
						}
					}
					else
					{ 	
						$$.traducao += $$.label + " = " + $1.label + " * " + $3.label + ";\n";
					}
				}
				|E '/' E
				{	
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t";

					if ($1.tipo != $3.tipo)
					{	
						if ($$.tipo == "ilegal") 
						{
								yyerror("ERRO: DIVISAO ILEGAL!");
						}
						else if ($$.tipo == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+$$.tipo+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = $$.tipo;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " / " + $3.label +";\n";
						}
						else if ($$.tipo == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+$$.tipo+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = $$.tipo;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " / " + $3.label +";\n";
						}
					}
					else
					{ 	
						$$.traducao += $$.label + " = " + $1.label + " / " + $3.label + ";\n";
					}
				}
				|'(' E ')'
				{	
					$$.label = gerarVarTemp();
					$$.traducao = $2.traducao;	
					$$.tipo = $2.tipo;
					$$.traducao = $2.traducao + "\t" + $$.label + " = " + $2.label + ";\n";
		
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
				| TK_STRING
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].valor = $1.traducao;
					(*mapa)[$$.label].tipo = $$.tipo;					
				}
				|E TK_E E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
 					$$.label = $$.label;
 					$$.tipo = "boolean";
 					//pra verificar se eh ilegal
    				string tipo1 = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
    				$$.traducao = $1.traducao + $3.traducao + "\t";
    				(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;

    				if ($1.tipo != $3.tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: AND ILEGAL!");
						}
						else if (tipo1 == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " && " + $3.label +";\n";
						}
						else if (tipo1 == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " && " + $3.label +";\n";
						}
					}
					else
					{
						$$.traducao += $$.label + " = " + $1.label + " && " + $3.label + ";\n";
					}
				}
				| E TK_OU E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
 					$$.label = $$.label;
 					$$.tipo = "boolean";
    				string tipo1 = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
    				$$.traducao = $1.traducao + $3.traducao + "\t";
    				(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;

    				if ($1.tipo != $3.tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: OR ILEGAL!");
						}
						else if (tipo1 == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " || " + $3.label +";\n";
						}
						else if (tipo1 == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " || " + $3.label +";\n";
						}
					}
					else
					{
						$$.traducao += $$.label + " = " + $1.label + " || " + $3.label + ";\n";
					}
    					
				}
				| TK_NEGACAO E
				{
				
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = "boolean";
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao =  $1.traducao + $2.traducao + "\t" + $$.label + " = " + "!" + $2.label +";\n";	

				}
				| E TK_MAIOR E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
 					$$.label = $$.label;
 					$$.tipo = "boolean";
    				string tipo1 = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
    				$$.traducao = $1.traducao + $3.traducao + "\t";
    				(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;

    				if ($1.tipo != $3.tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: MAIOR QUE ILEGAL!");
						}
						else if (tipo1 == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " > " + $3.label +";\n";
						}
						else if (tipo1 == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " > " + $3.label +";\n";
						}
					}
					else
					{
						$$.traducao += $$.label + " = " + $1.label + " > " + $3.label + ";\n";
					}
    			}
				| E TK_MAIOR_IGUAL E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
 					$$.label = $$.label;
 					$$.tipo = "boolean";
    				string tipo1 = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
    				$$.traducao = $1.traducao + $3.traducao + "\t";
    				(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;

    				if ($1.tipo != $3.tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: MAIOR/IGUAL ILEGAL!");
						}
						else if (tipo1 == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " >= " + $3.label +";\n";
						}
						else if (tipo1 == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " >= " + $3.label +";\n";
						}
					}
					else
					{
						$$.traducao += $$.label + " = " + $1.label + " >= " + $3.label + ";\n";
					}
    			}
				| E TK_MENOR E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
 					$$.label = $$.label;
 					$$.tipo = "boolean";
    				string tipo1 = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
    				$$.traducao = $1.traducao + $3.traducao + "\t";
    				(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;

    				if ($1.tipo != $3.tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: MENOR QUE ILEGAL!");
						}
						else if (tipo1 == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " < " + $3.label +";\n";
						}
						else if (tipo1 == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " < " + $3.label +";\n";
						}
					}
					else
					{
						$$.traducao += $$.label + " = " + $1.label + " < " + $3.label + ";\n";
					}
    			}
				| E TK_MENOR_IGUAL E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
 					$$.label = $$.label;
 					$$.tipo = "boolean";
    				string tipo1 = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
    				$$.traducao = $1.traducao + $3.traducao + "\t";
    				(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;

    				if ($1.tipo != $3.tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: MENOR/IGUAL ILEGAL!");
						}
						else if (tipo1 == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " <= " + $3.label +";\n";
						}
						else if (tipo1 == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " <= " + $3.label +";\n";
						}
					}
					else
					{
						$$.traducao += $$.label + " = " + $1.label + " <= " + $3.label + ";\n";
					}
    			}
				| E TK_IGUAL E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
 					$$.label = $$.label;
 					$$.tipo = "boolean";
    				string tipo1 = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
    				$$.traducao = $1.traducao + $3.traducao + "\t";
    				(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;

    				if ($1.tipo != $3.tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: IGUAL QUE ILEGAL!");
						}
						else if (tipo1 == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " == " + $3.label +";\n";
						}
						else if (tipo1 == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " == " + $3.label +";\n";
						}
					}
					else
					{
						$$.traducao += $$.label + " = " + $1.label + " == " + $3.label + ";\n";
					}
    			}
				| E TK_DIFERENTE E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
 					$$.label = $$.label;
 					$$.tipo = "boolean";
    				string tipo1 = op[tipoToIndice($1.tipo)][tipoToIndice($3.tipo)];
    				$$.traducao = $1.traducao + $3.traducao + "\t";
    				(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;

    				if ($1.tipo != $3.tipo)
					{
						if (tipo1 == "ilegal") 
						{
							yyerror("ERRO: DIFERENTE ILEGAL!");
						}
						else if (tipo1 == $1.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $3.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " != " + $3.label +";\n";
						}
						else if (tipo1 == $3.tipo)
						{
							string tempCast = gerarVarTemp();
							string traducaoCast = "\t" + tempCast + " = " + "("+tipo1+")" + $1.label + ";\n";
			            	$1.label = tempCast;
			            	(*mapa)[$1.label].label = $1.label;
							(*mapa)[$1.label].tipo = tipo1;
          					$$.traducao = $1.traducao + $3.traducao + traducaoCast + "\t" + $$.label + " = " + $1.label + " != " + $3.label +";\n";
						}
					}
					else
					{
						$$.traducao += $$.label + " = " + $1.label + " != " + $3.label + ";\n";
					}
    			}
				| TK_CAST E
				{
					MAPA* mapa = pilhaDeMapas.front();
					$$.label = gerarVarTemp();
					$$.tipo = $1.tipo;
					(*mapa)[$$.label].label = $$.label;
					(*mapa)[$$.label].tipo = $$.tipo;
					$$.traducao = $2.traducao + '\t' + $$.label + " = (" + $1.tipo + ") " + $2.label + ";\n";
				}
				;


IF 				: TK_IF '(' E ')' BLOCO
				{	string blocoEnd = gerarBloco();
					$$.traducao = $3.traducao + "\n\tif (" + $3.label +") goto " + blocoEnd + ";\n\n" + $5.traducao + "\t" + blocoEnd + ":\n";		
				}
				
				| TK_IF '(' E ')' BLOCO TK_ELSE BLOCO
				{
					string blocoIf = gerarBloco();
					string blocoElse = gerarBloco();
					string blocoEnd = gerarBloco();

					$$.traducao = $3.traducao + "\n\tif (" + $3.label +") goto " + blocoElse + ";\n\n" + $5.traducao  + "\tgoto " + blocoEnd  + ";\n\n\t" + blocoElse + ":\n"+$7.traducao + "\t" + blocoEnd + ":\n";
				}
				;

			
COUT			: TK_COUT '(' E ')' { $$.traducao = "\tcout << " + $3.label + " << endl;";}
				;

WHILE			: TK_WHILE '(' E ')' BLOCO
				{
					if(loopFor)
					{
						loopFor = false;
						loopForWhile = true;
					}

					string blocoIf = gerarBloco();
					labelOpen.push_front(blocoIf);

					string blocoElse = gerarBloco();
					labelClose.push_front(blocoElse);

					$$.traducao = $3.traducao + "\n\t" + labelOpen.front() + ":" + "\n\tif (" + $3.label +") goto " + labelClose.front() + ";\n\n" + $5.traducao + "\tgoto " +labelOpen.front() + ";\n\n\t" + labelClose.front() + ":\n";
					labelOpen.pop_front();
					labelClose.pop_front();

					if(loopForWhile)
					{
						loopFor = true;
						loopForWhile = false;

					}
				}
				;

DO				: TK_DO BLOCO TK_WHILE '(' E ')' ';'
				{
					{
						string blocoIf = gerarBloco();
						labelOpen.push_front(blocoIf);
			    			string blocoElse = gerarBloco();
			    			labelOpen.push_front(blocoElse);

			   		 if(loopFor)
					{
						loopFor = false;
						loopForWhile = true;
					}

				}
			
				$$.traducao = $5.traducao + "\n\t" + labelOpen.front() + ":\n" + $2.traducao + "\tif (" + $5.label + ") goto " + labelOpen.front() + ";\n\tgoto " + labelOpen.front() + ";\n\n\t" + labelClose.front() + ":\n";
				labelOpen.pop_front();
				labelClose.pop_front();

				if(loopForWhile)
				{
					loopFor = true;
					loopForWhile = false;
				}
			}
			;

FOR 		: TK_FOR '(' ATRIBUICAO ';' E ';' ATRIBUICAO ')' BLOCO
			{	
				{
					loopFor = true;
	
					string blocoIf = gerarBloco();
					labelOpen.push_front(blocoIf);
	
					string blocoAdd = gerarBloco();
					labelAdd.push_front(blocoAdd);
	
					string blocoElse = gerarBloco();
					labelClose.push_front(blocoElse);
				}
		
				$$.traducao = $3.traducao + "\n\t" + labelOpen.front() + ":\n" +  $5.traducao + "\n\tif (" + $5.label +") goto " + labelClose.front() + ";\n\n" + $9.traducao + "\n\t" + labelAdd.front() + ":\n" + $7.traducao + "\tgoto " + labelOpen.front() + ";\n\n\t" + labelClose.front() + ":\n";

				labelOpen.pop_front();
				labelAdd.pop_front();
				labelClose.pop_front();
				loopFor = false;
			}
			;


%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{	
	op[1][1] = "int";
	op[1][2] = "float";
	op[1][3] = "ilegal";
	op[1][4] = "string";
	op[1][5] = "ilegal";
	op[2][1] = "float";
	op[2][2] = "float";
	op[2][3] = "ilegal";
	op[2][4] = "string";
	op[2][5] = "ilegal";
	op[3][1] = "ilegal";
	op[3][2] = "ilegal";
	op[3][3] = "string";
	op[3][4] = "string";
	op[3][5] = "ilegal";
	op[4][1] = "string";
	op[4][2] = "string";
	op[4][3] = "string";
	op[4][4] = "string";
	op[4][5] = "ilegal";
	op[5][1] = "ilegal";
	op[5][2] = "ilegal";
	op[5][3] = "ilegal";
	op[5][4] = "ilegal";
	op[5][5] = "boolean";	
	yyparse();
	return 0;
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

void yyerror(string MSG )
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
	static int bloco = 1;
	stringstream label;
	label << " bloco " << bloco++;
	return label.str();
}
string gerarfimbloco()
{	
	static int bloco = 0;
	stringstream label;
	label << " fim_if " << bloco++;
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
		if(i->second.tipo == "boolean"){
			continue;
		}else{
			s << i->second.tipo << " " << i->second.label << ";\n";
		}
	}
	variaveis += s.str() + "\n";
	return variaveis;
}


/*string valorBoolean (string a) {
	if (a == "true") return "1";
	else if (a == "false") return "0";
}*/

int tipoToIndice(string tipo)
{
	if(tipo == "int") 
		return 1;
	else if(tipo == "float") 
		return 2;
	else if(tipo == "string") 
		return 3;
	else if(tipo == "char") 
		return 4;
	else if(tipo == "boolean") 
		return 5;
}

string intToString(int label)
{
	stringstream out;
	out << label;
	return out.str();
}
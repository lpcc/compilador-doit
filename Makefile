all: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -lfl

		./glf < Exemplos/rascunho.doit

ex1: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -lfl


		./glf < Exemplos/ex-SOMA.doit

ex2: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -lfl

		./glf < Exemplos/ex-IFELSE.doit

ex3: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -lfl

		./glf < Exemplos/ex-INCDEC.doit

ex4: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -lfl

		./glf < Exemplos/ex-LOGI.doit

ex5: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -lfl

		./glf < Exemplos/ex-RELA.doit

ex6: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -lfl

		./glf < Exemplos/ex-BOOL.doit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   /// biblioteca para strings

struct funcionario {//    inicio
	int codigo; // tipo , nome variavel
	int idade;
	float salario;
	char nome [30];     // char nada mais é que um vetor de tipo char...string
	
 }func1; /// uma versão

int main()
{
	printf("\n Formulário de dados pessoas sobre funcionários \n");
	printf("\n Digite o codigo...:");	
	scanf("%i",&func1.codigo);
	                 
	setbuf(stdin,NULL);				                           // func1.nomevariavel
	printf("\n Digite o nome...:");
	//scanf("%s",&func1.nome);
	gets(func1.nome);
	//scanf ("%30[^\n]",&func1.teste);
	setbuf(stdin, NULL);
		
	printf("\n Digite o idade...:");
	scanf("%i",&func1.idade);
	
	
	printf("\n Digite o salario...:");
	scanf("%f",&func1.salario);

	printf("\n+------------------------------+");
	printf("\n|   Cadastro Funcionário       |");
	printf("\n+------------------------------+");
	printf("\n|   Nome = %s                  |",func1.nome);
	printf("\n|   codigo = %i                |",func1.codigo);
	printf("\n|   idade = %i                 |",func1.idade);
	printf("\n|   salario = %0.2f            |",func1.salario);
	printf("\n+------------------------------+");

	system("pause");
	return 0;
}











































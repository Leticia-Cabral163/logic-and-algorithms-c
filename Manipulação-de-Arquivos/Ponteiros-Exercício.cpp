#include <stdio.h>
#include <stdlib.h>

/*
   Exercicio Ponteiros - Testes de fluxo de entrada e saída (I/O) de arquivos.
*/

int main()
{
	char frase[50];
	
	FILE*Apontar; //variavel ponteiro tipo FILE
	              // ponteiro que aponta para o tipo FILE
		Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\Linguagem prog\\Testeprog","w");
		//caminho do arquivo, se nao foe informado
		//procura na pasta padrao da fonte
		// w- write - criar e escrever arquivo
		if(Apontar==NULL)
		{
			printf("\n\n Arquivo nao encontrado \n\n");
		system("pause");
		return 0;	
		}
		fprintf(Apontar,"primeira linha do arquivo\n");
		fprintf(Apontar,"segunda linha do arquivo\n");
		fprintf(Apontar,"terceira linha do arquivo\n");
		fprintf(Apontar,"quarta linha do arquivo\n");
		
		fclose(Apontar); //fechar e salvar arquivo 
		
		
		
system("pause");
return 0;
}

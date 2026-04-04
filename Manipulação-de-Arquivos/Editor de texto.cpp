// programa editor de texto , um bloco de notas
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
	char frase[100];
	
int escrever()
{ //função para criar e escrever no arquivo 
	setbuf(stdin, NULL); // limpara teclado e puder colocar espaço 
	FILE*Apontar; 
		Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\Novoarquivo","w");
		
		if(Apontar==NULL)
		  {
			printf("\n\n Arquivo nao encontrado \n\n");
		    system("pause");
		    return 0;	
		   }
		printf("\n Comece aqui ...:");
		gets(frase);
		fputs(frase,Apontar);
		
		fclose(Apontar); //fechar e salvar arquivo 
}

int  adicionar_arquivo() // função para adicinar texto ao arquivo
{ 
        setbuf(stdin, NULL);
		FILE*Apontar; //variavel ponteiro tipo FILE
	              // ponteiro que aponta para o tipo FILE C:\Users\CEDUP16\Desktop\Leticia cabral\CEDUP\TEI\Linguagem prog
		Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\Novoarquivo","a");
		
		if(Apontar==NULL)
		  {
			printf("\n\n Arquivo nao encontrado \n\n");
		    system("pause");
		    return 0;	
		   }
		fprintf(Apontar,"\n ");
		printf("\n Adicione ...:");
		gets(frase);
		fputs(frase,Apontar);
		
		fclose(Apontar); //fechar e salvar arquivo 
}


int ler_arquivo() // função para ler o arquivo
{
	    setbuf(stdin, NULL);
		FILE*Apontar; //variavel ponteiro tipo FILE
	              // ponteiro que aponta para o tipo FILE C:\Users\CEDUP16\Desktop\Leticia cabral\CEDUP\TEI\Linguagem prog
		Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\Novoarquivo","r");
		
		if(Apontar==NULL)
		  {
			printf("\n\n Arquivo nao encontrado \n\n");
		    system("pause");
		    return 0;	
		   }
//     enquanto(pegue(string,tamanho,ponteiro) diferente de nulo)
//      escreva 
	    while(fgets(frase, 100, Apontar) != NULL)
        printf("%s", frase);
		
		fclose(Apontar); //fechar e salvar arquivo 
}
  
int main()
{
	
	int opcao;
    do        
   {
   	printf ("\n+-------------------------------------------------------+");
   	printf ("\n|           Menu Editor de Texto                        |");
   	printf ("\n+-------------------------------------------------------+");
   	printf ("\n|           1 = Escrever um novo arquivo                |");
   	printf ("\n|           2 = Retomar Arquivo                         |");
   	printf ("\n|           3 = Ler arquivo                             |");
   	printf ("\n|           4 = Sair do programa                        |");
   	printf ("\n+-------------------------------------------------------+");
    printf ("\n\n    Digite...:"); 
    scanf ("%i", &opcao);
    switch (opcao)
           {
           	case 1:
               escrever(); // funcção para criar e escrever um arquivo
               setbuf(stdin, NULL);
                break;  	
        	case 2:
                adicionar_arquivo(); // função para adicinar texto ao arquivo 
                setbuf(stdin, NULL);
                break;
           	case 3:
               ler_arquivo(); // função para ler o arquivo 
           	    break;
           	case 4:
           		 opcao = 45;
           	     printf ("\n\n Saindo do programa\n\n");
           	    break;
           	    
           	    
           	    
           }  //  fim do switch
    }  while ((opcao > 0 ) && (opcao <= 10));    // fim do while
	system("pause");
	return 0;
}






























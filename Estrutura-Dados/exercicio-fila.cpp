

#include <stdio.h>
#include <stdlib.h>

int fila[10], ini_fila=-1, ff=-1, opcao, limite, i, qtde=0;

void inserir()
{
        ff++;
        qtde++;
		printf ("\n Digite um numero inteiro para inserir na fila...: ");
        scanf ("%i",&fila[ff]);
		printf ("\n Concluido \n ");
		if (ff>9)
		{
			ff=0;
		}
} // fim inserir

void retirar()
{
      ini_fila++;
      qtde--;
      printf ("\n Concluido \n");
      if (ini_fila>9)
      {
      	ini_fila=0;
      }
} // fim retirar

void mostini()
{
  printf ("\n | %i |", fila[ini_fila+1]);
  printf ("\n\n Concluido \n");
} // fim mostrar inicio

void mostfim()
{
  printf ("\n | %i |", fila[ff]);
  printf ("\n\n Concluido \n");
} // fim mostrar fim

void mostfila()
{
  	for (i=ini_fila+1;i<=ff;i++)
  	{
  	  printf ("\n | %i | ", fila[i]);
  	} 
	printf ("\n Concluido \n");
} // fim mostrar fila




int main ()
{
	do
	{
	
      printf ("\n -------------------------------------------");
      printf ("\n |    EXERCICIO FILA CIRCULAR                |");
	  printf ("\n -------------------------------------------");
	  printf ("\n |      1- Inserir                           |");
	  printf ("\n |      2- Retirar                           |");
	  printf ("\n |      3- Mostrar Inicio                    |");
	  printf ("\n |      4- Mostrar Final                     |");
	  printf ("\n |      5- Mostrar Fila Inteira              |");
	  printf ("\n |      6- Sair                              |");
	  printf ("\n -------------------------------------------");	
	  printf ("\n Escolha a opcao...: ");
	  scanf ("%i",&opcao);
	  
	  switch (opcao)
	  {
	  	case 1:
	  		printf ("\n Inserir dados na fila \n");
	  		if (qtde==10)
	  		{
	  			printf ("\n Fila cheia - overflow \n");
	  		}
	  		else 
			  {
	  			inserir();
	  		  }
	  		break;
	  	case 2:
	  		printf ("\n Retirar dados da fila \n");
	  		if (qtde==0)
	  		{
	  			printf ("\n Fila vazia - underflow \n");
	  		}
	  		retirar();
	  		break;
	  	case 3:
	  		printf ("\n Mostrar o dado que esta no inicio da fila \n");
	  		mostini();
	  		break;
	  	case 4:
	  		printf ("\n Mostrar o dado que esta no final da fila \n");
	  		mostfim();
	  		break;
	  	case 5:
	  		printf ("\n Mostrar a fila inteira \n");
	  		mostfila();
	  		break;	
	  	case 6:
	  		opcao = 25;
	  		break;
		  default:
	  		printf ("\n Opcao invalida \n");
	  		opcao = 1;
	  }	// fim switch
	  
	}while ((opcao>0) && (opcao<9)); //fim do
	
  printf ("\n\n");
  system ("pause");
  return 0;		
}

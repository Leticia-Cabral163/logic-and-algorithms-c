#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <math.h>

/*
     Implementação de lógica de criptografia com chaves públicas/privadas.
     Novembro/2025
*/
int a,b,x,Ra,Rb,PK;
int opcao;

int a_b()  //função digite A E B
{
	printf("\n Chaves publicas A-B");
	printf("\n Digite um numero para A ...:");
	scanf("%i",&a);
	printf("\n Digite o valor de  B ...:");
	scanf("%i",&b);
	 
	 system("pause");  	
}



 int calc_Ra()  // função calcula o Ra e escolhe X
{
   printf("\n Calcular Ra");
   printf("\n Escolha uma chave privadas X...: ");
	scanf("%i",&x);	
   Ra= pow (a,x);
   Ra = Ra %b;
   
   printf("\n O valor de Ra ...: %i \n",Ra);
   
   system("pause");
}


int calc_PK()	//função calcula PK digita valor de Rb
{
   printf("\n Carcular PK ");
   printf("\n Digite o valor de Rb ...:");
	scanf("%i",&Rb);		
   PK = pow(Rb,x);
   PK = PK %b; 
   
   printf("\n O valor de PK ...: %i \n",PK);
   
   system("pause");
}



int main ()
{
	do
	   {
//         system("cls"); // comando  limpar tela
         system("color 50");
         printf ("\n +-------------------------------------------+");
         printf ("\n |    PROGRAMA DE ALICE                      |");
	     printf ("\n +-------------------------------------------+");
	     printf ("\n |      1-Chaves Públicas                    |");
	     printf ("\n |      2-Calcular Ra                        |");
	     printf ("\n |      3-Calcular chave privada PK-         |");
	     printf ("\n |      4- Sair                              |");
	     printf ("\n +-------------------------------------------+");	
	     printf ("\n Escolha a opcao...: ");
	      scanf ("%i",&opcao);
	  
	     switch (opcao)
	     {
	  	   case 1:	  	   	
	           a_b(); // função escolher a e b ( chaves publicas) 	  	 
	  		 break;
	  	    
	    	 
	    	case 2: //função Ra
	  	         calc_Ra();
	    	break;
		   
		   case 3:  //função calcula pk
		       calc_PK();	
           break;
       
		   case 4: //sair
		       	opcao = 25;
	  	     	break;
		     
		 default:                                       // opcao DEFAULT
	  		printf ("\n Opcao invalida \n");
	  		opcao = 1;
	    }	
	  
	   }while ((opcao>0) && (opcao<20)); //fim do S switch
	
  printf ("\n\n");
  system ("pause");
  return 0;		
}


#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <math.h>

/*
  Exercício: Manipulação de Chaves de Segurança
  Objetivo: Implementação de lógica de criptografia com chaves públicas/privadas.
  Data: Novembro/2025
 */

int a=0,b=0,x,y=0,Ra=0,Rb=0,PK=0,hac,hack,i,j;
int opcao;


int a_b()  //função digite A E B
{
	printf("\n Chaves publicas A-B");
	printf("\n Digite o valor de A ...:");
	scanf("%i",&a);
	printf("\n Digite o valor de  B ...:");
	scanf("%i",&b);
	 
	 system("pause");  	
}



 int calc_xey()  // função calcula x e y
{
   printf("\n Calcular x e y");
   printf("\n Digite o valor de Ra...: ");
   scanf("%i",&Ra);	
   
   	    for(i=0;i<=99;i++)
   	    {
   	    	hac = pow(a,i);
            hac = hac  %b;
            if(hac == Ra)
            {
             break;	
            }
   	    }
   
   printf("\n O valor de x ...: %i \n",i);
   x=i;
   printf("\n Digite o valor de Rb...: ");
   scanf("%i",&Rb);	
   
   	    for(j=0;j<=99;j++)
   	    {
   	    	hack = pow(a,j);
            hack = hack  %b;
            if(hack == Rb)
            {
             break;	
            }
   	    }
   
   printf("\n O valor de y ...: %i \n",j);
   y=j;
   system("pause");
}


int calc_PK()	//função calcula PK 
{
   printf("\n Carcular PK ");
   PK = pow(Rb,x);
 	PK = PK %b;	
   // PK = (RbX) mod B;
   printf("\n O valor de PK ...: %i \n",PK);
   
   system("pause");
}



int main ()
{
	do
	   {
//         system("cls"); // comando  limpar tela
          system("color 40");
         printf ("\n +-------------------------------------------+");
         printf ("\n |    PROGRAMA HACKER QUEBRA A CHAVE         |");
	     printf ("\n +-------------------------------------------+");
	     printf ("\n |      1-Valores de A - B                   |");
	     printf ("\n |      2-Calcular X - Y                     |");
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
	  	    
	    	 
	    	case 2: //função calcular x e y
	  	         calc_xey();
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


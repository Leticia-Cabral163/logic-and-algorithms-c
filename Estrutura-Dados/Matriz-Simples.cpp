#include <stdio.h>
#include <stdlib.h>
int matriz1[3][4],matriz2[3][4],matriz3[3][4],i,j,opcao,soma,conta,soma2,conta2;
float media,media2;
   int cargamat() 
    {
        printf 	("\n Carregar a primeira  Matriz ");
	
	   for (i=0;i<=2;i++)
	       { 
	         for ( j=0;j<=3;j++)
	             {
	   	         	printf("\n Digite um valor para a matriz ...:");
	   	         	scanf("%i",&matriz1[i][j]);
                    soma=soma+ matriz1[i][j];
                    conta++;
	   	         }
      }
         printf("\n Operação realizada com sucesso ! \n");
     }

    int mostrarmat()
    {
    	printf("\n Mostrar  primeira matriz ");
    	 for (i=0;i<=2;i++)
	     { 
	       for ( j=0;j<=3;j++)
	           {
	   	     	printf("\n Na posicao %i tem....: %i" ,i,matriz1[i][j]);
	   	       }
      }
    printf("\n Operação realizada com sucesso ! \n");
    }
    int media_matriz1()
    {
    	printf ("\n Calcular a media da matriz ");
    	media=(float)soma/conta;
    	printf("\n A media da primeira matriz e ...: %f",media);
    	
    }
       int cargamat_2() 
     {
       printf 	("\n Carregar a segunda  Matriz ");
	
	  for (i=0;i<=2;i++)
	       { 
	         for ( j=0;j<=3;j++)
	             {
	   	         	printf("\n Digite um valor para a matriz ...:");
	   	         	scanf("%i",&matriz2[i][j]);
	   	         	soma2=soma2+matriz2[i][j];
	   	         	conta2++;
	   	         }
      }
    printf("\n Operação realizada com sucesso ! \n");
    }
      int mostrarmat_2()
    {
    	printf ("\n Mostrar  a segunda matriz ");
    	 for (i=0;i<=2;i++)
	     { 
	       for ( j=0;j<=3;j++)
	           {
	   	     	printf("\n Na posicao %i tem....: %i" ,i,matriz2[i][j]);
	   	       }
      }
    printf("\n Operação realizada com sucesso ! \n");
    }
    int  media_matriz2()
    {
    	printf ("\n Calcular a media da segunda  matriz ");
    	media2=(float)soma2/conta2;
    	printf("\n A media da primeira matriz e ...: %f",media2);
    }
	int  multipli_matriz3() 
     {
       printf 	("\n  Multiplicação das matrizes ");
	
	      for (i=0;i<=2;i++)
          	{ 
	           for ( j=0;j<=3;j++)
	                {
                         
	              	 	matriz3[i][j]= (matriz1[i][j] * matriz2[i][j] );
	   	             }
      }
    printf("\n Operação realizada com sucesso ! \n");
    }
    int mostrar_mat3()
    {
    	printf ("\n Mostrar  a terceira matriz ");
    	 for (i=0;i<=2;i++)
	     { 
	       for ( j=0;j<=3;j++)
	           {
	   	     	printf("\n Na posicao %i tem....: %i" ,i,matriz3[i][j]);
	   	       }
      }
    printf("\n Operação realizada com sucesso ! \n");
    }
  
      
    
int main()
{
	do 
	{
	
	printf ("\n+-------------------------------------------------------+");
   	printf ("\n|           Menu Matriz                                 |");
   	printf ("\n+-------------------------------------------------------+");
   	printf ("\n|           1 = Carga Matriz                            |");
   	printf ("\n|           2 = Mostrar Matriz                          |");
   	printf ("\n|           3 = Mostrar a media da matriz               |");
   	printf ("\n|           4 = Carga segunda Matriz                    |");
   	printf ("\n|           5 = Mostrar Segunda Matriz                  |");
   	printf ("\n|           6 = Mostrar a media da matriz               |");
   	printf ("\n|           7 = Multiplicacao para a terceira Matriz    |");
   	printf ("\n|           8 = Mostrar a terceira matriz               |");
    printf ("\n|           9= Sair do Programa                         |");
   	printf ("\n+-------------------------------------------------------+");
    printf ("\n\n    Escolha a opcao.....: "); 
    scanf ("%i", &opcao);
   
    switch (opcao)
           {
           	case 1:
               cargamat();
               break;  
            case 2:
                mostrarmat();
                break;
            case 3:
                media_matriz1();
                break;
	 	    case 4:
                cargamat_2();
                break;
           	case 5:
                mostrarmat_2();
                break;
            case 6:
                media_matriz2();
                break;
            case 7:
			    multipli_matriz3();
				break;
	        case 8:
                mostrar_mat3();
                break;    
               case 9:
			    opcao = 24;
           	     printf ("\n\n Saindo do programa\n\n");
           	    break;
           	    
		    default:
			   printf ("\n\n Opcao invalida - Preste atencao no que faz\n\n");
			   opcao = 15;	
			   break;
			   
           }  //  fim do switch
    }  while ((opcao > 0 ) && (opcao <= 12));    // fim do while
    system ("pause");
	return 0;   
}

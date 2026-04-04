#include <stdio.h>
#include <stdlib.h>

int vet1[5],vet2[5],vet3[10] ,j,i,t, umzero=0;


int cargavet1()
   {
      printf ("\n\n Carregar  o primeiro vetor");
 
       for(i=0;i<=4;i++)
          {
  	       printf ("\n Digite um inteiro na posicao %i do vetor..: ", i);
  	        scanf ("%i", &vet1[i]);
  	          if (vet1[i]==0)
  	          {
  	          	umzero=1;
  	          }
          }		
   }
    
   int mostrarvetint()
    {
      printf ("\n\n Mostrar  o primeiro vetor inteiro");
     	printf ("\n O conteudo do vetor..: ");
     	for(i=0;i<=4;i++)
            {
  	          printf (" %i ", vet1[i]);
            }		
    }
    
    int cargavet2()
   {
      printf ("\n\n Carregar o segundo vetor");
 
       for(i=0;i<=4;i++)
          {
  	       printf ("\n Digite um inteiro na posicao %i do vetor..: ", i);
  	        scanf ("%i", &vet2[i]);
  	        	          if (vet2[i]==0)
  	          {
  	          	umzero=1;
  	          }
          }		
   }
    
   int mostrarvetint2()
    {
      printf ("\n\n Mostrar o segundo  vetor inteiro");
     	printf ("\n O conteudo do vetor..: ");
     	for(i=0;i<=4;i++)
            {
  	          printf (" %i ", vet2[i]);
            }		
    }
    
    
  int concatenacaovet3()
{ 
  printf("\n concatenação dos dois vetores");
    j=-1;
	for(i=0;i<=4;i++)
          {
          j++;          
          vet3[j]=vet1[i];
          j++;
		  vet3[j]=vet2[i];

          }	
 
 }
 
  int mostrarvet3()
  {
  	printf("\n Mostrar o terceiro vetor");
  	printf ("\n O conteudo do vetor..: ");
     	for(i=0;i<=9;i++)
            {
  	          printf (" %i", vet3[i]);
            }	 
  }
  int subzero()
  {
  	printf("\n Percorrer vetor trocando os valores repetidos por zero ");
    	for (i=0;i<=9;i++)
    	    for (j=i+1;j<=9;j++)
            	{    
  		         if(vet3[i] == vet3[j])
  		    		vet3[j]=0;
  		       }
  }
  
  
  int ordemcrescente()
  {
  	printf("\n Reordenar Vetor em Ordem Crescente ");;
    	for (i=0;i<=9;i++)
    	    for (j=i+1;j<=9;j++)
             	{
    	    	 if (vet3[i] > vet3[j] )
    		       {  
    		        t=vet3[i];
    		       vet3[i]= vet3[j];
    		        vet3[j]=t;
    		       }
			 
    	        }
    printf("\n operacao feita com sucesso!");
  }
    int zerosultimo()
    {
    
 	   printf("\n Colocar os zeros por ultimo , sendo que um deles continuara na frente");

while (vet3[umzero]==0)
{
  for(i=umzero;i<=9;i++) 	
  	{
  	 if(vet3[i]==0)
 	   	   {
 	   	   	 vet3[i]=vet3[i+1];
 	   	   }
 	   }
 	   vet3[9]=0;
 	   printf("\n Operacao feita com sucesso");
    }
}
int main(){
   int opcao;	
   do        
   {
   	printf ("\n+-------------------------------------------------------+");
   	printf ("\n|           Menu Vetor                                  |");
   	printf ("\n+-------------------------------------------------------+");
   	printf ("\n|           1 = Carga Vetor                             |");
   	printf ("\n|           2 = Mostrar Vetor Inteiro                   |");
   	printf ("\n|           3 = Carga  Vetor 2                          |");
   	printf ("\n|           4 = Mostrar Vetor2 inteiro                  |");
   	printf ("\n|           5 = Concatenação dos Vetores                |");
   	printf ("\n|           6 = Mostrar Vetor 3                         |");
   	printf ("\n|          7 = Sustituir os valores iguais              |");
    printf ("\n|          8 = Colocar vetor em ordem crescente         |");
    printf ("\n|          9 = Colocar os zeros por último              |");
    printf ("\n|          10= Sair do Programa                         |");
   	printf ("\n+-------------------------------------------------------+");
    printf ("\n\n    Escolha a opcao.....: "); 
    scanf ("%i", &opcao);
   
    switch (opcao)
           {
           	case 1:
               cargavet1();
               break;  
            case 2:
                mostrarvetint();
                break;
			case 3:    
                cargavet2();
                break;	           
			case 4:    
                mostrarvetint2();
                break;		
			case 5:			 
                concatenacaovet3();
           	    break;
            case 6:
                mostrarvet3();
                break;
             case 7:
               subzero();
               break;  
           	
           	case 8:
           		ordemcrescente();
           		break;
           case 9:
           	   zerosultimo();
           	   break;
           	case 10:
                opcao = 24;
           	     printf ("\n\n Saindo do programa\n\n");
           	    break;
           	    
		    default:
			   printf ("\n\n Opcao invalida - Preste atencao no que faz\n\n");
			   opcao = 13;	
			   break;
			   
           }  //  fim do switch
    }  while ((opcao > 0 ) && (opcao <= 10));    // fim do while
    system ("pause");
	return 0;   
 } 

#include <stdio.h>
#include <stdlib.h>
int vet[5],opcao,i,contador,contador2;
int topo=-1;

 int inserir()
 {if (topo >=4)
 	   printf("\n pilha cheia - OVERFLOW \n");
 	 else  
 	 { topo++;
 	 printf("\n Inserir dados na pilha ");
 	 printf("\n Digite um valor ...:");
 	 scanf("%i",&vet[topo]);
     } //fim_else
 } //fim_inserir
 
 int retirar()
 {  if ( topo<=0)
    printf("\n pilha vazia - UNDERFLOW \n"); 
    else {
    printf("\n Retirar dados na pilha ");
    vet[topo--];
    printf("\n Operacao feita com sucesso");
    }//fim_else
 }//fim_retirar
  
  int most_topo()
  {	printf("\n Mostrar o topo da pilha ");
  	printf("\n | %i | ",vet[topo]);
  }//fim_most_topo
  
  int most_pilha()
  { printf("\n Mostrar a pilha inteira");
  	for(i=topo;i>=0;i--)
  	   {
  	   	printf(" \n  | %i |",vet[i]);
  	   }
  	printf("\n :)");
  }//fim_most_pilha
  
int main()
{
    do        
   {
   	printf ("\n+-------------------------------------------------------+");
   	printf ("\n|           Menu Pilha                                  |");
   	printf ("\n+-------------------------------------------------------+");
   	printf ("\n|           1 = Inserir dados na pilha                  |");
   	printf ("\n|           2 = Retirar dados na pilha                  |");
   	printf ("\n|           3 = Mostrar dado do topo                    |");
   	printf ("\n|           4 = Mostrar pilha inteira                   |");
    printf ("\n|           5 = Sair do programa                        |");
   	printf ("\n+-------------------------------------------------------+");
    printf ("\n\n    Escolha a opcao.....: "); 
    scanf ("%i", &opcao);
    switch (opcao)
           {
           	case 1:
               inserir();
                break;  
            case 2:
			       retirar();
			       break;
			case 3:    
                most_topo();
                break;	           
			case 4:    
               most_pilha();
                break;		
        	case 5:
               int opcao = 45;
           	     printf ("\n\n Saindo do programa\n\n");
           	    break;
           	    
           }  //  fim do switch
    }  while ((opcao > 0 ) && (opcao <= 8));    // fim do while
	system("pause");
	return 0;
}

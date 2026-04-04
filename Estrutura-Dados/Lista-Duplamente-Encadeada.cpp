
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // biblioteca limpar

int lista[10][3],i,j,opcao,eloi=0,elof=2,disp=1,pv,aux,aux1,meio,aux2,meio2;
//        linha coluna

  int inicio_lista() //          |funcao iniciar a  matriz NODO CABECA| 
     {
       for(i=0;i<=9;i++)
          {
            for(j=0;j<=2;j++)
               {
             	lista[i][j]= 0 ;//  limpa matriz
               }
       	   lista[i][2]= i+1;  //   	sequencia nodos disponiveis
         }
     lista[0][0]=1; // inicio recebe 1
     lista[0][1]= 1; // disponivel recebe 1
     lista[0][2]= 0; 
     lista[9][2]=0; // ultimo registro recebe 0
      printf("\n Lista iniciada com sucesso ! \n");
    system("pause");
    }

  int inserir_final() //            | FUNÇAO INSERIR PELO FINAL|      
     {         
		printf ("\n Inserir pelo final da fila ");
		printf ("\n Digite um numero...: ");
		scanf("%i",&lista[lista[0][1]][1]); //posição x recebe o disponivel	            
		aux= lista[0][1]; // auxiliar recebe o disponivel
		lista[aux][0]=0; // sucessor recebe 0
		lista[lista[0][2]][0]=lista[0][1]; // linha do último na coluna 0  recebe o disponível
		lista[0][1]=lista[aux][2]; // o disponível recebe o antecessor
		lista[aux][2]=lista[0][2]; // antecessor recebe o ultimo
		lista[0][2]= aux; // ultimo recebe o auxiliar
		
		 system(" \n pause"); 	 	      			
    }

int visualizar_Matriz_Inteira(){	// funcão visualizar toda a lista
      
      printf("\n              Mostrar lista Inteira \n");
        printf("\n            +------+------+------+ ");
		 printf("\n           | Eloi | Disp | Elof | ");
	    printf("\n            +------+------+------+ ");
	  for(i=0;i<=9;i++)
      {  
      	 printf("\n Linha %i  |  %i  |  %i  |  %i  |",i,lista[i][eloi],lista[i][disp],lista[i][elof]);
      	 if(i==0)
          {
          	printf("\n        +------+------+------+ ");
          }
      }
         printf("\n           +------+------+------+ ");
    system("pause");
}

int  inserir_inicio()
{
  	printf ("\n Inserir pelo inicio da fila ");
		printf ("\n Digite um numero...: ");
		scanf("%i",&lista[lista[0][1]][1]); //posição x recebe o disponivel

  lista[lista[0][0]][2]=lista[0][1];  //  lista ( inicio)(2) = disponível    
  lista[lista[0][1]][0]=lista[0][0];  // lista(disponível)(0) = início
  lista[0][0]=lista[0][1]; // inicio = disponível           
  lista[0][1]=lista[lista[0][1]][2]; // disponível = lista(disponível)(2)  
  lista[lista[0][0]][2]=0; //  lista(disponível)(2) = 0  
   system(" \n pause");      
}

int  inserir_meio()
{

        int aux1;
	printf ("\n Inserir no Meio \n");

     if (lista[0][1]==0)
        {
         printf("\n A lista esta Cheia");
         printf("\n Disp..: %i", lista[0][1]);
        }
       else
       {
        printf("\nEntre com posição desejada ...:");
        scanf("%i", &meio);
        printf("\nDigite um numero para Posica %i..: ", lista[0][1]);
        scanf("%i", &lista[lista[0][1]][1]);

         aux=lista[meio][0];  
        aux1=lista[lista[0][1]][2];  // o proximo disponivel  7
        lista[meio][0]=lista[0][1]; // apontar para o proximo da ordem logica  Disponive
        lista[lista[0][1]][2]=meio;  // apontar para o proximo da ol - antecessor
        lista[aux][2]=lista[0][1];   // apontar para o antecessor - disponivel
        lista[lista[0][1]][0]=aux;  // apontar para o a sucessor
        lista[0][1]=aux1;
system(" \n pause"); 
}
}

 int listar_inicio(){
	
	printf ("\n Listar pelo Inicio \n");  	
    aux2=lista[0][0];
	 do {
	      printf("\n %i",lista[aux2][1]);
	      aux2 = lista[aux2][0];	
	 }while(aux2>0);
	printf ("\n Lista Terminada!  \n");
	system(" \n pause"); 
}

 int listar_final()
 {
 	printf ("\n Listar pelo Final \n");  	
    aux2=lista[0][2];
	 do {
	      printf("\n %i",lista[aux2][1]);
	      aux2 = lista[aux2][2];	
	 }while(aux2>0);
	printf ("\n Lista Terminada!  \n");
	system(" \n pause");
 	
 }
 
  int Retirar_Inicio()
  {
  	printf ("\n Retirar pelo inicio \n");
     aux1 = lista[lista[0][0]][0]; // auxiliar recebe o linha inicio coluna 0
     lista[lista[0][0]][1] = 0; // retirou
     lista[lista[0][0]][0] = lista[0][1]; // retirado sucessor recebe disponível
     lista[0][1] = lista[0][0]; // disponível recebe o retirado
     lista[0][0] = aux; // inicio recebe o aux
     lista[lista[0][0]][2] = 0; // registro sucessor se torna o início

	printf ("\n Operação Realizada com sucessor!  \n");
	system(" \n pause");
    
  }
  
   int Retirar_Final()
  {
  	printf ("\n Retirar pelo Final \n");
    aux = lista[lista[0][2]][2]; // auxiliar recebe o linha ultimo coluna 2
     lista[lista[0][2]][1] = 0; // retirou
     lista[lista[0][2]][2] = lista[0][1]; // retirado sucessor recebe disponível
     lista[0][1] = lista[0][2]; // disponível recebe o retirado
     lista[0][2] = aux; // último recebe o aux
     lista[lista[0][2]][0] = 0; // registro sucessor se torna o início

	printf ("\n Operação Realizada com sucessor!  \n");
	system(" \n pause");
    
  }
  
  int Retirar_Meio()
  {
  	printf ("\n Retirar pelo Meio \n");
  	visualizar_Matriz_Inteira();
  	printf ("\n\n Digite a posição que voce quer retirar...: \n");
  	scanf("%i", &meio2);
  	aux = lista[meio2][0]; // auxiliar recebe o sucessor     
    lista[meio2][1] = 0; // retirou
    lista[meio2][0] = lista[0][1]; // sucessor aponta para o antigo disponivel
    lista[0][1] = meio2; // disponivel aponta para o meio2
    lista[aux][2] = lista[meio2][2]; // linha do aux na coluna 2 recebe o antecessor do meio2
    lista[lista[meio2][2]][0] = aux;
    lista[meio2][2]= lista[meio2][0] ;
    
    	printf ("\n Operação Realizada com sucessor!  \n");
	system(" \n pause");

  }
  
int main ()
{
	do
	   {
//         system("cls"); // comando  limpar tela
         printf ("\n +-------------------------------------------+");
         printf ("\n |    EXERCICIO LISTA DUPLAMENTE ENCADEADA   |");
	     printf ("\n +-------------------------------------------+");
	     printf ("\n |      1- Inicializar Lista                 |");
	     printf ("\n |      2- Inserir Pelo Final                |");
	     printf ("\n |      3- Inserir pelo Início               |");
	     printf ("\n |      4- Inserir pelo Meio                 |");
	     printf ("\n |      5- Visualizar Matriz Inteira         |");
	     printf ("\n |      6- Retirar Final                     |");
	     printf ("\n |      7- Retirar Inicio                    |");
	     printf ("\n |      8- Retirar Meio                      |");
	     printf ("\n |      9- Listar Final                      |");
	     printf ("\n |     10- Listar Inicio                     |");
	     printf ("\n |     11- Sair                              |");
	     printf ("\n +-------------------------------------------+");	
	     printf ("\n Escolha a opcao...: ");
	      scanf ("%i",&opcao);
	  
	     switch (opcao)
	     {
	  	   case 1:
	           inicio_lista();  	  
	  	  break;
	 
	     	case 2:
	  		   inserir_final();  
	    	break;
	 
	    	case 3:
	  		 inserir_inicio();
        	break;
	  	
	  	    case 4:
	  	    inserir_meio();
	    	break;
	    	
	    	case 5:
	  	         visualizar_Matriz_Inteira();
	    	break;
	  	
	  	case 6:
	  	       Retirar_Final();
	    	break;
	    	
	  	  case 7:
	  	       Retirar_Inicio();
	    	break;
	    	
	    	 case 8:
	  	       Retirar_Meio();
	    	break;
	  	
	         case 9:
	  	        listar_final();	
          	break;	
          	
	         case 10:
	  	         listar_inicio();	
          	break;	
	  	
	     	  case 11:
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

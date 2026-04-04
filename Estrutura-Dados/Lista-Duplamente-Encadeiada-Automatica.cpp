
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // biblioteca limpar

int lista[10][3],i,j,opcao,eloi=0,elof=2,disp=1,pv,aux,aux1,meio,aux2,meio2;
int posicao,k,num;
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

		lista[lista[0][1]][1]= num; //posição x recebe o disponivel	           
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
   lista[lista[0][1]][1]= num; //posição x recebe o disponivel	  
  lista[lista[0][0]][2]=lista[0][1];  //  lista ( inicio)(2) = disponível    
  lista[lista[0][1]][0]=lista[0][0];  // lista(disponível)(0) = início
  lista[0][0]=lista[0][1]; // inicio = disponível           
  lista[0][1]=lista[lista[0][1]][2]; // disponível = lista(disponível)(2)  
  lista[lista[0][0]][2]=0; //  lista(disponível)(2) = 0  
   system(" \n pause");      
}

int  inserir_meio()
{     
      	printf("\n Inserção pelo meio");
      int auxiliar;   
      int antecessor;
      int  sucessor;
      int aux1;
      antecessor = lista[0][0];
        do
		  {
        	if(lista[antecessor][1] < num )
        	   { 
             	    antecessor = lista[lista[antecessor][2]][0];
			  		   auxiliar = lista[antecessor][0]; 		
        	   }
        	if (lista[auxiliar][1]
			
			
			
			 > num)
        	   {    
        			sucessor = lista[auxiliar][1];
        	   }
        	else
        		{
        			antecessor = auxiliar;
        		}
	
        }while((antecessor < num) && (sucessor > num));
       
      
       	printf("\n passou 2");
        lista[lista[0][1]][1]= num; //posição x recebe o disponivel   lista[linha][coluna]	
        aux=lista[meio][0];  
        aux1=lista[lista[0][1]][2];  // o proximo disponivel  7
       lista[meio][0]=lista[0][1]; // apontar para o proximo da ordem logica  Disponive
       lista[lista[0][1]][2]=meio;  // apontar para o proximo da ol - antecessor
        lista[aux][2]=lista[0][1];   // apontar para o antecessor - disponivel
        lista[lista[0][1]][0]=aux;  // apontar para o a sucessor
    
	    lista[0][1]=aux1; 
	   printf("\n passou 3");
	   system(" \n pause");  
   }


 int listar_inicio()
 {   // função listar pelo inicio
	
	printf ("\n Listar pelo Inicio \n");  	
      aux2=lista[0][0];
	   do
	    {
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
	 do
	  {
	    printf("\n %i",lista[aux2][1]);
	    aux2 = lista[aux2][2];
		  	
	 }while(aux2>0);
	printf ("\n Lista Terminada!  \n");
	system(" \n pause");
 	
 } 
 

int ini_lista_aut() {   
    
    printf("\n Inserir registro na Lista ");
    printf("\n Digite um numero...: ");
      scanf("%i", &num); 
    
//        if (lista[lista[0][0]][1] == 0)  // se o 1 registro da lista for 0 começa pelo final
//		    {
//                inserir_final(); 
//                return 0;
//            }

       if (num >= lista[lista[0][2]][1] ) // se linha(ultimo)(1) for menor inserir pelo finalç
	 {
      
        inserir_final();
    } 
     else
       if (num <= lista[lista[0][0]][1]) // se linha(inicio)(1) for maior que num vai pelo inicio
	    {
              inserir_inicio();
            }
    
    
	else  // se nada der certo vai pelo meio
	{
         printf("\n passou 1");
        inserir_meio();
         printf("\n passou 4");
    }
    
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
         printf ("\n |    LISTA DUPLAMENTE ENCADEADA AUTOMATICA  |");
	     printf ("\n +-------------------------------------------+");
	     printf ("\n |      1-Inicializar Lista                  |");
	     printf ("\n |      2-Inserir Registro                   |");
	     printf ("\n |      3- Retirar Registro                  |");
	     printf ("\n |      4- Visualizar Tudo                   |");
	     printf ("\n |      5- Listar Pelo Inicio                |");
	     printf ("\n |      6- Listar Pelo Final                 |");
	     printf ("\n |      7- Sair                              |");
	     printf ("\n +-------------------------------------------+");	
	     printf ("\n Escolha a opcao...: ");
	      scanf ("%i",&opcao);
	  
	     switch (opcao)
	     {
	  	   case 1:	  	   	
	           inicio_lista(); 	  	 
	  		 break;
	  	    
	       case 2:
	    	 ini_lista_aut(); 
	    	 break;
	    	 
	    	case 4:
	  	         visualizar_Matriz_Inteira();
	    	break;
	  	
	  	       Retirar_Final();
	          Retirar_Inicio();
	           Retirar_Meio();
	       case 5:
		   listar_inicio();
		   break;
		   
		   case 6:
		        listar_final();	
           break;
           
		   case 7:
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

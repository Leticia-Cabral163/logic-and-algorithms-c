#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h> // biblioteca tempo 
#include <math.h>

   struct {   //STRUCT CADASTRO ALUNO 
     int	num_mat;
     char	nome_aluno[30];
     char num_cpf[16];
	 char num_ident[11];
	 int dia;
	 int mes;
	 int ano;
	 int idade;
	 char nome_resp[30];
	 char bairro[30];
    }aluno1,aluno2;

 int ano[13] {00,31,28,31,30,31,30,31,31,30,31,30,31 }; // VETOR ANO 
//            0, 1 , 2 ,3, 4, 5, 6, 7, 8, 9,10,11,12
int validar; 
int resul;
int anobisexto; // Variaveis correcao

    int datadia ;
    int mesdia ; /// variaveis data atual 
    int anodia;
    
   int datavalida() /// funcao CONFERIR DATAS 
  {
	 validar = 0;
	if (( aluno1.ano > anodia ) || (aluno1.ano < 1 )) /// if ano 
		{
		 validar = 3; 
		
		}  else 
			if(( aluno1.mes > 12) || ( aluno1.mes < 1 )) /// if meses  ! sempre apontando o dia
	                {
	 	               validar = 2;
	 	               
	 	            }
	                else 
	                        if(( aluno1.dia > ano[aluno1.mes] )|| (aluno1.dia  < 1 )) /// if dia
	                            {
	 	                          validar = 1;
	                            }
	 	return(validar);		
	 }  /// FIM FUNCAO VALIDAR DATAS 
  
  int inserir() // FUNCAO INSERIR 1 
   {
   	 printf("\n Inserir um aluno");
   	 
   	 printf("\n Digite o numero- da matricula ...:");
   	 scanf("%i",&aluno1.num_mat);
   	 setbuf(stdin, NULL);
   	 
   	 printf("\n Digite o nome do aluno ...:");
   	 gets(aluno1.nome_aluno);
	 setbuf(stdin, NULL);
	 
	 printf("\n Digite o numero do Cpf do aluno...:");
	 gets(aluno1.num_cpf);
	 setbuf(stdin,NULL);
	 
     printf("\n Digite o numero da Identidade do aluno...:");
	 gets(aluno1.num_ident);
	 setbuf(stdin,NULL);
	 
     do{  // OPERACAO DATA E IDADE 
     		 
	 printf("\n Digite o numero do dia de nascimento do aluno...:"); 
	 scanf("%i",&aluno1.dia);
	 printf("\n Digite o numero do mes de nascimento do aluno ...:");
	 scanf("%i",&aluno1.mes);
	 printf("\n Digite o numero do ano de nascimento do aluno ...:");
	 scanf("%i",&aluno1.ano);
	 setbuf(stdin, NULL);	 

     resul = datavalida(); // conferir datas	 
	     if( resul != 0 )	//if se estiver errado
	  	  	{
	  	  		printf("\n   Data Incorreta");
	  	  		
	  	  		 if ( resul == 1) /// if dia incorreto 
	  	  		{
	  	  			printf("\n !Dia invalido !");
	  	  		}    
	  	  		if ( resul == 2) /// if mes incorreto 
	  	  		{
	  	  			printf("\n ! Mes invalido ");
	  	  		}
					if ( resul == 3) /// if ano incorreto 
	  	  		{
	  	  			printf("\n ! Ano invalido ");
	  	  		}	
			   printf("\n Digite novamente ....:  "); 
	  	  	} 

      }while ( resul != 0); // LAÇO PARA DIGITAR DATAS VALIDAS  
	                                             
	 printf("\n Digite o nome do responsavel do aluno ...:");
	scanf("%30[^\n]", aluno1.nome_resp);
	 setbuf(stdin, NULL);
	 
	 printf("\n Digite o bairro de residencia do aluno ....:");
	 gets(aluno1.bairro);
	 
   } /// FINAL OPCAO 1 INSERIR
   
int visualizar()  //// IMPRIMIR OPCAO 2 
    {
    	printf("\n         Cadastro do aluno ");
    	printf("\n Matricula : %i",aluno1.num_mat);
    	printf("\n Nome do aluno : %s",aluno1.nome_aluno);
    	printf("\n CPF : %s ",aluno1.num_cpf);
    	printf("\n Data de Nascimento %i/%i/%i  ",aluno1.dia,aluno1.mes,aluno1.ano);
    	printf("\n Idade : %i",aluno1.idade);
    	printf("\n Numero da identidade : %s ",aluno1.num_ident);
    	printf("\n Nome do Responsavel : %s ",aluno1.nome_resp);
    	printf("\n Bairro de residencia : %s",aluno1.bairro);
    } /// FECHAMENTO OPCAO 2
    
int alterar()  //// ALTERAR OPCAO 3 
{
	int escolher;
	
	printf("\n Para Alterar... Digite.....\n"); // MENU ALTERAR 
        printf("\n +-----------------------------------+");
		printf("\n |     Alterar    Registros          | ");
		printf("\n +-----------------------------------+");
		printf("\n |   Nome Aluno      |   1           | ");
		printf("\n |           CPF     |   2           | ");	
	    printf("\n |  Numero Identidade|   3           | ");
		printf("\n |  Dia  Nascimento  |   4           | ");
	    printf("\n |  Mes  Nascimento  |   5           | ");
	    printf("\n |  Ano  Nascimento  |   6           | ");
		printf("\n |  Nome Responsavel |   7           | ");
		printf("\n |  Bairro Residencia|   8           | ");
		printf("\n +-----------------------------------+");
		
		printf("\n Digite...:");
		scanf("%i",&escolher);
		
	        switch(escolher) // CASE ALTERAR
	    {

   	              case 1:
   	                 printf("\n Alterar Nome do aluno \n");	
   	               printf("\n Digite o novo nome  ...:");
   	              setbuf(stdin, NULL);
   	               gets(aluno1.nome_aluno);
	                break;
	             case 2:
   	                 printf("\n Alterar o CPF \n");
	               printf("\n Digite o novo CPF...:");
	               setbuf(stdin,NULL);
				   gets(aluno1.num_cpf);
	               break;
	    	    case 3:
   	                 printf("\n Alterar o numero da identidade \n");
                     printf("\n Digite o novo  numero da Identidade ...:");
	                 setbuf(stdin,NULL);
				     gets(aluno1.num_ident);
				   	break;              
				case 4:
   	                 printf("\n Alterar o dia de nascimento \n");    
	                 printf("\n Digite o novo  numero do dia de nascimento ...:");
					 scanf("%i",&aluno1.dia);
	                setbuf(stdin, NULL);
	               break;
	           case 5:
   	                printf("\n Alterar mes de nascimento \n");
	                printf("\n Digite o novo  numero do mes de nascimento ...:");
	                scanf("%i",&aluno1.mes);
	                setbuf(stdin, NULL);
	               break;
	          case 6:
   	                printf("\n Alterar ano de nascimento \n");
	                printf("\n Digite o novo numero do ano de nascimento ...:");
	                scanf("%i",&aluno1.ano);
	                setbuf(stdin, NULL);
                    break;
			case 7:
   	                 printf("\n Alterar Nome do Responsavél \n");	 
	                 printf("\n Digite o novo nome do responsavél ...:");
	                 setbuf(stdin, NULL);
					 scanf("%30[^\n]", aluno1.nome_resp);
	                 break;
            case 8:
   	                 printf("\n Alterar Bairro Residencial  \n");
					  printf("\n Digite o novo  bairro de residencia do aluno ....:");
	                  gets(aluno1.bairro);
					  	break;
		             	
        }	// FIM CASE ALTERAR

} // FIM FUNCAO 3 ALTERAR 

int calcularidade() /// FUNCAO CALCULAR IDADE 
    {
    	 aluno1.idade = ( anodia- aluno1.ano) ; 
    }

int main()
{  

    time_t mytime; /// CODIGO ANO BISEXTO 
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    printf("Data: %d/%d/%d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
    
     datadia = tm.tm_mday;
     mesdia = tm.tm_mon + 1;
     anodia = tm.tm_year + 1900;  /// CODIGO DATA DO COMPUTADOR 
                                  
    if (anodia % 4 == 0) /// CODIGO ANO BISEXTO 
    { ano[1]= 29;	
    }

int opcao;
     
     do{
     
     
    printf("\n +-----------------------------------+");
	printf("\n |   Programa de Cadastro de Alunos  | ");
	printf("\n +-----------------------------------+");
	printf("\n |   1-Inserir Aluno                 |");
	printf("\n |   2-Visualizar Aluno              |");
	printf("\n |   3-Alterar registro Aluno        |");
    printf("\n |   4-Sair do programa              |");
	printf("\n +-----------------------------------+");
	
	printf("\n Escolha uma opcao...:");
	scanf("%i",&opcao);
	
	switch  (opcao)  /// CASE MENU PRINCIPAL 
	{
		case 1:
		inserir();
		calcularidade();//CHAMADA PARA A FUNCAO CALCULAR IDADE
		printf("\n\n Cadastro Concluido com sucesso!\n");
		break;
		
		case 2:
			visualizar();
			break;
		
		case 3:
		    alterar();
		    printf("\n Operaçoes concluidas com sucesso \n");
			break;
				
		 case 4:
			    opcao = 24;
           	     printf ("\n\n Saindo do programa\n\n");
           	    break;
           	    
		    default:
			   printf ("\n\n Opcao invalida - Preste atencao no que faz\n\n");
			   opcao = 13;	
			   break;	
	}
	
     }while ( (opcao > 0 ) && (opcao <= 3));
	system("pause");
	return 0;
}

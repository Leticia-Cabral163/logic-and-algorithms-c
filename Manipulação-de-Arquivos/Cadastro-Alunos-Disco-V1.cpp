// Exercicio Cadastro Aluno em Disco
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h> // biblioteca tempo 
#include <math.h>

	char frase[400];// guardar dados no arq
	
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
int anobisexto; // Variaveis correcao data 

    int datadia ;
    int mesdia ; /// variaveis data atual 
    int anodia;
    
   
  
  int inserir() // FUNCAO INSERIR 1 
   {  
           setbuf(stdin, NULL);
		FILE*Apontar; //variavel ponteiro tipo FILE
	              // ponteiro que aponta para o tipo FILE C:\Users\CEDUP16\Desktop\Leticia cabral\CEDUP\TEI\Linguagem prog
		Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\AlunosArquivo","a");
		
		if(Apontar==NULL)
		  {
			printf("\n\n Arquivo nao encontrado \n\n");
		    system("pause");
		    return 0;	
		   }

		
   	 printf("\n Inserir um aluno");  
   	 printf("\n Digite o numero- da matricula ...:");
   	 gets(aluno1.num_mat);
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
	 gets( aluno1.dia);
     fputs(aluno1.dia,Apontar);
	 printf("\n Digite o numero do mes de nascimento do aluno ...:");
	 gets(aluno1.mes);
	 fputs(aluno1.mes,Apontar);
	 printf("\n Digite o numero do ano de nascimento do aluno ...:");
	 gets(aluno1.ano);
	 fputs(aluno1.ano,Apontar);
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
	 gets( aluno1. nome_resp);
     fputs(aluno1.nome_resp,Apontar);
	 setbuf(stdin, NULL);
	 
	 printf("\n Digite o bairro de residencia do aluno ....:");
	 gets(aluno1.bairro);
     fputs(aluno1.bairro,Apontar);
	 
	     	 aluno1.idade = ( anodia- aluno1.ano) ; // calc idade
	 
	 fclose(Apontar);
	 
   } /// FINAL OPCAO 1 INSERIR aluno
   
    
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
        
salvararquivo(){ // opcao 1 salvar o arquivo no doc
	fprintf("\n         Cadastro do aluno ");
    	fprintf("\n Matricula : %i",aluno1.num_mat);
    	fprintf("\n Nome do aluno : %s",aluno1.nome_aluno);
    	fprintf("\n CPF : %s ",aluno1.num_cpf);
    	fprintf("\n Data de Nascimento %i/%i/%i  ",aluno1.dia,aluno1.mes,aluno1.ano);
    	fprintf("\n Idade : %i",aluno1.idade);
    	fprintf("\n Numero da identidade : %s ",aluno1.num_ident);
    	fprintf("\n Nome do Responsavel : %s ",aluno1.nome_resp);
    	fprintf("\n Bairro de residencia : %s",aluno1.bairro);
}


int visualizar_td() // função para ler o arquivo 2
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

	    while(fgets(frase, 400, Apontar) != NULL)
        printf("%s", frase);
		
		fclose(Apontar); //fechar e salvar arquivo 
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
	printf("\n |   1-Inserir Novo Aluno            |");
	printf("\n |   2-Visualizar Todos os Alunos    |");
	printf("\n |   3-Visualizar Aluno              |");
    printf("\n |   4-Sair do programa              |");
	printf("\n +-----------------------------------+");
	
	printf("\n Escolha uma opcao...:");
	scanf("%i",&opcao);
	
	switch  (opcao)  /// CASE MENU PRINCIPAL 
	{
		case 1:
		inserir();
		salvararquivo();
		printf("\n\n Cadastro Concluido com sucesso!\n");
		break;
		
		case 2:
			visualizar_td();
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
	
     }while ( (opcao > 0 ) && (opcao <= 5));
	system("pause");
	return 0;
}





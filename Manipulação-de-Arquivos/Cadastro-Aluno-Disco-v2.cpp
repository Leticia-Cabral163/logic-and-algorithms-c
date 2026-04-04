// Exercicio Cadastro Aluno em Disco 2 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h> // biblioteca tempo 
#include <math.h>

	char frase[400];// guardar dados no arq
	char mataaluno[5];
   struct {   //STRUCT CADASTRO ALUNO 
     int	num_mat[20];
     char	nome_aluno[30];
     char num_cpf[16];
	 char num_ident[11];
	 int dia;
	 int mes;
	 int ano;
	 int idade;
	 char nome_resp[30];
	 char bairro[30];
    }aluno1;

 int ano[13] {00,31,28,31,30,31,30,31,31,30,31,30,31 }; // VETOR ANO 
//            0, 1 , 2 ,3, 4, 5, 6, 7, 8, 9,10,11,12
int validar; 
int resul;
int anobisexto; // Variaveis correcao data 

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
  
  int inserir() // FUNCAO INSERIR ALUNO 
   {  
		 setbuf(stdin, NULL);
   	 printf("\n Inserir um aluno");
		  
   	 printf("\n Digite o numero- da matricula ...:");
    scanf("%i", &aluno1.num_mat);
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
	 scanf("%i", &aluno1.dia);
	 printf("\n Digite o numero do mes de nascimento do aluno ...:");
	 scanf("%i", &aluno1.mes);
	 printf("\n Digite o numero do ano de nascimento do aluno ...:");
	 scanf("%i", &aluno1.ano);
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
	 setbuf(stdin, NULL);
	 
	 printf("\n Digite o bairro de residencia do aluno ....:");
	 gets(aluno1.bairro);
	 
	     	 aluno1.idade = ( anodia- aluno1.ano) ; // calc idade
	 

   } /// FINAL OPCAO 1 INSERIR aluno
   
    

        
 int salvararquivo() // FUNÇÃO SALVAR ARQUIVO
 { 
			setbuf(stdin, NULL);
		FILE*Apontar; //variavel ponteiro tipo FILE
	              // ponteiro que aponta para o tipo FILE C:\Users\CEDUP16\Desktop\Leticia cabral\CEDUP\TEI\Linguagem prog
		Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\AlunosArquivoVersão2","a");
		
		if(Apontar==NULL)
		  {
			printf("\n\n Arquivo nao encontrado \n\n");
		    system("pause");
		    return 0;	
		   }
		   
		//   contador ++;
	    //fprintf( Apontar,"\n   %i",contador);
    	fprintf(Apontar,"\n  %i",aluno1.num_mat);
    	fprintf(Apontar," %s",aluno1.nome_aluno);
    	fprintf(Apontar," %s ",aluno1.num_cpf);
    	fprintf(Apontar," %i/%i/%i  ",aluno1.dia,aluno1.mes,aluno1.ano);
    	fprintf(Apontar," %i",aluno1.idade);
    	fprintf(Apontar,"  %s ",aluno1.num_ident);
    	fprintf(Apontar," %s ",aluno1.nome_resp);
    	fprintf(Apontar," %s",aluno1.bairro);
    	
  
	fclose(Apontar);
}


int visualizar_td() // função para ler o arquivo 2
{
	    setbuf(stdin, NULL);
		FILE*Apontar; //variavel ponteiro tipo FILE
	              // ponteiro que aponta para o tipo FILE C:\Users\CEDUP16\Desktop\Leticia cabral\CEDUP\TEI\Linguagem prog
		Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\AlunosArquivoVersão2","r");
		
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
int visualizar_al() // função para ler aluno especifico 
{
	
	printf("\n Visualizar Aluno");
	printf("\n Digite a Matricula do Aluno ...:");
	scanf("%s",&mataaluno);
	
	    setbuf(stdin, NULL);
		FILE*Apontar; //variavel ponteiro tipo FILE
	              // ponteiro que aponta para o tipo FILE C:\Users\CEDUP16\Desktop\Leticia cabral\CEDUP\TEI\Linguagem prog
		Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\AlunosArquivoVersão2","r");
		
		if(Apontar==NULL)
		  {
			printf("\n\n Arquivo nao encontrado \n\n");
		    system("pause");
		    return 0;	
		   }

        // Lê cada linha e carrega a struct
    while (fgets(frase, sizeof(frase), Apontar) != NULL) {
        // Extrai os dados da linha
        if (sscanf(frase, " %i %s %s %i/%i/%i  %i %s  %s %s", aluno1.num_mat, &aluno1.nome_aluno, &aluno1.num_cpf,
		&aluno1.dia,&aluno1.mes,&aluno1.ano,&aluno1.idade,&aluno1.num_ident,&aluno1.nome_resp,&aluno1.bairro) == 3) {
            // Atribui os dados à struct
            printf("\n Cadastro do aluno  %i \n Matricula : %i \n Nome do aluno : %s \n CPF : %s  \n Data de Nascimento %i/%i/%i  \n Idade : %i \n Numero da identidade : %s \n Nome do Responsavel : %s  \n Bairro de residencia : %s \n ",&aluno1.num_mat, &aluno1.nome_aluno, &aluno1.num_cpf,
		&aluno1.dia,&aluno1.mes,&aluno1.ano,&aluno1.idade,&aluno1.num_ident,&aluno1.nome_resp,&aluno1.bairro );
        } else {
            printf("Erro ao ler os dados da linha: %s\n", frase);
        }
    }
	    
		fclose(Apontar); //fechar e salvar arquivo 
	
}
int excluirtodos() // finção excluir
{
	FILE*Apontar; //variavel ponteiro tipo FILE
	              // ponteiro que aponta para o tipo FILE C:\Users\CEDUP16\Desktop\Leticia cabral\CEDUP\TEI\Linguagem prog
		Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\AlunosArquivoVersão2","w");
		
		if(Apontar==NULL)
		  {
			printf("\n\n Arquivo nao encontrado \n\n");
		    system("pause");
		    return 0;	
		   }
		   printf("\n\n Registros excluido com sucesso! \n\n");
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
    { ano[2]= 29;	
    }

int opcao; ///  Main principal
     
  do{
     
    printf("\n +-----------------------------------+");
	printf("\n |   Programa de Cadastro de Alunos 2| ");
	printf("\n +-----------------------------------+");
	printf("\n |   1-Inserir Novo Aluno            |");
	printf("\n |   2-Visualizar Todos os Alunos    |");
	printf("\n |   3-Visualizar Aluno Especifíco   |");
	printf("\n |   4-Limpar e Excluir Cadastros    |");
    printf("\n |   5-Sair do programa              |");
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
		      visualizar_al();
		    printf("\n Operaçoes concluidas com sucesso \n");
			break;
				
		 case 4:
			    printf("\n Deseja mesmo Excluir TODOS os registros do arquivo de forma PERMANENTE ?");
			    int resp;
           	    printf("\n 1|SIM ");
				printf("\n 2|NÃO ");
				scanf("%i",&resp);
				  if(resp == 1)
				    {
				         excluirtodos();	
				    }
                 else 
                    {
                    	printf("\n Então cuide aonde clica para não fazer cagada !");
                    }
           	    break;

		 case 5:
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





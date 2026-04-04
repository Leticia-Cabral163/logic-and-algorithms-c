
// Exercicio Cadastro Aluno em Disco 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // biblioteca tempo
#include <math.h>

char frase[400]; // guardar dados no arq
char mataaluno[5];

struct {    //STRUCT CADASTRO ALUNO
    char    num_mat[5];
    char    nome_aluno[30];
    char num_cpf[16];
    char num_ident[11];
    char dia[3];   // Espaço para o '\0'
    char mes[3];   // Espaço para o '\0'
    char ano[5];   // Espaço para o '\0'
    char idade[3]; // Espaço para o '\0'
    char nome_resp[30];
    char bairro[30];
} aluno1;


int datadia;
int mesdia; /// variaveis data atual
int anodia;



int inserir() // FUNCAO INSERIR ALUNO
{
    setbuf(stdin, NULL);
    printf("\n Inserir um aluno");

    printf("\n Digite o numero- da matricula ...:");
    scanf("%4s", aluno1.num_mat); // Limitando a leitura para evitar buffer overflow
    setbuf(stdin, NULL);

    printf("\n Digite o nome do aluno ...:");
    fgets(aluno1.nome_aluno, sizeof(aluno1.nome_aluno), stdin); //garante que não seja lido mais dados do que o maximo.
    aluno1.nome_aluno[strcspn(aluno1.nome_aluno, "\n")] = 0; // Remover newline
    setbuf(stdin, NULL);

    printf("\n Digite o numero do Cpf do aluno...:");
    fgets(aluno1.num_cpf, sizeof(aluno1.num_cpf), stdin);
    aluno1.num_cpf[strcspn(aluno1.num_cpf, "\n")] = 0; // Remover newline
    setbuf(stdin,NULL);

    printf("\n Digite o numero da Identidade do aluno...:");
    fgets(aluno1.num_ident, sizeof(aluno1.num_ident), stdin);
    aluno1.num_ident[strcspn(aluno1.num_ident, "\n")] = 0; // Remover newline
    setbuf(stdin,NULL);

    printf("\n Digite o numero do dia de nascimento do aluno...:");
    scanf("%2s", aluno1.dia);
    printf("\n Digite o numero do mes de nascimento do aluno ...:");
    scanf("%2s", aluno1.mes);
    printf("\n Digite o numero do ano de nascimento do aluno ...:");
    scanf("%4s", aluno1.ano);
    setbuf(stdin, NULL);

    printf("\n Digite o nome do responsavel do aluno ...:");
    fgets(aluno1.nome_resp, sizeof(aluno1.nome_resp), stdin);
    aluno1.nome_resp[strcspn(aluno1.nome_resp, "\n")] = 0; // Remover newline
    setbuf(stdin, NULL);
setbuf(stdin, NULL);

    printf("\n Digite o bairro de residencia do aluno ....:");
    fgets(aluno1.bairro, sizeof(aluno1.bairro), stdin);
    aluno1.bairro[strcspn(aluno1.bairro, "\n")] = 0; // Remover newline
    setbuf(stdin, NULL);

    printf("\n Digite a idade do aluno ...:");
    scanf("%2s", aluno1.idade);
    setbuf(stdin, NULL);

    // aluno1.idade = ( anodia- aluno1.ano) ; // calc idade

} /// FINAL OPCAO 1 INSERIR aluno


int salvararquivo() // FUNÇÃO SALVAR ARQUIVO
{
    setbuf(stdin, NULL);
    FILE*Apontar; //variavel ponteiro tipo FILE
                    // ponteiro que aponta para o tipo FILE C:\Users\CEDUP16\Desktop\Leticia cabral\CEDUP\TEI\Linguagem prog
    Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\CadAlunoV3","a");
//  Apontar = fopen("E:\\Aulas - 2025\\Cedup\\Tumras\\Segundo\\Linguagem\\CadAlunos","a");

    if(Apontar==NULL)
    {
        printf("\n\n Arquivo nao encontrado \n\n");
        system("pause");
        return 0;
    }
    //  contador ++;
    //fprintf( Apontar,"\n  %i",contador);
    fprintf(Apontar,"\n %s %s %s %s %s %s %s %s %s %s",
            aluno1.num_mat,
            aluno1.nome_aluno,
            aluno1.num_cpf,
            aluno1.num_ident,
            aluno1.dia,
            aluno1.mes,
            aluno1.ano,
            aluno1.idade,
            aluno1.nome_resp,
            aluno1.bairro);


    fclose(Apontar);
    return 1; // Indica sucesso ao salvar
}


int visualizar_td() // função para ler o arquivo 2
{
    setbuf(stdin, NULL);
    FILE*Apontar; //variavel ponteiro tipo FILE
                    // ponteiro que aponta para o tipo FILE C:\Users\CEDUP16\Desktop\Leticia cabral\CEDUP\TEI\Linguagem prog
    Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\CadAlunoV3","r");

//  Apontar = fopen("E:\\Aulas - 2025\\Cedup\\Tumras\\Segundo\\Linguagem\\CadAlunos","r");

    if(Apontar==NULL)
    {
        printf("\n\n Arquivo nao encontrado \n\n");
        system("pause");
        return 0;
    }



    while(fgets(frase, 400, Apontar) != NULL) {
            printf(" %s", frase);
      }


    fclose(Apontar); //fechar e salvar arquivo
    return 0; // Indica sucesso
}

int visualizar_al() // função para ler aluno especifico
{
    printf("\n Visualizar Aluno");
    printf("\n Digite a Matricula do Aluno ...:");
    scanf("%4s",mataaluno); 
    setbuf(stdin, NULL);

    FILE*Apontar; //variavel ponteiro tipo FILE
                    // ponteiro que aponta para o tipo FILE C:\Users\CEDUP16\Desktop\Leticia cabral\CEDUP\TEI\Linguagem prog
    Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\CadAlunoV3","r");

    if(Apontar==NULL)
    {
        printf("\n\n Arquivo nao encontrado \n\n");
        system("pause");
        return 0;
    }

    int encontrado = 0;
    //char num_mat_aux[5], nome_aluno[30], num_cpf[16], num_ident[11], dia[3], mes[3], ano[5], idade[3], nome_resp[30], bairro[30];

    while (fgets(frase, sizeof(frase), Apontar) != NULL) {
        if (sscanf(frase, "%s %s %s %s %s %s %s %s %s %s",
                    aluno1.num_mat,
            aluno1.nome_aluno,
            aluno1.num_cpf,
            aluno1.num_ident,
            aluno1.dia,
            aluno1.mes,
            aluno1.ano,
            aluno1.idade,
            aluno1.nome_resp,
            aluno1.bairro
                   ) == 10) {
            if (strcmp(aluno1.num_mat, mataaluno) == 0) {
                printf("\n+------------------------- Cadastro do Aluno -------------------------+\n");
                printf("| Matricula: %s |\n", aluno1.num_mat);
                printf("| Nome do Aluno: %-s |\n", aluno1.nome_aluno);
                printf("| CPF: %s |\n", aluno1.num_cpf );
                printf("| Numero da identidade: %s |\n",aluno1.num_ident);
                printf("| Data de Nascimento: %s/%s/%s                  |\n",aluno1.dia,aluno1.mes,aluno1.ano);
                printf("| Idade: %s |\n",aluno1.idade);
                printf("| Nome do Responsavel: %-s |\n",aluno1.nome_resp);
                printf("| Bairro de residencia: %s |\n",aluno1.bairro);
                printf("+---------------------------------------------------------------------+\n");
                encontrado = 1;
                break; // Encontrou o aluno, pode sair do loop
            }
        } else {
            printf("Erro ao ler linha do arquivo: %s", frase);
        }
    }

    if (!encontrado) {
        printf("\nAluno com matricula '%s' nao encontrado.\n", mataaluno);
    }

    fclose(Apontar); //fechar e salvar arquivo
    return encontrado; // Indica se o aluno foi encontrado
}

int excluirtodos() // finção excluir
{
    FILE*Apontar; 
    Apontar= fopen("C:\\Users\\CEDUP16\\Desktop\\Leticia cabral\\CEDUP\\TEI\\Linguagem prog\\CadAlunoV3","w");

    if(Apontar==NULL)
    {
        printf("\n\n Arquivo nao encontrado \n\n");
        system("pause");
        return 0;
    }
    fprintf(Apontar, ""); // Escreve uma string vazia para limpar o arquivo
    fclose(Apontar);
    printf("\n\n Registros excluidos com sucesso! \n\n");
    return 1; // Indica sucesso
}

int main()
{
    time_t mytime; 
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    printf("Data: %d/%d/%d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);

    datadia = tm.tm_mday;
    mesdia = tm.tm_mon + 1;
    anodia = tm.tm_year + 1900; /// CODIGO DATA DO COMPUTADOR



    int opcao; ///  Main principal

    do{

        printf("\n +-----------------------------------+");
        printf("\n |   Programa Cdastro Alunos V4      |");
        printf("\n +-----------------------------------+");
        printf("\n |     1-Inserir Novo Aluno          |");
        printf("\n |     2-Visualizar Todos os Alunos  |");
        printf("\n |     3-Visualizar Aluno Especifico |");
        printf("\n |     4-Excluir Tudo                |");
        printf("\n |     5-Sair do programa            |");
        printf("\n +-----------------------------------+");

        printf("\n Escolha uma opcao...:");
        scanf("%i",&opcao);
        setbuf(stdin, NULL); 

        switch  (opcao)  /// CASE MENU PRINCIPAL
        {
            case 1:
                inserir();
                if (salvararquivo()) {
                    printf("\n\n Cadastro Concluido com sucesso!\n");
                } else {
                    printf("\n\n Erro ao salvar o cadastro.\n");
                }
                break;

            case 2:
                visualizar_td();
                break;

            case 3:
                visualizar_al();
                printf("\n Operacao concluida com sucesso \n");
                break;

            case 4:
                printf("\n Deseja mesmo Excluir TODOS os registros do arquivo de forma PERMANENTE ?");
                int resp;
                printf("\n 1|SIM ");
                printf("\n 2|NAO \n");
                scanf("%i",&resp);
                setbuf(stdin, NULL); // Limpar o buffer do teclado
                if(resp == 1)
                {
                    excluirtodos();
                }
                else
                {
                    printf("\n Operacao de exclusao cancelada.\n");
                }
                break;

            case 5:
                opcao = 0; // Condição para sair do loop
                printf ("\n\n Saindo do programa\n\n");
                break;

            default:
                printf ("\n\n Opcao invalida - Preste atencao no que faz\n\n");
                break;
        }

    }while (opcao != 0);

    printf("\nFim do programa.\n");
    return 0;
}




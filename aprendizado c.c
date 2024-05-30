#include <stdio.h>  //biblioteca
#include <string.h> // biblioteca responsavel poir cuidar das strings
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale

int registro()
{
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char Arquivo[40];

    printf("digite o seu cpf:\n");
    scanf("%s", cpf);

    strcpy(Arquivo, cpf);

    FILE *file;
    file = fopen(Arquivo, "w");
    fprintf(file, cpf);
    fclose(file);

    file = fopen(Arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o seu nome:\n");
    scanf("%s", nome);

    file = fopen(Arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    file = fopen(Arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o seu sobrenome:\n");
    scanf("%s", sobrenome);

    file = fopen(Arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    file = fopen(Arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o seu cargo:\n");
    scanf("%s", cargo);

    file = fopen(Arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    file = fopen(Arquivo, "a");
    fprintf(file, ".");
    fclose(file);

    system("pause");
}

int consultar()
{

    char cpf[40];
    char conteudo[200];
    char Arquivo[200];

    printf("Digite o cpf:");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Arquivo nao encontrado, nao localizado\n");
    }
    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas sao as informacoes do usuario:");
        printf("%s", conteudo);
        printf("\n\n");
    }
    system("pause");
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF a ser deletado:\n");
    scanf("%s", cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file = NULL)
    {
        printf("Usucario deletado");
        system("pause");
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int escolha = 0; // definindo variavel
    int laco = 1;

    for (laco = 1; laco = 1;)
    {

        system("cls");
        printf("\t Cartorio \n");
        printf(" Escolha as opcoes abaixo:\n");
        printf("\t 1- Registar nome:\n");
        printf("\t 2- consultar nome:\n");
        printf("\t 3- deletar nome:\n");
        printf("\t 4- Sair do sistema!\n\n");
        printf("opcao:");

        scanf("%d", &escolha); // armazenado a escolha de opçao
        system("cls");

        switch (escolha)
        {
        case 1:
            registro();
            break;

        case 2:
            consultar();
            break;

        case 3:
            deletar();
            break;
        case 4:
        printf("Obrigado por entrar no nosso site!");
        return 0;
            break;

        default:
            printf("essa opcao nao esta disponivel! tente novamente\n"); // Resposta de escolha errada!
            system("pause");
            break;
        }
    }
}
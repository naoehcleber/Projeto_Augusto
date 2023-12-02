#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structs.h"

const char* PERSON_FORMAT_OUT = "%d - (%s, %d, %d, %c)\n";
const char* PERSON_FORMAT_IN = "%d - (%[^,], %d, %d, %c)\n";

void ImprimirMenu()
{
    printf("==========MENU==========\n");
    printf("1 - Adicionar novo caso\n");
    printf("2 - Listar casos\n");
    printf("3 - Buscar um caso\n");
    printf("4 - Atualizar um caso\n");
    printf("5 - Remover um caso\n");
    printf("0 - Fechar aplicacao\n");
}

int ContarLinhasNoArquivo(const char *file)
{
    FILE* arquivo = fopen(file, "r");
    char K;
    int linhas = 0;

    if (arquivo == NULL)
    {
        return 0;
    }

    for (K = getc(arquivo); K != EOF; K = getc(arquivo))
    {
        if (K == '\n')
        {
            linhas = linhas + 1;
        }
    }
    fclose(arquivo);
    return linhas;
}

int IncrementarContador(const char* file_name)
{
    int linhas = ContarLinhasNoArquivo(file_name);
    int contador = linhas + 1;
    return contador;
}

void lerArquivo() {
    FILE *arquivo = fopen("dados.txt", "r");
    int linhas = ContarLinhasNoArquivo("dados.txt");
    for(int j =0; j < linhas; j++){
        fscanf(arquivo,PERSON_FORMAT_IN,&c[j].contador, c[j].nome, &c[j].idade, &c[j].avaliacao, &c[j].genero);
        //printf(PERSON_FORMAT_OUT, c[j].contador, c[j].nome, c[j].idade, c[j].avaliacao, c[j].genero);

    }
    fclose(arquivo);
}

void NovoRegistro()
{
    FILE* arquivo = fopen("dados.txt", "r+");
    if (arquivo == NULL)
    {
        arquivo = fopen("dados.txt", "w+");
    }
    FILE* temp = fopen("temp.txt", "w");

    int linhas = ContarLinhasNoArquivo("dados.txt");
    int j = linhas;
    int linhasTemp = ContarLinhasNoArquivo("temp.txt");
    char p;

    printf("Caso %d\n", j + 1);

    printf("Nome: ");
    fgets(c[j].nome, 50, stdin);
    c[j].nome[strcspn(c[j].nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &c[j].idade);

    printf("Digite uma nota de 0 a 10 para Joao: ");
    scanf("%d", &c[j].avaliacao);
    while (getchar() != '\n');

    printf("Genero: ");
    scanf(" %c", &c[j].genero);

    int posicao;
    printf("Deseja inserir o registro no inicio ou no final do arquivo?\n");
    printf("1 - inicio\n");
    printf("2 - final\n");
    scanf("%d", &posicao);

    switch (posicao)
    {
    case 1:
        fseek(arquivo, 0, SEEK_SET);

        c[j].contador = 1;
        fprintf(temp, PERSON_FORMAT_OUT, c[j].contador, c[j].nome, c[j].idade, c[j].avaliacao, c[j].genero);

        // loop para aumentar em 1 todos os contadores do arquivo original
        for (int k = 0; k < linhas; k++)
        {
            c[k].contador = k + 2;
            fprintf(temp, PERSON_FORMAT_OUT, c[k].contador, c[k].nome, c[k].idade, c[k].avaliacao, c[k].genero);
        }

        fclose(temp);  // Fecha o arquivo temporário após a escrita

        temp = fopen("temp.txt", "r");  // Reabre o arquivo temporário para leitura

        // Copia o conteúdo do arquivo temporário para o arquivo original
        while ((p = fgetc(temp)) != EOF)
        {
            fputc(p, arquivo);
        }

        fclose(temp);
        break;

    case 2:
        fseek(arquivo, 0, SEEK_END);

        c[j].contador = IncrementarContador("dados.txt");
        fprintf(arquivo, PERSON_FORMAT_OUT, c[j].contador, c[j].nome, c[j].idade, c[j].avaliacao, c[j].genero);
        break;
    }

    fclose(arquivo);
}


void ListarRegistros()
{
    FILE* arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo para leitura.\n");
        return;
    }

    int qual;
    int linhaAtual;
    char buffer[256];
    char bufferULTIMAS[5][256];
    int index = 0;
    int totalLinhas = 0;

    printf("1- Ler os 5 primeiros casos\n");
    printf("2- Ler os 5 ultimos casos\n");
    printf("3- Ler TODOS os casos\n");
    scanf("%d", &qual);

    switch (qual)
    {
    case 1:
        linhaAtual = 0;
        while (linhaAtual < 5 && fgets(buffer, sizeof(buffer), arquivo) != NULL)
        {
            printf("%s", buffer);
            linhaAtual++;
        }
        break;

    case 2:
        while (fgets(bufferULTIMAS[index], sizeof(bufferULTIMAS[index]), arquivo) != NULL)
        {
            index = (index + 1) % 5;
            totalLinhas++;
        }

        for (int i = 0; i < 5 && i < totalLinhas; i++)
        {
            printf("%s", bufferULTIMAS[index]);
            index = (index + 1) % 5;
        }
        break;

    case 3:
        while ((fgets(buffer, sizeof(buffer), arquivo)) != NULL)
        {
            printf("%s", buffer);
        }
        break;

    default:
        printf("\nOpcao invalida.\n");
        break;
    }

    fclose(arquivo);
}

void BuscarRegistro()
{
    FILE* arquivo = fopen("dados.txt", "r+");
    int linhas = ContarLinhasNoArquivo("dados.txt");
    lerArquivo();


    if (arquivo == NULL)
    {
        printf("\nNão foi possível abrir o arquivo para busca.\n");
        return;
    }

    int encontrado = 0;

    int numRegistro;

    printf("Insira o numero do caso: ");
    scanf("%d", &numRegistro);

    for (int i = 0; i < linhas; i++)
    {
        if (numRegistro == c[i].contador)
        {
            printf("Caso encontrado!\n");
            printf(PERSON_FORMAT_OUT, c[i].contador, c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero);
            encontrado++;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Nenhum registro encontrado com esse numero.\n");
    }

    fclose(arquivo);
    }

void AtualizarRegistro()
{
    FILE* arquivo = fopen("dados.txt", "r+");
    if (arquivo == NULL)
    {
        printf("\nNao foi possivel abrir o arquivo para atualizacao.\n");
        return;
    }

    int linhas = ContarLinhasNoArquivo("dados.txt");
    int numRegistro, encontrado = 0;
    printf("Insira o numero do caso a ser atualizado: ");
    scanf("%d", &numRegistro);
    while (getchar() != '\n');

    for (int i = 0; i < linhas; i++)
    {
        if (numRegistro == c[i].contador)
        {
            printf("Caso encontrado. Insira os novos dados:\n");

            printf("Nome: ");
            fgets(c[i].nome, 50, stdin);
            c[i].nome[strcspn(c[i].nome, "\n")] = '\0';
            

            printf("Idade: ");
            scanf("%d", &c[i].idade);
            while (getchar() != '\n');


            printf("Digite uma nota de 0 a 10 para Joao: ");
            scanf("%d", &c[i].avaliacao);

            while (getchar() != '\n');

            printf("Genero: ");
            scanf("%c", &c[i].genero);

            //achar a posicao do caso
            
            fprintf(arquivo, PERSON_FORMAT_OUT, c[i].contador, c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("\nNenhum caso encontrado com esse numero.\n");
    }

    fclose(arquivo);
}

void RemoverRegistro()
{
    FILE* arquivo = fopen("dados.txt", "r+");
    if (arquivo == NULL)
    {
        printf("\nNao foi possivel abrir o arquivo para remocao.\n");
        return;
    }

    int linhas = ContarLinhasNoArquivo("dados.txt");
    int numRegistro;
    printf("Insira o numero do caso a ser removido: ");
    scanf("%d", &numRegistro);

    FILE* temp = fopen("temp.txt", "w");

    for (int i = 0; i < linhas; i++)
    {
        if (c[i].contador != numRegistro)
        {
            fprintf(temp, PERSON_FORMAT_OUT, c[i].contador, c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero);
        }
        i++;
    }

    fclose(arquivo);
    fclose(temp);

    remove("dados.txt");
    rename("temp.txt", "dados.txt");

    printf("Caso %d removido com sucesso.\n", numRegistro);
}
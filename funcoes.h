#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structs.h"

const char* PERSON_FORMAT_OUT = "%d - (%s, %d, %d, %c)\n";
int i = 0;

void ImprimirMenu(){
    printf("1 - Adicionar novo caso\n");
    printf("2 - Listar casos\n");
    printf("3 - Buscar um caso\n");
    printf("4 - Atualizar um caso\n");
    printf("5 - Remover um caso\n");
    printf("0 - Fechar aplicacao\n");
}

int ContarLinhasNoArquivo(){
    FILE *arquivo = fopen("Caso.txt","r");
    char K;
    int linhas = 0;

    for(K = getc(arquivo); K !=EOF; K = getc(arquivo)){
        if( K == '\n'){
            linhas = linhas + 1;
        }
    }
    fclose(arquivo);
    return linhas;
}

int IncrementarContador(){
    int linhas = ContarLinhasNoArquivo();
    int contador = linhas +1;
    return contador;
}

void NovoRegistro(){
    FILE *arquivo = fopen("Caso.txt","r+");
    if(arquivo == NULL){
        arquivo = fopen("Caso.txt","w+");
    }

    int linhas = ContarLinhasNoArquivo();
    int j = linhas;
    i = 0;
    
        printf("Caso %d\n", j+1);
        printf("Nome : ");
        fgets(c[i].nome,50,stdin);
        //remover o '\n' do fgets
        c[i].nome[strcspn(c[i].nome,"\n")] = '\0';

        printf("Idade : ");
        scanf("%d",&c[i].idade);
        printf("Digite uma nota de 0 a 10 para Joao : ");
        scanf("%d", &c[i].avaliacao);
        while(getchar()!='\n');

        printf("Qual genero ? ");
        scanf("%c",&c[i].genero);
        

        int posicao;
        printf("Deseja inserir o registro no inicio ou no final do arquivo ?\n");
        printf("1 - inicio\n");
        printf("2 - final\n");
        scanf("%d",&posicao);

        switch(posicao){
            case 1 :
                fseek(arquivo, 0, SEEK_SET);
             
                FILE *temp = fopen("temp.txt", "w");
               
                c[i].contador = IncrementarContador();
                fprintf(temp, PERSON_FORMAT_OUT, c[i].contador, c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero);

                for (int k = 0; k < linhas; k++) {
                    fscanf(arquivo, PERSON_FORMAT_OUT, &c[k].contador, c[k].nome, &c[k].idade, &c[k].avaliacao, &c[k].genero);
                    fprintf(temp, PERSON_FORMAT_OUT, c[k].contador, c[k].nome, c[k].idade, c[k].avaliacao, c[k].genero);
                }

                fclose(arquivo);
                fclose(temp);

                remove("Caso.txt");
                rename("temp.txt", "Caso.txt");

                arquivo = fopen("Caso.txt", "r+");
                break;

            case 2 :
                fseek(arquivo, 0, SEEK_END);
          
                c[i].contador = IncrementarContador();
                fprintf(arquivo, PERSON_FORMAT_OUT, c[i].contador, c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero);

                break;
        }
        fclose(arquivo);
        i++;
    }



void ListarRegistros() {
    FILE *arquivo = fopen("Caso.txt", "r");
    if (arquivo == NULL) {
        printf("\nNao foi possivel abrir o arquivo para leitura.\n");
        return;
    }

    int qual;
    int K;
    int linhaAtual;
    char buffer[256];
    char bufferULTIMAS[5][256];
    int index = 0;
    int totalLinhas = 0;
    printf("1- Ler os 5 primeiros casos\n");
    printf("2- Ler os 5 ultimos casos\n");
    printf("3- Ler TODOS os casos\n");
    scanf("%d", &qual);

    switch (qual) {
        case 1:
            linhaAtual = 0;
            while(linhaAtual < 5 && fgets(buffer, sizeof(buffer),arquivo)!=NULL){
                printf("%s",buffer);
                linhaAtual++;
            }
            break;

        case 2:
            //ta imprimindo todos os records ao inves de os 5 ultimos apenas
            

            // Ler as últimas linhas do arquivo
            while (fgets(bufferULTIMAS[index], sizeof(bufferULTIMAS[index]), arquivo) != NULL) {
                index = (index + 1) % 5;
                totalLinhas++;
            }

            // Imprimir as últimas linhas armazenadas no buffer circular
            for (i = 0; i < 5 && i < totalLinhas; i++) {
                printf("%s", bufferULTIMAS[index]);
                index = (index + 1) % 5;
            }

            break;

        case 3:
            
            while((K = getc(arquivo)) != EOF){
                putchar(K);
                
            }
            break;

        default:
            printf("Opcao invalida.\n");
            break;
    }

    fclose(arquivo);

}


void BuscarRegistro() {
    FILE *arquivo = fopen("Caso.txt", "r");
    if (arquivo == NULL) {
        printf("\nNão foi possível abrir o arquivo para busca.\n");
        return;
    }

    int encontrado = 0;
    int linhas = ContarLinhasNoArquivo();
    int numRegistro;
    int contador = IncrementarContador();

    printf("Insira o numero do caso: ");
    scanf("%d", &numRegistro);

    for (int i = 0; i < linhas; i++) {
        if (numRegistro == c[i].contador) {
            printf("Caso encontrado\n");
            printf(PERSON_FORMAT_OUT, c[i].contador, c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero);
            encontrado++;
            break; 
        }
    }

    if (!encontrado) {
        printf("Nenhum registro encontrado com esse numero.\n");
    }

    fclose(arquivo);
}


void AtualizarRegistro() {
    FILE *arquivo = fopen("Caso.txt", "r+");
    if (arquivo == NULL) {
        printf("\nNao foi possivel abrir o arquivo para atualizacao.\n");
        return;
    }

    int numRegistro, encontrado = 0;
    printf("Insira o numero do caso a ser atualizado : ");
    scanf("%d", &numRegistro);

    for (i; fscanf(arquivo, PERSON_FORMAT_OUT, &c[i].contador, c[i].nome, &c[i].idade, &c[i].avaliacao, &c[i].genero) == 5; i++) {
        if (c[i].contador == numRegistro) {
            printf("Caso encontrado. Insira os novos Caso:\n");

            printf("Nome : ");
            fgets(c[i].nome, 50, stdin);
    
            c[i].nome[strcspn(c[i].nome, "\n")] = '\0';

            printf("Idade : ");
            scanf("%d", &c[i].idade);

            printf("Digite uma nota de 0 a 10 para Joao : ");
            scanf("%d", &c[i].avaliacao);

            while (getchar() != '\n');

            printf("Qual genero ? ");
            scanf(" %c", &c[i].genero);

            fseek(arquivo, i*sizeof(struct caso), SEEK_SET);

            fprintf(arquivo, PERSON_FORMAT_OUT, c[i].contador, c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Nenhum caso encontrado com esse numero.\n");
    }

    fclose(arquivo);
}

void RemoverRegistro() {
    FILE *arquivo = fopen("Caso.txt", "r+");
    if (arquivo == NULL) {
        printf("\nNao foi possivel abrir o arquivo para remocao.\n");
        return;
    }

    int numRegistro;
    printf("Insira o numero do caso a ser removido : ");
    scanf("%d", &numRegistro);

    FILE *temp = fopen("temp.txt", "w");
    
    while (fscanf(arquivo, PERSON_FORMAT_OUT, &c[i].contador, c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero) == 5) {
        if (c[i].contador != numRegistro) {
            fprintf(temp, PERSON_FORMAT_OUT, c[i].contador, c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("Caso.txt");
    rename("temp.txt", "Caso.txt");
}

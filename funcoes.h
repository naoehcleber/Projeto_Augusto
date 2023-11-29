#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
//define o formato em que os dados vao ser escritos 
const char* PERSON_FORMAT_OUT = "(%s, %d, %d, %c)\n";

void ImprimirMenu(){
    printf("1 - Adicionar novo registro\n");
    printf("2 - Listar registros\n");
    printf("3 - Buscar um registro\n");
    printf("4 - Atualizar um registro\n");
    printf("5 - Remover um registro\n");
    printf("0 - Fechar aplicacao\n");

}





void NovoRegistro(){
    FILE *arquivo = fopen("dados.txt","r+");
    if(arquivo == NULL){
        arquivo = fopen("dados.txt","w+");
    }



    printf("Nome : ");
    fgets(c.nome,50,stdin);
    printf("Idade : ");
    scanf("%d",&c.idade);
    printf("Digite uma nota de 0 a 10 : ");
    scanf("%d", &c.avaliacao);
    while(getchar()!='\n');

    printf("Qual genero ? ");
    scanf("%c",&c.genero);
    

    int posicao;
    printf("Deseja inserir o registro no inicio ou no final do arquivo ?\n");
    printf("1 - inicio\n");
    printf("2 - final\n");
    scanf("%d",&posicao);

    switch(posicao){
        case 1 :
            fseek(arquivo, 0, SEEK_SET);
            //imprimir no arquivo ja formatado 
            fprintf(arquivo, PERSON_FORMAT_OUT, c.nome, c.idade, c.avaliacao, c.genero);

            break;
        case 2 :
                fseek(arquivo, 0, SEEK_END);
                //imprimir no arquivo ja formatado 
                fprintf(arquivo, PERSON_FORMAT_OUT, c.nome, c.idade, c.avaliacao, c.genero);

            break;
    }
    fclose(arquivo);

}

#define PERSON_FORMAT_OUT "(%s, %d, %d, %c)\n"

void ListarRegistros() {
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("\nNão foi possível abrir o arquivo para leitura.\n");
        return;
    }

    int qual;
    char impressaoNOME[20];
    int impressaoIDADE, impressaoAVALIACAO;
    char impressaoGENERO;

    printf("1- Ler os 5 primeiros registros\n");
    printf("2- Ler os 5 últimos registros\n");
    printf("3- Ler TODOS os registros\n");
    scanf("%d", &qual);

    switch (qual) {
        case 1:
            // Code to read and print the first 5 records
            for (int i = 0; i < 5 && fscanf(arquivo, PERSON_FORMAT_OUT, impressaoNOME, &impressaoIDADE, &impressaoAVALIACAO, &impressaoGENERO) != EOF; i++) {
                printf(PERSON_FORMAT_OUT, impressaoNOME, impressaoIDADE, impressaoAVALIACAO, impressaoGENERO);
            }
            break;

        case 2:
            // Code to read and print the last 5 records
            // You need to determine the total number of records in the file and then read the last 5.
            // Implementing this requires additional code to count the total number of records.
            // Please note that this is a simplified example, and a more robust solution may be needed.
            break;

        case 3:
            // Code to read and print all records
            while (fscanf(arquivo, PERSON_FORMAT_OUT, impressaoNOME, &impressaoIDADE, &impressaoAVALIACAO, &impressaoGENERO) != EOF) {
                printf(PERSON_FORMAT_OUT, impressaoNOME, impressaoIDADE, impressaoAVALIACAO, impressaoGENERO);
            }
            break;

        default:
            printf("Opção inválida.\n");
            break;
    }

    fclose(arquivo);
}




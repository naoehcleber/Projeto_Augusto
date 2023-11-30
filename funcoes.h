#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structs.h"
//define o formato em que os dados vao ser escritos 
const char* PERSON_FORMAT_OUT = "%d - (%s, %d, %d, %c)\n";
int i = 0;

void ImprimirMenu(){
    printf("1 - Adicionar novo registro\n");
    printf("2 - Listar registros\n");
    printf("3 - Buscar um registro\n");
    printf("4 - Atualizar um registro\n");
    printf("5 - Remover um registro\n");
    printf("0 - Fechar aplicacao\n");

}



int ContarLinhasNoArquivo(){
    FILE *arquivo = fopen("dados.txt","r");
    char K;
    int linhas = 0;

    for(K = getc(arquivo); K !=EOF; K = getc(arquivo)){
        if( K == '\n'){
            linhas = linhas + 1;
        }
    }
    
    return linhas;
}

int IncrementarContador(){
    int linhas = ContarLinhasNoArquivo();
    int contador = linhas +1;
    return contador;
}



void NovoRegistro(){
    FILE *arquivo = fopen("dados.txt","r+");
    if(arquivo == NULL){
        arquivo = fopen("dados.txt","w+");
    }

    int linhas = ContarLinhasNoArquivo();
    int j = linhas;
    
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
                // fseek(arquivo, 0, SEEK_SET);
                // //imprimir no arquivo ja formatado 
                // fprintf(arquivo, PERSON_FORMAT_OUT, c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero);
                // int linhas = ContarLinhasNoArquivo;
                // int i, j, atual;
                // for(i=1; i<linhas; i++){
                //     atual = c[i];
                //     j = i-1;
                //     while(j>=0 && c[j]>atual){
                //         c[j+1] = c[j];
                //         j = j-1;
                //     }
                //     c[j+1] = atual;
                // }
                    
                // }

                break;
            case 2 :
                fseek(arquivo, 0, SEEK_END);
                //imprimir no arquivo ja formatado
                linhas = c[i].contador; 
                fprintf(arquivo, PERSON_FORMAT_OUT, c[j].contador, c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero);

                break;
        }
        fclose(arquivo);
        i++;
    }



void ListarRegistros() {
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("\nNão foi possível abrir o arquivo para leitura.\n");
        return;
    }

    int qual;
    int K;
    int linhas;

    printf("1- Ler os 5 primeiros registros\n");
    printf("2- Ler os 5 ultimos registros\n");
    printf("3- Ler TODOS os registros\n");
    scanf("%d", &qual);

    switch (qual) {
        case 1:
            
            for(int i = 0; i< 5; i++){
                while((K = getc(arquivo)) != EOF){
                    putchar(K);
                }
            }
            break;

        case 2:
            //ta imprimindo todos os records ao inves de os 5 ultimos apenas
            linhas = ContarLinhasNoArquivo();
            for(int i = linhas; i> linhas-5; i--){
                while((K = getc(arquivo)) != EOF){
                    putchar(K);
                }
            }
            break;

        case 3:
            
            while((K = getc(arquivo)) != EOF){
                putchar(K);
                
            }
            break;

        default:
            printf("Opção inválida.\n");
            break;
    }

    fclose(arquivo);

}


void BuscarRegistro(){
    FILE *arquivo = fopen("dados.txt", "r");
    int i, numRegistro, encontrado = 0;

    printf("Insira o numero de registro a ser buscado : ");
    scanf("%d", &numRegistro);

    while(fread(&c, sizeof(c), 1, arquivo) == 1){
        if(c[i].contador == numRegistro){
            encontrado = 1;
            printf("(%s, %d, %d, %c, %d)\n", c[i].nome, c[i].idade, c[i].avaliacao, c[i].genero, c[i].contador);
            break;
        }
    }
    if(!encontrado){
        ("Nenhum caso encontrado com esse registro.");
    }

    fclose(arquivo);
}

void AtualizarRegistro(){
    FILE *arquivo = fopen("dados.txt", "w");
    int i, numRegistro, encontrado = 0;

    printf("Insira o numero de registro a ser atualizado : ");
    scanf("%d", &numRegistro);
    
    
}
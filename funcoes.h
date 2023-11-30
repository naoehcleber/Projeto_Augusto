#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
    //remover o '\n' do fgets
    c.nome[strcspn(c.nome,"\n")] = '\0';

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

void AdicionarContador(){
    FILE *arquivo = fopen("dados.txt","r+");
    FILE *arquivoTEMP = fopen("dadosTEMP.txt", "w+");
    
    int current_line = 1;
    int linhas = ContarLinhasNoArquivo();
    char buffer[linhas];
    while(fgets(buffer,sizeof(buffer),arquivo) != NULL){
        fprintf(arquivoTEMP, "%d - (%s)", current_line, buffer);
        c.contador = current_line;
        current_line++;
    }
    fclose(arquivoTEMP);
    fclose(arquivo);

    remove("dados.txt");
    rename("dadosTEMP.txt", "dados.txt");
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
        if(c.contador == numRegistro){
            encontrado = 1;
            printf("(%s, %d, %d, %c, %d)\n", c.nome, c.idade, c.avaliacao, c.genero, c.contador);
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
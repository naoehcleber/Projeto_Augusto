#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "funcoes.h"

const char* PERSON_FORMAT_OUT = "(%s, %d, %d, %c)\n";

void main(){
    struct caso c;

    FILE *arquivo = fopen("dados.txt", "w+");

    while(1){
        int escolha;


        //menu
        ImprimirMenu();
        scanf("%d", &escolha);
        while(getchar()!= '\n');

        switch (escolha){
        case 1:
            NovoRegistro();
            fprintf(arquivo, PERSON_FORMAT_OUT, c.nome, c.idade, c.avaliacao, c.genero);
            fseek(arquivo, 0, SEEK_SET);

            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 0:
            break;
        }
    }

    //fechar arquivo
    fclose(arquivo);


}
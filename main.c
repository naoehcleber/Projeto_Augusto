#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

//const char* PERSON_FORMAT_OUT = "(%s, %d, %d, %c)\n";

void main(){
    //struct caso c;

    FILE *arquivo = fopen("dados.txt", "r+");

    while(1){
        int escolha;


        //menu
        ImprimirMenu();
        scanf("%d", &escolha);
        while(getchar()!= '\n');

        switch (escolha){
        case 1:
            NovoRegistro();
            break;
        case 2:
            AdicionarContador();
            ListarRegistros();
            break;
        case 3:
            BuscarRegistro();
            break;
        case 4:
            AtualizarRegistro();
            //AtualizarRegistro();
            break;
        case 5:
            //RemoverRegistro();
            break;
        case 0:
            exit(0);
            break;
        }
    }

    //fechar arquivo
    fclose(arquivo);


}
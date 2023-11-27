#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "funcoes.h"

void main(){
    struct caso c[50];

    while(1){
        int escolha;
        //menu
        ImprimirMenu();
        scanf("%d", &escolha);
        while(getchar()!= '\n');

        switch (escolha){
        case 1:
            /* code */
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


}
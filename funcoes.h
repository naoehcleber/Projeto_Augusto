#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void ImprimirMenu(){
    printf("1 - Adicionar novo registro\n");
    printf("2 - Listar registros\n");
    printf("3 - Buscar um registro\n");
    printf("4 - Atualizar um registro\n");
    printf("5 - Remover um registro\n");
    printf("0 - Fechar aplicacao\n");

}

void AdcInicio(){

}

void AdcFinal(){
    
}




void NovoRegistro(){
    printf("Nome : ");
    fgets(c.nome,50,stdin);
    printf("Idade : ");
    scanf("%d",&c.idade);
    printf("Digite uma nota de 0 a 10 : ");
    scanf("%d", &c.avaliacao);
    printf("Qual genero ? ");
    scanf("%c",&c.genero);
    

    int posicao;
    printf("Deseja inserir o registro no inicio ou no final do arquivo ?\n");
    printf("1 - inicio\n");
    printf("2 - final\n");
    scanf("%d",&posicao);

    switch(posicao){
        case 1 :
            break;
        case 2 :
            AdcFinal();
            break;
    }

}
const char* PERSON_FORMAT_OUT = "(%s, %d, %d, %c)\n";

void AdcFile(){
}
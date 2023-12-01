#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    FILE* arquivo = fopen("dados.txt", "r+");

    while (1)
    {
        int escolha;

        ImprimirMenu();
        scanf("%d", &escolha);
        while (getchar() != '\n');

        switch (escolha)
        {
        case 1:
            NovoRegistro();
            break;
        case 2:
            ListarRegistros();
            break;
        case 3:
            BuscarRegistro();
            break;
        case 4:
            AtualizarRegistro();
            break;
        case 5:
            RemoverRegistro();
            break;
        case 0:
            exit(0);
            break;
        }
    }

    fclose(arquivo);
    return 0;
}

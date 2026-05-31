#include <stdio.h>

int main(void)
{
    int N;

    do
    {
        printf("\ninforme o tamanho do quadrado espiral: ");
        scanf("%d", &N);

        if (N <= 2)
        {
            printf("\nnúmero inválido | informe um número maior ou igual a 3\n");
            continue;
        }
        break;
    } while (1);

    int matriz[N][N];
    int valor = 1;

    int linha_inicial = 0;
    int linha_final = N - 1;
    int coluna_inicial = 0;
    int coluna_final = N - 1;

    while (valor <= N * N)
    {
        for (int i = coluna_inicial; i <= coluna_final; i++)
        {
            matriz[linha_inicial][i] = valor;
            valor++;
        }
        linha_inicial++;

        for (int i = linha_inicial; i <= linha_final; i++)
        {
            matriz[i][coluna_final] = valor;
            valor++;
        }
        coluna_final--;

        for (int i = coluna_final; i >= coluna_inicial; i--)
        {
            matriz[linha_final][i] = valor;
            valor++;
        }
        linha_final--;

        for (int i = linha_final; i >= linha_inicial; i--)
        {
            matriz[i][coluna_inicial] = valor;
            valor++;
        }
        coluna_inicial++;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
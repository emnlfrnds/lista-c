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
    int ultimo_valor = N * N;

    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            matriz[i][j] = valor;
            valor++;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
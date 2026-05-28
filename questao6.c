#include <stdio.h>

int main(void)
{
    int B, L, A;

    do
    {
        printf("\ninforme o valor de B:\n");
        scanf("%d", &B);

        if (B % 2 == 0 || B <= 4)
        {
            printf("\nvalor inválido | tente um valor ímpar e maior ou igual a 5\n");
            continue;
        }

        printf("\ninforme o valor de L:\n");
        scanf("%d", &L);

        if (L <= 0 || L % 2 == 0 || L > (B / 2))
        {
            printf("\nvalor inválido | tente um valor ímpar e menor ou igual a %d\n", (B / 2));
            continue;
        }

        printf("\ninforme o valor de A:\n");
        scanf("%d", &A);

        if (A <= 1 || A > (B / 2))
        {
            printf("\nvalor inválido | tente um valor maior ou igual a 2 e menor ou igual a %d\n", (B / 2));
            continue;
        }

        break;

    } while (1);

    int base = (B / 2) + 1;

    for (int i = 1; i <= base; i++)
    {
        for (int j = base; j > i; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("*");
        }
        for (int l = i - 1; l > 0; l--)
        {
            printf("*");
        }
        printf("\n");
    }

    int meia_linha = base - (L / 2) - 1;

    for (int i = 1; i <= A; i++)
    {
        for (int j = 0; j < meia_linha; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < L; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
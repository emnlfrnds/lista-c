#include <stdio.h>

int main(void)
{
    int tamanho, modelo;

    printf("\ninforme o tamanho do quadrado:\n");
    scanf("%d", &tamanho);

    printf("\ndeseja o quadrado preenchido ou vazado?\nuse 1 para preenchido | use 2 para vazado\n");
    scanf("%d", &modelo);

    switch (modelo)
    {
    case 1:
        printf("\n");
        for (int i = 0; i < tamanho; i++)
        {
            for (int j = 0; j < tamanho; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;

    case 2:
        printf("\n");
        for (int i = 0; i < tamanho; i++)
        {
            for (int j = 0; j < tamanho; j++)
            {
                if (i == 0 || i == tamanho - 1 || j == 0 || j == tamanho - 1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;

    default:
        printf("\ninforme uma escolha correta\n");
        break;
    }
    
    return 0;
}
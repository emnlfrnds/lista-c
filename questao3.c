#include <stdio.h>

int main(void)
{
    int tamanho, modelo;

    printf("\ninforme o tamanho do triângulo:\n");
    scanf("%d", &tamanho);

    printf("\ndeseja o triângulo preenchido ou vazado?\nuse 1 para preenchido | use 2 para vazado\n");
    scanf("%d", &modelo);

    int matriz[tamanho][tamanho];

    switch (modelo)
    {
    case 1:
        printf("\n");
        for (int i = 0; i < tamanho; i++)
        {
            for (int j = 0; j <= i; j++)
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
            for (int j = 0; j <= i; j++)
            {
                if (i == tamanho - 1 || j == 0 || j == i)
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
        printf("\ninforme uma opção válida\n");
        break;
    }
    
    return 0;
}
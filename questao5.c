#include <stdio.h>

int main()
{
    int altura;

    printf("\ninforme a altura do triângulo de pascal:\n");
    scanf("%d", &altura);

    for (int i = 0; i < altura; i++)
    {
        int valor = 1;
        {
            for (int j = 0; j < altura - i; j++)
            {
                printf(" ");
            }
            printf("%d ", 1);

            for (int k = 1; k <= i; k++)
            {
                valor = valor * (i - k + 1) / k;
                printf("%d ", valor);
            }
            printf("\n");
        }
    }
    
    return 0;
}
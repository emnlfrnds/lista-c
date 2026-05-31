#include <stdio.h>

int main(void)
{
    int base;

    printf("\ninforma a base do losango:\n");
    scanf("%d", &base);

    for (int i = 0; i < base; i++)
    {
        for (int j = 0; j < base - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            printf("X");
        }
        printf("\n");
    }

    for (int i = base - 2; i >= 0; i--)
    {
        for (int j = 0; j < base - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            printf("X");
        }
        printf("\n");
    }
    
    return 0;
}
#include <stdio.h>

int main(void)
{
    int N, space;

    printf("\ninforme o valor de N:\n");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        space = N - (N - i);
        for (int j = N; j > space; j--)
        {
            printf("    ");
        }
        for (int k = 1; k <= space; k++)
        {
            printf("%2d  ", k);
        }
        for (int l = space - 1; l > 0; l--)
        {
            printf("%2d  ", l);
        }
        printf("\n");
    }

    return 0;
}
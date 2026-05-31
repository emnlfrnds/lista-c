#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER 200000
#ifndef PI
#define PI 3.14159265358979323846
#endif

typedef struct
{
    double x, y;
    double angulo;
} Tartaruga;

void gerarLSystem(int iteracoes, char *axioma, char *regraF, char *resultado)
{
    strcpy(resultado, axioma);
    for (int i = 0; i < iteracoes; i++)
    {
        char temp[MAX_BUFFER] = "";
        for (int j = 0; resultado[j] != '\0'; j++)
        {
            if (resultado[j] == 'F')
            {
                strcat(temp, regraF);
            }
            else
            {
                char ch_str[2] = {resultado[j], '\0'};
                strcat(temp, ch_str);
            }
        }
        strcpy(resultado, temp);
    }
}

void desenhar(const char *comandos, double tamanho_passo, char **grade, int linhas, int colunas, double x_ini, double y_ini, double angulo_ini)
{
    Tartaruga t = {x_ini, y_ini, angulo_ini};
    double proporcao_x = 2.2;

    for (int i = 0; comandos[i] != '\0'; i++)
    {
        char cmd = comandos[i];
        if (cmd == 'F')
        {
            double novo_x = t.x + tamanho_passo * cos(t.angulo);
            double novo_y = t.y + tamanho_passo * sin(t.angulo);

            int x0 = (int)round(t.x * proporcao_x);
            int y0 = (int)round(t.y);
            int x1 = (int)round(novo_x * proporcao_x);
            int y1 = (int)round(novo_y);

            int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
            int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
            int err = dx + dy, e2;

            while (1)
            {
                if (y0 >= 0 && y0 < linhas && x0 >= 0 && x0 < colunas)
                {
                    grade[y0][x0] = '*';
                }
                if (x0 == x1 && y0 == y1)
                    break;
                e2 = 2 * err;
                if (e2 >= dy)
                {
                    err += dy;
                    x0 += sx;
                }
                if (e2 <= dx)
                {
                    err += dx;
                    y0 += sy;
                }
            }

            t.x = novo_x;
            t.y = novo_y;
        }
        else if (cmd == '+')
        {
            t.angulo += PI / 3.0;
        }
        else if (cmd == '-')
        {
            t.angulo -= PI / 3.0;
        }
    }
}

int main()
{
    int N;

    do
    {
        printf("\ninforme o nivel N do fractal (1 a 3):\n");
        scanf("%d", &N);
        if (N < 1 || N > 3)
        {
            printf("\ninforme um numero entre 1 e 3.\n");
            continue;
        }
        break;
    } while (1);

    int linhas = 35 * N;
    int colunas = 80 * N;

    char **grade = (char **)malloc(linhas * sizeof(char *));
    for (int i = 0; i < linhas; i++)
    {
        grade[i] = (char *)malloc(colunas * sizeof(char));
        for (int j = 0; j < colunas; j++)
            grade[i][j] = ' ';
    }

    int iteracoes = N;
    char sequencia[MAX_BUFFER];
    char *axioma = "F++F++F";
    char *regraF = "F-F++F-F";

    gerarLSystem(iteracoes, axioma, regraF, sequencia);

    double proporcao_x = 2.2;
    double v_cx = (colunas / 2.0) / proporcao_x;
    double v_cy = linhas / 2.0;

    double L = linhas * 0.55;
    double H = L * sqrt(3.0) / 2.0;

    double tamanho_passo = L / pow(3, iteracoes);

    double start_x = v_cx - L / 2.0;
    double start_y = v_cy - H / 2.5;
    desenhar(sequencia, tamanho_passo, grade, linhas, colunas, start_x, start_y, 0.0);
    
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            putchar(grade[i][j]);
        }
        putchar('\n');
    }

    for (int i = 0; i < linhas; i++)
        free(grade[i]);
    free(grade);

    return 0;
}
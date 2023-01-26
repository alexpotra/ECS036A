#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrix.h"

SquareMatrix *make_matrix(int n)
{

    SquareMatrix *m = malloc(sizeof(SquareMatrix));

    if (!m)
    {
        return NULL;
    }

    m->n = n;
    m->values = malloc(n * sizeof(double *));

    for (int i = 0; i < n; i++)
    {
        m->values[i] = malloc(n * sizeof(double));
    }

    return m;
}

void print_matrix(SquareMatrix *m)
{
    printf(">>>> Matrix of size %d\n", m->n);
    for (int i = 0; i < m->n; i++)
    {
        for (int j = 0; j < m->n; j++)
        {
            printf("%.2lf ", m->values[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(SquareMatrix *m)
{
    for (int i = 0; i < m->n; i++)
    {
        free(m->values[i]);
    }
    free(m->values);
    free(m);
}

double determinant(SquareMatrix *m)
{
    if (m->n == 1)
    {
        return m->values[0][0];
    }

    double result = 0.0;

    SquareMatrix *minor = make_matrix(m->n - 1);

    if (minor == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }

    for (int j = 0; j < m->n; j++)
    {
        fill_minor(m, j, minor);
        result += m->values[0][j] * (j % 2 ? -1 : 1) * determinant(minor);
    }

    free_matrix(minor);

    return result;
}

void fill_minor(SquareMatrix *m, int col, SquareMatrix *minor)
{
    for (int i = 0; i < m->n - 1; i++)
    {
        for (int j = 0; j < col; j++)
        {
            minor->values[i][j] = m->values[i + 1][j];
        }

        for (int j = col + 1; j < m->n; j++)
        {
            minor->values[i][j - 1] = m->values[i + 1][j];
        }
    }
}
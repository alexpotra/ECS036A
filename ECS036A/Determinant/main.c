#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "matrix.h"

int biggest_dimension = 100;

SquareMatrix *getMatrix(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        return NULL;
    }

    int numRows = 0, numCols = 0;
    fscanf(file, "%d %d\n", &numRows, &numCols);

    if (numRows != numCols)
    {
        return NULL;
    }

    SquareMatrix *m = make_matrix(numRows);

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            fscanf(file, "%lf", &(m->values[i][j]));
        }
    }

    fclose(file);
    return m;
}

int main(int argc, char *argv[])
{

    SquareMatrix *matrix = getMatrix(argv[1]);

    if (matrix == NULL)
    {
        exit(-1);
    }

    printf("The determinant is %.2lf.\n", determinant(matrix));

    free_matrix(matrix);

    return 0;
}
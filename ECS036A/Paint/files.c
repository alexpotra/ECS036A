// files.c
// Implementations for functions handling file operations

#include "files.h"
#include "canvas.h"

void save(Canvas *c, char *filename)
{
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Improper save command or file could not be created.\n");
        return;
    }
    fprintf(f, "%d %d\n", c->num_rows, c->num_cols);
    for (int i = 0; i < c->num_rows; i++)
    {
        for (int j = 0; j < c->num_cols; j++)
        {
            fprintf(f, "%c", c->canvas[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

Canvas *load(char *filename)
{
    int num_rows, num_cols;
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Improper load command or file could not be opened.\n");
        return NULL;
    }
    int vars = fscanf(f, "%d %d", &num_rows, &num_cols);
    if (vars != 2)
    {
        printf("Improper load command or file could not be opened.\n");
        return NULL;
    }
    Canvas *c = make_canvas(num_rows, num_cols);
    char eol;
    fscanf(f, "%c", &eol);
    for (int i = 0; i < c->num_rows; i++)
    {
        for (int j = 0; j < c->num_cols; j++)
        {
            fscanf(f, "%c", &(c->canvas[i][j]));
        }
        fscanf(f, "%c", &eol);
    }
    fclose(f);

    return c;
}

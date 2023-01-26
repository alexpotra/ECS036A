// canvas.c
// Implementations for functions managing the memory for a canvas

#include "canvas.h"

int min(int a, int b)
{
    return (a < b) ? a : b;
}

char **fill_canvas(int num_rows, int num_cols)
{
    char **result = malloc(num_rows * sizeof(char *));
    CHECK_ALLOC(result);

    for (int i = 0; i < num_rows; i++)
    {
        result[i] = malloc(num_cols * sizeof(char));
        CHECK_ALLOC(result[i]);
        for (int j = 0; j < num_cols; j++)
        {
            result[i][j] = '*';
        }
    }
    return result;
}

Canvas *make_canvas(int num_rows, int num_cols)
{
    Canvas *c = malloc(sizeof(Canvas));
    CHECK_ALLOC(c);

    if (num_rows < 1)
    {
        printf("The number of rows is less than 1.\n");
        return NULL;
    }

    if (num_cols < 1)
    {
        printf("The number of columns is less than 1.\n");
        return NULL;
    }

    c->num_rows = num_rows;
    c->num_cols = num_cols;
    c->canvas = fill_canvas(num_rows, num_cols);
    return c;
}

void resize_canvas(Canvas *c, int num_rows, int num_cols)
{
    char **new_canvas = fill_canvas(num_rows, num_cols);
    int count_rows = min(num_rows, c->num_rows);
    int count_cols = min(num_cols, c->num_cols);
    int d = num_rows - 1;

    if (num_rows < 1)
    {
        printf("The number of rows is less than 1.\n");
        return;
    }

    if (num_cols < 1)
    {
        printf("The number of columns is less than 1.\n");
        return;
    }

    for (int i = c->num_rows - 1; count_rows > 0; count_rows--, i--, d--)
    {
        for (int j = 0; j < count_cols; j++)
        {
            new_canvas[d][j] = c->canvas[i][j];
        }
    }

    for (int i = 0; i < c->num_rows; i++)
    {
        free(c->canvas[i]);
    }
    free(c->canvas);

    c->canvas = new_canvas;
    c->num_rows = num_rows;
    c->num_cols = num_cols;
}

void free_canvas(Canvas *c)
{
    for (int i = 0; i < c->num_rows; i++)
    {
        free(c->canvas[i]);
    }
    free(c->canvas);
    free(c);
}

void add(Canvas *c, char d, int pos)
{
    if (d == 'r')
    {
        if (pos < 0 || pos > c->num_rows)
        {
            printf("Improper add command.\n");
            return;
        }
        resize_canvas(c, c->num_rows + 1, c->num_cols);
        for (int i = 0; i < c->num_rows - pos - 1; i++)
        {
            for (int j = 0; j < c->num_cols; j++)
            {
                c->canvas[i][j] = c->canvas[i + 1][j];
            }
        }
        for (int j = 0; j < c->num_cols; j++)
        {
            c->canvas[c->num_rows - pos - 1][j] = '*';
        }
    }
    else
    {
        if (pos < 0 || pos > c->num_cols)
        {
            printf("Improper add command.\n");
            return;
        }
        resize_canvas(c, c->num_rows, c->num_cols + 1);
        for (int i = 0; i < c->num_rows; i++)
        {
            for (int j = c->num_cols - 1; j > pos; j--)
            {
                c->canvas[i][j] = c->canvas[i][j - 1];
            }
        }
        for (int i = 0; i < c->num_rows; i++)
        {
            c->canvas[i][pos] = '*';
        }
    }
}

void del(Canvas *c, char d, int pos)
{
    if (d == 'r')
    {
        if (pos < 0 || pos > c->num_rows)
        {
            printf("Improper delete command.\n");
            return;
        }
        for (int i = c->num_rows - pos - 1; i > 0; i--)
        {
            for (int j = 0; j < c->num_cols; j++)
            {
                c->canvas[i][j] = c->canvas[i - 1][j];
            }
        }
        resize_canvas(c, c->num_rows - 1, c->num_cols);
    }
    else
    {
        if (pos < 0 || pos > c->num_cols)
        {
            printf("Improper delete command.\n");
            return;
        }
        for (int i = 0; i < c->num_rows; i++)
        {
            for (int j = pos; j < c->num_cols - 1; j++)
            {
                c->canvas[i][j] = c->canvas[i][j + 1];
            }
        }
        resize_canvas(c, c->num_rows, c->num_cols - 1);
    }
}

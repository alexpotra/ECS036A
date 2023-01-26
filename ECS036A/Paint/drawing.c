// drawing.c
// Implementations for functions for managing canvas content

#include "drawing.h"

void write(Canvas *c, int start_row, int start_col, int end_row, int end_col)
{
    if (start_row < 0 || start_row >= c->num_rows)
    {
        printf("Invalid start row %d\n", start_row);
        return;
    }
    if (start_col < 0 || start_col >= c->num_cols)
    {
        printf("Invalid start col %d\n", start_col);
        return;
    }
    if (end_row < 0 || end_row >= c->num_rows)
    {
        printf("Invalid end row %d\n", end_row);
        return;
    }
    if (end_col < 0 || end_col >= c->num_cols)
    {
        printf("Invalid end col %d\n", end_col);
        return;
    }

    char drawing_char;
    int i = c->num_rows - start_row - 1;
    int j = start_col;
    int di;
    int dj;
    int num_steps;

    if (start_row == end_row)
    {
        drawing_char = '-';
        di = 0;
        dj = (start_col < end_col) ? 1 : -1;
        num_steps = abs(start_col - end_col) + 1;
    }
    else if (start_col == end_col)
    {
        drawing_char = '|';
        di = (start_row > end_row) ? 1 : -1;
        dj = 0;
        num_steps = abs(start_row - end_row) + 1;
    }
    else if (start_row - end_row == start_col - end_col)
    {
        drawing_char = '/';
        di = (start_row > end_row) ? 1 : -1;
        dj = (start_col < end_col) ? 1 : -1;
        num_steps = abs(start_col - end_col) + 1;
    }
    else if (start_row - end_row == end_col - start_col)
    {
        drawing_char = '\\';
        di = (start_row > end_row) ? 1 : -1;
        dj = (start_col < end_col) ? 1 : -1;
        num_steps = abs(start_row - end_row) + 1;
    }
    else
    {
        printf("Improper draw command.\n");
        return;
    }

    while (num_steps > 0)
    {
        if (c->canvas[i][j] != drawing_char && c->canvas[i][j] != '*')
        {
            c->canvas[i][j] = '+';
        }
        else
        {
            c->canvas[i][j] = drawing_char;
        }

        i += di;
        j += dj;
        num_steps--;
    }
}

void erase(Canvas *c, int row, int col)
{
    if (row < 0 || row >= c->num_rows)
    {
        printf("Invalid start row %d\n", row);
        return;
    }
    if (col < 0 || col >= c->num_cols)
    {
        printf("Invalid start col %d\n", col);
        return;
    }

    c->canvas[c->num_rows - row - 1][col] = '*';
}
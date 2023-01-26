// main.c
// Main application loop

#include "drawing.h"
#include "commands.h"
#include "files.h"

void draw_canvas(Canvas *c)
{
    for (int i = 0; i < c->num_rows; i++)
    {
        printf("%d ", c->num_rows - i - 1);
        for (int j = 0; j < c->num_cols; j++)
        {
            printf("%c ", c->canvas[i][j]);
        }
        printf("\n");
    }
    printf("  ");

    for (int j = 0; j < c->num_cols; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int num_rows = 10;
    int num_cols = 10;

    if (argc == 3)
    {
        num_rows = atoi(argv[1]);
        num_cols = atoi(argv[2]);
        if (num_rows < 1)
        {
            num_rows = 10;
            num_cols = 10;
            printf("The number of rows is less than 1.\n");
            printf("Making default board of 10 X 10.\n");
        }
        else if (num_cols < 1)
        {
            num_rows = 10;
            num_cols = 10;
            printf("The number of columns is less than 1.\n");
            printf("Making default board of 10 X 10.\n");
        }
    }
    else if (argc != 1)
    {
        printf("Wrong number of command line arguments entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        printf("Making default board of 10 X 10.\n");
    }

    int quit = 0;
    Canvas *c = make_canvas(num_rows, num_cols);

    if (c == NULL)
    {
        exit(0);
    }

    while (!quit)
    {
        draw_canvas(c);
        Command cmd = get_command();
        int start_r, start_c, end_r, end_c, pos;
        char d;
        char filename[1024];
        switch (cmd)
        {
        case Quit:
            quit = 1;
            break;
        case Help:
            print_help();
            break;
        case Write:
            if (get_write_params(&start_r, &start_c, &end_r, &end_c) == 4)
            {
                write(c, start_r, start_c, end_r, end_c);
            }
            break;
        case Erase:
            if (get_erase_params(&start_r, &start_c) == 2)
            {
                erase(c, start_r, start_c);
            }
            break;
        case Resize:
            if (get_resize_params(&start_r, &start_c) == 2)
            {
                resize_canvas(c, start_r, start_c);
            }
            break;
        case Add:
            if (get_add_del_params(&d, &pos, "add") == 2)
            {
                add(c, d, pos);
            }
            break;
        case Delete:
            if (get_add_del_params(&d, &pos, "delete") == 2)
            {
                del(c, d, pos);
            }
            break;
        case Save:
            if (get_save_load_params(filename, "save") == 1)
            {
                save(c, filename);
            }
            break;
        case Load:
            if (get_save_load_params(filename, "load") == 1)
            {
                Canvas *new_canvas = load(filename);
                if (new_canvas != NULL)
                {
                    free_canvas(c);
                    c = new_canvas;
                }
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
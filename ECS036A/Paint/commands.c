// commands.c
// Implementations for functions parsing user inputs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

// Checks if residual input is left on the line
// Returns 0 if no residual, 1 otherwise
int clear_line()
{
    int result = 0;
    char *buffer = NULL;
    size_t len = 0;
    getline(&buffer, &len, stdin);
    if (buffer)
    {
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] > 32)
            {
                result = 1;
            }
        }
        free(buffer);
    }
    return result;
}

// Checks if command length is valid
// Returns 0 if length is 1, returns 1 otherwise
int check_command_length(char *command, int clear)
{
    if (strlen(command) == 1)
    {
        return 0;
    }
    else
    {
        if (clear)
        {
            clear_line();
        }
        return 1;
    }
}

Command get_command()
{
    char command[1024];
    printf("Enter your command: ");
    scanf("%s", command);

    switch (command[0])
    {
    case 'q':
        if (check_command_length(command, 1))
        {
            printf("Improper quit command.\n");
            return Invalid;
        }
        return Quit;
    case 'h':
        if (check_command_length(command, 1))
        {
            printf("Improper help command.\n");
            return Invalid;
        }
        return Help;
    case 'w':
        if (check_command_length(command, 1))
        {
            printf("Improper draw command.\n");
            return Invalid;
        }
        return Write;
    case 'e':
        if (check_command_length(command, 1))
        {
            printf("Improper erase command.\n");
            return Invalid;
        }
        return Erase;
    case 'r':
        if (check_command_length(command, 1))
        {
            printf("Improper resize command.\n");
            return Invalid;
        }
        return Resize;
    case 'a':
        if (check_command_length(command, 1))
        {
            printf("Improper add command.\n");
            return Invalid;
        }
        return Add;
    case 'd':
        if (check_command_length(command, 1))
        {
            printf("Improper delete command.\n");
            return Invalid;
        }
        return Delete;
    case 's':
        if (check_command_length(command, 1))
        {
            printf("Improper save command.\n");
            return Invalid;
        }
        return Save;
    case 'l':
        if (check_command_length(command, 1))
        {
            printf("Improper load command.\n");
            return Invalid;
        }
        return Load;
    case '\n':
    case '\r':
        return Invalid;
    default:
        printf("Unrecognized command. Type h for help.\n");
        return Invalid;
    }
}

void print_help()
{

    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
}

int get_write_params(int *start_row, int *start_col, int *end_row, int *end_col)
{
    int parameters = scanf("%d %d %d %d", start_row, start_col, end_row, end_col);

    if (parameters != 4 || clear_line())
    {
        printf("Improper draw command.\n");
        return -1;
    }

    return parameters;
}

int get_erase_params(int *row, int *col)
{
    int parameters = scanf("%d %d", row, col);

    if (parameters != 2 || clear_line())
    {
        printf("Improper erase command.\n");
        return -1;
    }

    return parameters;
}

int get_resize_params(int *num_rows, int *num_cols)
{
    int parameters = scanf("%d %d", num_rows, num_cols);

    if (parameters != 2 || clear_line())
    {
        printf("Improper resize command.\n");
        return -1;
    }

    return parameters;
}

int get_add_del_params(char *d, int *pos, char *cmd)
{
    char buffer[1024];
    int parameters = scanf("%s %d", buffer, pos);
    if (parameters != 2 || clear_line())
    {
        printf("Improper %s command.\n", cmd);
        return -1;
    }
    if (check_command_length(buffer, 0))
    {
        printf("Improper %s command.\n", cmd);
        return -1;
    }
    *d = buffer[0];
    if (*d != 'r' && *d != 'c')
    {
        printf("Improper %s command.\n", cmd);
        return -1;
    }

    return parameters;
}

int get_save_load_params(char *filename, char *cmd)
{
    int parameters = scanf("%s", filename);

    if (parameters != 1 || clear_line())
    {
        printf("Improper %s command.\n", cmd);
        return -1;
    }

    return parameters;
}

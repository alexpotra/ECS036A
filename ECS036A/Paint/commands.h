// commands.h
// Definitions for functions parsing user inputs

// Enum defining user commands supported
typedef enum Command
{
    Quit,
    Help,
    Write,
    Erase,
    Resize,
    Add,
    Delete,
    Save,
    Load,
    Invalid
} Command;

// Parse user input to extract command field
// Returns the command argument
Command get_command();

// Prints help screen for command options
void print_help();

// Parse user input for write() parameters
//      start_row: start row for write function
//      start_col: start column for write function
//      end_row: end row for write function
//      end_col: end column for write function
// Returns the number of successful fields parsed
int get_write_params(int *start_row, int *start_col, int *end_row, int *end_col);

// Parse user input for erase() parameters
//      row: row for erase function
//      col: column for erase function
// Returns the number of successful fields parsed
int get_erase_params(int *row, int *col);

// Parse user input for resize_canvas() parameters
//      num_rows: number of rows for resize function
//      num_cols: number of columns for resize function
// Returns the number of successful fields parsed
int get_resize_params(int *num_rows, int *num_cols);

// Parse user input for add() & del() parameters
//      d: direction (row/column) for add & delete functions
//      pos: position for add & delete functions
//      cmd: which command was chosen (add/delete)
// Returns the number of successful fields parsed
int get_add_del_params(char *d, int *pos, char *cmd);

// Parse user input for save() & load() parameters
//      filename: save/load file location for save & load functions
//      cmd: which command was chosen (save/load)
// Returns the number of successful fields parsed
int get_save_load_params(char *filename, char *cmd);

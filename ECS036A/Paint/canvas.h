// canvas.h
// Definitions for functions managing the memory for a canvas

#ifndef _CANVAS_H
#define _CANVAS_H

#include <stdio.h>
#include <stdlib.h>

#define CHECK_ALLOC(p)                          \
    if (p == NULL)                              \
    {                                           \
        printf("Failed to allocate memory.\n"); \
        exit(0);                                \
    }

// Struct defining canvas object
//      num_rows: number of rows for canvas
//      num_cols: number of columns for canvas
//      canvas: char values for coordinates in canvas
typedef struct Canvas
{
    int num_rows;
    int num_cols;

    char **canvas;
} Canvas;

// Allocate a new canvas with given dimensions
//      num_rows: number of rows for new canvas
//      num_cols: number of columns for new canvas
// Returns the canvas object if successful, NULL otherwise
Canvas *make_canvas(int num_rows, int num_cols);

// Reallocates a new canvas with given dimensions
//      c: original canvas object to resize
//      num_rows: number of rows for new canvas
//      num_cols: number of columns for new canvas
void resize_canvas(Canvas *c, int num_rows, int num_cols);

// Frees an allocated canvas object
//      c: canvas to be freed
void free_canvas(Canvas *c);

// Adds empty row or column to selected position
//      c: canvas to be edited
//      d: direction of addition (row/column)
//      pos: position of added row/column
void add(Canvas *c, char d, int pos);

// Deletes row or column from selected position
//      c: canvas to be edited
//      d: direction of deletion (row/column)
//      pos: position of row/column to be deleted
void del(Canvas *c, char d, int pos);

#endif
// drawing.h
// Definitions for functions for managing canvas content

#include "canvas.h"

// Draws straight line to canvas
//      c: canvas to be drawn on
//      start_row: start row for line
//      start_col: start column for line
//      end_row: end row for line
//      end_col: end column for line
void write(Canvas *c, int start_row, int start_col, int end_row, int end_col);

// Draws erases chosen coordinate point on canvas
//      c: canvas to be erased from
//      row: row for erase coordinate
//      col: column for erase coordinate
void erase(Canvas *c, int row, int col);
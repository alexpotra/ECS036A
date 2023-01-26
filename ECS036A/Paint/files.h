// files.h
// Definitions for functions handling file operations

#include "canvas.h"

// Saves existing canvas object to file
//      c: canvas to be saved
//      filename: save location
void save(Canvas *c, char *filename);

// Loads saved canvas object from file
//      filename: load location
// Returns loaded canvas object from file, or NULL if invalid
Canvas *load(char *filename);

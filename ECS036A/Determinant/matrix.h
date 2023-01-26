typedef struct SquareMatrix
{
    int n;
    double **values;
} SquareMatrix;

double determinant(SquareMatrix *m);

void fill_minor(SquareMatrix *m, int col, SquareMatrix *minor);

SquareMatrix *make_matrix(int n);
void free_matrix(SquareMatrix *m);
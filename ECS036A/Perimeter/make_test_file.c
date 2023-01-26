#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// create a point struct with coordinate values (x,y)
typedef struct Point
{
    int x;
    int y;
} Point;

void make_points(int n, char *filename)
{
    FILE *output = fopen(filename, "wb");
    if (output == NULL)
    {
        printf("File not opened\n");
        exit(0);
    }
    Point *points = malloc(n * sizeof(Point));
    if (points == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        points[i].x = i;
        points[i].y = 2 * i;
    }

    int c = fwrite(&n, sizeof(n), 1, output);
    if (c != 1)
    {
        printf("Count not written\n");
        exit(0);
    }

    c = fwrite(points, sizeof(Point), n, output);
    if (c != n)
    {
        printf("Points not written\n");
        exit(0);
    }

    free(points);
    fclose(output);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: make_test_file <point_count> <filename>\n");
        exit(0);
    }
    make_points(atoi(argv[1]), argv[2]);
    return 0;
}

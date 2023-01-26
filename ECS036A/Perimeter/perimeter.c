#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// create a point struct with coordinate values (x,y)
typedef struct Point
{
    int x;
    int y;
} Point;

// function calculates distance between two points
double distance(Point p1, Point p2)
{
    // distance formula
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

// function to calculate perimeter
double getPerimeter(Point *points, int size)
{
    double result = 0.0;
    for (int i = 1; i < size; i++)
    {
        result += distance(points[i - 1], points[i]);
    }
    result += distance(points[size - 1], points[0]);
    return result;
}

// main function
int main(int argc, char *argv[])
{
    double perimeter;
    Point *points = NULL;
    int n;
    FILE *input = fopen(argv[1], "rb");

    int c = fread(&n, sizeof(n), 1, input);
    if (c != 1)
    {
        exit(0);
    }

    printf(">>>> Point count %d\n", n);
    points = malloc(sizeof(Point) * n);

    c = fread(points, sizeof(Point), n, input);
    if (c != n)
    {
        exit(0);
    }

    perimeter = getPerimeter(points, n);
    printf("The perimeter is %.2lf\n", perimeter);

    free(points);
    fclose(input);
    return 0;
}

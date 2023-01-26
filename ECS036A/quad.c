#include <stdio.h>
#include <math.h>

int main(void)
{
    double a;
    double b;
    double c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    if ((pow(b, 2) - (4 * a * c)) > 0)
    {
        printf("There are 2 real solutions\n");
        double root1 = ((-1.0 * b) + sqrt(pow(b, 2) - (4.0 * a * c))) / (2.0 * a);
        double root2 = ((-1.0 * b) - sqrt(pow(b, 2) - (4.0 * a * c))) / (2.0 * a);
        printf("Solution 1: %.2lf\n", root1);
        printf("Solution 2: %.2lf\n", root2);
    }
    else if ((pow(b, 2) - (4 * a * c)) == 0)
    {
        double root1 = (-1.0 * b) / (2.0 * a);
        printf("There is one real solution: %.2lf\n", root1);
    }
    else
    {
        printf("There are no real solutions");
    }
}
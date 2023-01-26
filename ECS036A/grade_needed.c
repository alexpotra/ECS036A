#include <stdio.h>

int main(void)
{
    char letterGrade;
    double gradeNeeded;
    double currGrade;
    double finalWeight;

    printf("Enter the grade you want in the class: ");
    scanf("%c", &letterGrade);

    printf("Enter the percent you need to get that grade: ");
    scanf("%lf", &gradeNeeded);

    printf("Enter your current percent in the class: ");
    scanf("%lf", &currGrade);

    printf("Enter the weight of the final: ");
    scanf("%lf", &finalWeight);

    double examGrade = (gradeNeeded - (currGrade * (1 - (finalWeight / 100)))) / (finalWeight / 100);

    printf("You need to get at least %.2lf%% on the final to get a %c in the class.", examGrade, letterGrade);

    return 0;
}
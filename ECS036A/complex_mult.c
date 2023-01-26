#include <stdio.h>

int main()
{
    char firstNum[6];
    char secondNum[6];

    printf("Enter the first complex number in the form ai + b: ");
    scanf("%[^\n]%*c", firstNum);

    printf("Enter the second complex number in the form ai + b: ");
    scanf("%[^\n]%*c", secondNum);

    int x1 = firstNum[0];
    int y1 = firstNum[5];

    int x2 = secondNum[0];
    int y2 = secondNum[5];

    printf("(%di + %d) * (%di + %d) = %di + %d", x1, y1, x2, y2, x1 * y2 + y1 * x2, y2 * y1 - x1 * x2);

    return 0;
}
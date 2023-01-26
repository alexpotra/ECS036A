#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum ConversionType
{
    Temp,
    Dist
} ConversionType;

ConversionType get_conversion_type()
{
    char buffer[1024];
    printf(
        "Pick the type of conversion that you would like to do.\n"
        "T or t for temperature\nD or d for distance\n"
        "Enter your choice: ");
    scanf("%s", buffer);

    for (int i = 0; i < strlen(buffer); i++)
    {
        buffer[i] = toupper(buffer[i]);
    }

    if (strlen(buffer) != 1)
    {
        if (buffer[0] == 'T' || buffer[0] == 'D')
        {
            printf("Invalid formatting. Ending program.\n");
        }
        else
        {
            printf("Unknown conversion type %s chosen. Ending program.\n", buffer);
        }
        exit(0);
    }

    if (buffer[0] == 'T')
    {
        return Temp;
    }

    if (buffer[0] == 'D')
    {
        return Dist;
    }

    printf("Unknown conversion type %s chosen. Ending program.\n", buffer);
    exit(0);
}

typedef enum TempUnits
{
    Fahrenheit = 0,
    Celsius = 1,
    Kelvin = 2,
    InvalidTemp = 3
} TempUnits;

typedef enum DistUnits
{
    Inches = 0,
    Feet = 1,
    Yards = 2,
    Miles = 3,
    InvalidDist = 4
} DistUnits;

TempUnits get_temp_unit(char unit)
{
    switch (unit)
    {
    case 'F':
        return Fahrenheit;
    case 'C':
        return Celsius;
    case 'K':
        return Kelvin;
    default:
        return InvalidTemp;
    }
}

DistUnits get_dist_unit(char unit)
{
    switch (unit)
    {
    case 'I':
        return Inches;
    case 'F':
        return Feet;
    case 'Y':
        return Yards;
    case 'M':
        return Miles;
    default:
        return InvalidDist;
    }
}

int check_temp_unit(char *unit)
{
    if (strlen(unit) != 1)
    {
        return 0;
    }

    if (get_temp_unit(unit[0]) == InvalidTemp)
    {
        return 0;
    }

    return 1;
}

int check_dist_unit(char *unit)
{
    if (strlen(unit) != 1)
    {
        return 0;
    }

    if (get_dist_unit(unit[0]) == InvalidDist)
    {
        return 0;
    }

    return 1;
}

typedef double (*CONVERT)(double);

double convert_121(double val)
{
    return val;
}

double convert_F2C(double val)
{
    return (val - 32) * 5.0 / 9.0;
}

double convert_F2K(double val)
{
    return (val - 32) * 5.0 / 9.0 + 273.15;
}

double convert_C2F(double val)
{
    return (val * 9.0 / 5.0) + 32;
}

double convert_C2K(double val)
{
    return val + 273.15;
}

double convert_K2F(double val)
{
    return (val - 273.15) * 9.0 / 5.0 + 32;
}

double convert_K2C(double val)
{
    return val - 273.15;
}

CONVERT temp_conversions[3][3] = {
    {convert_121, convert_F2C, convert_F2K},
    {convert_C2F, convert_121, convert_C2K},
    {convert_K2F, convert_K2C, convert_121}};

double convert_I2F(double val)
{
    return val / 12.0;
}
double convert_I2Y(double val)
{
    return val / 36.0;
}
double convert_I2M(double val)
{
    return val / 63360.0;
}
double convert_F2I(double val)
{
    return val * 12.0;
}
double convert_F2Y(double val)
{
    return val / 3.0;
}
double convert_F2M(double val)
{
    return val / 5280.0;
}
double convert_Y2I(double val)
{
    return val * 36.0;
}
double convert_Y2F(double val)
{
    return val * 3;
}
double convert_Y2M(double val)
{
    return val / 1760.0;
}
double convert_M2I(double val)
{
    return val * 63360.0;
}
double convert_M2F(double val)
{
    return val * 5280.0;
}
double convert_M2Y(double val)
{
    return val * 1760.0;
}

CONVERT dist_conversions[4][4] = {
    {convert_121, convert_I2F, convert_I2Y, convert_I2M},
    {convert_F2I, convert_121, convert_F2Y, convert_F2M},
    {convert_Y2I, convert_Y2F, convert_121, convert_Y2M},
    {convert_M2I, convert_M2F, convert_M2Y, convert_121}};

void convert_temp()
{
    double val = 0.0;
    char unit[1024];
    char new_unit[1024];

    printf("Enter the temperature followed by its suffix (F, C, or K): ");

    int val_c = scanf("%lf", &val);
    if (val_c != 1)
    {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }

    int unit_c = scanf("%s", unit);
    for (int i = 0; i < strlen(unit); i++)
    {
        unit[i] = toupper(unit[i]);
    }
    if (unit_c != 1 || !check_temp_unit(unit))
    {
        if (unit[0] == 'F' || unit[0] == 'C' || unit[0] == 'K')
        {
            printf("Invalid formatting. Ending program.\n");
        }
        else
        {
            printf("%s is not a valid temperature type. Ending program.\n", unit);
        }
        exit(0);
    }

    printf("Enter the new unit type (F, C, or K): ");
    unit_c = scanf("%s", new_unit);
    for (int i = 0; i < strlen(new_unit); i++)
    {
        new_unit[i] = toupper(new_unit[i]);
    }
    if (unit_c != 1 || !check_temp_unit(new_unit))
    {
        if (new_unit[0] == 'F' || new_unit[0] == 'C' || new_unit[0] == 'K')
        {
            printf("Invalid formatting. Ending program.\n");
        }
        else
        {
            printf("%s is not a valid temperature type. Ending program.\n", new_unit);
        }
        exit(0);
    }

    CONVERT convert = temp_conversions[get_temp_unit(unit[0])][get_temp_unit(new_unit[0])];
    printf("%.2lf%c is %.2lf%c\n", val, toupper(unit[0]), convert(val), toupper(new_unit[0]));
}

void convert_dist()
{
    double val = 0.0;
    char unit[1024];
    char new_unit[1024];

    printf("Enter the distance followed by its suffix (I,F,Y,M): ");

    int val_c = scanf("%lf", &val);
    if (val_c != 1)
    {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }

    int unit_c = scanf("%s", unit);
    for (int i = 0; i < strlen(unit); i++)
    {
        unit[i] = toupper(unit[i]);
    }
    if (unit_c != 1 || !check_dist_unit(unit))
    {
        if (unit[0] == 'I' || unit[0] == 'F' || unit[0] == 'Y' || unit[0] == 'M')
        {
            printf("Invalid formatting. Ending program.\n");
        }
        else
        {
            printf("%s is not a valid distance type. Ending program.\n", unit);
        }
        exit(0);
    }

    printf("Enter the new unit type (I,F,Y,M): ");
    unit_c = scanf("%s", new_unit);
    for (int i = 0; i < strlen(new_unit); i++)
    {
        new_unit[i] = toupper(new_unit[i]);
    }
    if (unit_c != 1 || !check_dist_unit(new_unit))
    {
        if (new_unit[0] == 'I' || new_unit[0] == 'F' || new_unit[0] == 'Y' || new_unit[0] == 'M')
        {
            printf("Invalid formatting. Ending program.\n");
        }
        else
        {
            printf("%s is not a valid distance type. Ending program.\n", new_unit);
        }
        exit(0);
    }

    CONVERT convert = dist_conversions[get_dist_unit(unit[0])][get_dist_unit(new_unit[0])];
    printf("%.2lf%c is %.2lf%c\n", val, toupper(unit[0]), convert(val), toupper(new_unit[0]));
}

int main()
{
    ConversionType type = get_conversion_type();
    if (type == Temp)
    {
        convert_temp();
    }
    else
    {
        convert_dist();
    }

    return 0;
}
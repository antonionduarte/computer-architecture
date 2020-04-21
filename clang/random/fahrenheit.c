#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* Print Fahrenheit-Celsius table for fahr = 0, 20 ..., 300 (this is a comment btw) */
float celsius(int);

int main()
{
    float fahr;
    int lower, upper, step;

    // I don't think this is necessarily
    lower = LOWER; // lower limit of temperatures table
    upper = UPPER; // upper limit of temperatures table
    step = STEP; // step size

    printf("Celsius\tFahrenheit\n");

    for (float fahr = upper; fahr >= lower; fahr -= step)
    {
        printf("%3.1f\t%6.1f\n", fahr, celsius(fahr));
    }
}

float celsius(int fahr)
{
    return 5.0 * (fahr - 32.0) / 9.0;
}
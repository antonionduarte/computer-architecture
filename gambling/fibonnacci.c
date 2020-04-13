#include <stdio.h>

#define START 1

int main() {

    int total_value; // Total value you have to bet.
    int pre_previous, previous, sum, index; // Variables related to fibbonacci generation.

    index = 1;
    previous = 1;
    pre_previous = 1;
    sum = 0;

    int input;

    printf("Please insert the total value that you want to bet: ");
    scanf(" %d", &input);
    printf("NOTE: You currently have 20.000 available\n");

    previous = input;
    pre_previous = input;

    // printf("Please insert the total value you have available: ");
    // scanf(" %d", &total_value);

    total_value = 2000; // ATM THIS WILL BE A FIXED VALUE.
    int losses = 0;

    while (total_value > 0) {

        // Generates the fibbonacci sequence.

        if (index < 3) {
            printf("%d\n", pre_previous);
            total_value -= pre_previous;
        } else {
            sum = previous + pre_previous;
            printf("%d\n", sum);
            pre_previous = previous;
            previous = sum;
        }

        // Takes the value from the total_value to test how many losses.
        
        total_value -= sum;
        
        losses++;
        index++;
    }

    printf("You are able to take: %d losses\n", losses);

    return 0;
}


#include <stdio.h>

int main() {
    float bet_value;
    int safe_ground;
    printf("Please introduce your safe ground: ");
    scanf(" %d", &safe_ground);
    printf("Please introduce your bet value: ");
    scanf(" %f", &bet_value);
    for (int i = 1; i <= safe_ground; i++)
        bet_value = bet_value * 2;
    printf("The value that you need to invest: %f\n", bet_value);
}
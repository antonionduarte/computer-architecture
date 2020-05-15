#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

    /* Variables */

    // contents of the first 8 bytes of a PNG file
    char png[] = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};

    /* Open the file on read mode */

    FILE* file = fopen(argv[1], "r");

    /* Copy bytes to read into an array */

    char file_to_read[24];
    fread(file_to_read, 1, 24, file);

    /* Compare the first 8 bytes */

    // checks if the file is PNG or not
    if (memcmp(png, file_to_read, 8) != 0) {
        printf("Not a PNG file.\n");
        return 0;
    }

    /* See the sizes of the PNG */

    // copy the width int to a char array
    char* width;
    int count = 0;
    for (int i = 19; i >= 16; i--) {
        file_to_read[i] = width[count];
        count++;
    }

    // copy the heigth int to a char array
    char* heigth;
    count = 0;
    for (int i = 23; i >= 20; i--) {
        file_to_read[i] = heigth[count];
        count++;
    }

    int width_real = *((int *) width);
    int heigth_real = *((int *) heigth);

    printf("%d %d", width_real, heigth_real);

    return 0;
}
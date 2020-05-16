#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

    /* Variables */

    // contents of the first 8 bytes of a PNG file
    char png[] = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};

    /* Open the file on read mode */

    FILE* file = fopen(argv[1], "r");

    /* Copy bytes to read into an array */

    char relevant_bytes[24];
    fread(relevant_bytes, 1, 24, file);

    /* Compare the first 8 bytes to check if it is a PNG file */

    if (memcmp(png, relevant_bytes, 8) != 0) {
        printf("Not a PNG file.\n");
        return 0;
    }

    /* See the sizes of the PNG */

    char width[4], heigth[4];
    int count = 0;
    for (int i = 0; i < 4; i++) {
        width[count] = relevant_bytes[19 - i];
        heigth[count] = relevant_bytes[23 - i];
        count++;
    }

    int width_number = *((int *) width);
    int heigth_number = *((int *) heigth);

    printf("PNG file: %d x %d\n", width_number, heigth_number);

    return 0;
}
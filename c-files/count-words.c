#include <stdio.h>

#define IN 1 // Inside a word
#define OUT 0 // Outside a word

int main() {
    int c, n1, nw, nc, state;
    
    state = OUT;
    n1 = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc; // This parts adds a new char. (Be mindful that it counts \n and \t as chars).
        if (c == '\n') // This part adds a line if the new character is a line change.
            ++n1; 
        if (c == ' ' || c == '\n' || c == '\t') // This part determines if we're out of a word.
            state = OUT; 
        else if (state == OUT) { // If we are indeed outside a word this adds a new word.
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", n1, nw, nc);
}
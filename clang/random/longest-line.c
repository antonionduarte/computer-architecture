#include <stdio.h>
#define MAXLINE 1000 // Maximum input lines size

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; // Current line lenght
    int max; // Maximum lenght seen so far

    char line[MAXLINE]; // Current input line
    char longest[MAXLINE]; // Line that has the maximum lenght

    max = 0;
    while ((len = _getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) // Checks if there was a line
        printf("%s", longest);
    return 0;
}

int _getline(char s[], int lim) // This receives an array of chars and a limit
// The s[] is a character array (the way we define a line). It has a limit of chars
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        // In this case we use (lim - 1) because array indexes start with 0
        // This loop will run and add characters to the char array (line)
        // Until we either reach the limit, reach the EOF char or reach a 
        // Line change character
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i; // Returns the lenght of the line
}

void copy(char to[], char from[]) // This method basically copies one array of characters to another
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        // This copies the array element i of the first one to the second
        // Until it reaches the end of line char (\0)
        ++i;
}
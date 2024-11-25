#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int ROWS = 4;
static const int COLS = 4;

static int pows[ROWS][COLS] = { {1000, 1000, 1000, 1000},
                                {900, 500, 400, 100},
                                {90, 50, 40, 10},
                                {9, 5, 4, 1} };

static char *roms[ROWS][COLS] = { { "m", "m", "m", "m" },
                                  { "cm", "d", "cd", "c" },
                                  { "xc", "l", "xl", "x" },
                                  { "ix", "v", "iv", "i" } };

static void checkvalue(int value)
{
    if (value < 1 || value > 9999) {
        fprintf(stderr, "Use numbers in the range 1 .. 9999\n");
        exit(EXIT_FAILURE);  // Use EXIT_FAILURE for error exit
    }
}

static void to_roman(int decimal, /*@out@*/ char *roman)
{
    int power, indx;
    
    roman[0] = '\0';  // Initialize roman as an empty string

    for (power = 0; power < ROWS; power++) {
        for (indx = 0; indx < COLS; indx++) {
            while (decimal >= pows[power][indx]) {
                // Append to roman safely using snprintf to avoid buffer overflow
                (void)snprintf(roman + strlen(roman), 25 - strlen(roman), "%s", roms[power][indx]);
                decimal -= pows[power][indx];
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int low;          /* Starting number from command line */
    int high;         /* Ending number from command line */
    char roman[25];   /* Converted Roman number */

    if (argc < 2) {
        printf("Usage: roman decimal_number\n");
        exit(EXIT_FAILURE);  // Use EXIT_FAILURE for error exit
    }

    low = atoi(argv[1]);
    high = low;
    checkvalue(low);

    if (argc > 2) {
        high = atoi(argv[2]);
        checkvalue(high);
        if (low > high) {
            fprintf(stderr, "Lower number must be less than the higher number\n");
            exit(EXIT_FAILURE);  // Use EXIT_FAILURE for error exit
        }
    }
    else {
        low = 1;  // Low side is 1 if only one argument
    }

    for (; low <= high; low++) {
        to_roman(low, roman);
        fprintf(stdout, "%d %s\n", low, roman);
    }

    return 0;  // Return 0 to indicate successful execution
}
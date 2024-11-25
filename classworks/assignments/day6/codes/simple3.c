#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main() {
    char *data1;
    char *data2;
    int i;
    int a;

    do {
        data1 = (char *)malloc(SIZE);
        if (data1 == NULL) {
            fprintf(stderr, "Memory allocation failed for data1\n");
            return 1;
        }

        printf("Please enter your user name: ");
       (void) scanf("%15s", data1);  // Avoid buffer overflow

        a = strcmp(data1, "quit");
        if (a == 0) {  // Exit loop if user types "quit"
            free(data1);
            break;
        }

        data2 = (char *)malloc(SIZE);
        if (data2 == NULL) {
            fprintf(stderr, "Memory allocation failed for data2\n");
            free(data1);
            return 1;
        }

        // Copy at most SIZE-1 characters to avoid buffer overflow
        for (i = 0; i < SIZE - 1 && data1[i] != '\0'; i++) {
            data2[i] = data1[i];
        }
        data2[i] = '\0';  // Null-terminate the string

        free(data1);  // Free data1 after use
        printf("data2 :%s:\n", data2);

        free(data2);  // Free data2 after use
    } while (true);

    return 0;
}
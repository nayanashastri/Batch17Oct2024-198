/*  sample4.c : A C program example for practising static code analysis
 *  This program is filled with errors and NOT intended to ever be run
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main()
{
    char *data1, *data2, *tmp;
    int i;

    data1 = (char *)malloc(SIZE);
    if (NULL == data1)
		exit (EXIT_FAILURE);
    printf("Please input your username: ");

    if (EOF == scanf("%s", data1))
		exit (EXIT_FAILURE);

    data2 = (char *)malloc (SIZE);
    if (NULL == data2)
		exit (EXIT_FAILURE);
    tmp = data1;
    for (i = 0; i<16; i++)
    {
        data2[i] = *(tmp++);
    }
    printf ("tmp :%s:\n", tmp);
    free (data1);
    printf ("data2 :%s:\n", data2);

    /* Splint should catch the fact that memory pointed to by tmp is invalid
     * and is being read in the following instruction */

    /* Splint should catch the fact that the memory allocated for
     * data2 is not freed */
     free(data2);
    return 0;
}
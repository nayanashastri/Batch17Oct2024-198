/*  sample5.c : A C program example for practising static code analysis
 *  This program is filled with errors and NOT intended to ever be run
 */

#include <stdlib.h>

static int *func();

int main()
{
    int a=0;
    int *pint = NULL;

    /* Splint should catch the fact that the value of 'a' is used  
     * before being initialized */
    a = a + 1;
    pint = func();
    printf("Value returned by func: %d",*pint);
    free(pint);
	return 0;
}
static int *func()
{
    /* Splint should catch the fact that the address of 'a' which  
     * is allocated on the stack is being returned to the calling 
     * function
     */
int *a = (int *)malloc(sizeof(int));  // Dynamically allocate memory for 'a'
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(0);
    }

    *a = 10;  

    return a;


	}
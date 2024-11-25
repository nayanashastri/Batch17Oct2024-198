 *  This program is filled with errors and NOT intended to ever be run
 */
#include <stdio.h>

int main()
{
	int *p=malloc(sizeof(int));
	if(p==NULL){
	 fprintf(stderr,"Memory allocation\n");
	 return 1;
	}
	/* Splint should catch the fact that the storage pointed to by 
     * p is not yet defined
	 */ 
    *p=42;
	printf ("integer value : %d", *p);
    free(p);
return 0;
}
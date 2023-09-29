#include <stdio.h>
#include <stdlib.h> 
#include "inc_4.h"
 
void func_4(int low, int high)
{
	printf( "\nHello, I m func_1! (PRIME)\n" );
	int i, flag;

	printf("Prime numbers between %d and %d are: ", low, high);

    while (low < high)
    {
		flag = 0;

		for(i = 2; i <= low/2; ++i)
		{
			if(low % i == 0)
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
			printf("%d ", low);

		++low;
    }
	printf("\n");
}

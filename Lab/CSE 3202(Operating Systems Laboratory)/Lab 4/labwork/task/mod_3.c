#include <stdio.h>
#include <stdlib.h> 
#include "inc_3.h"
 
void func_3(int n1, int n2)
{
	printf( "\nHello, I m func_3! (LCM)\n" );
	int i, gcd, mul, lcm;
	mul=(n1*n2);
	for(i=1; i <= n1 && i <= n2; ++i)
	{
		if(n1%i==0 && n2%i==0)
		    gcd = i;
	}
	lcm=(mul/gcd);

    	printf("\nLCM of %d and %d is: %d\n", n1, n2, lcm);
}

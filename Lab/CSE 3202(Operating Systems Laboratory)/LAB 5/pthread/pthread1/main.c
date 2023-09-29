#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define NUM_THREADS	5


int main(int argc, char *argv[])
{
  long long int a,b,c,d;
  a = pow(31,5);
  c= a%91;
  printf("%d",c);
}

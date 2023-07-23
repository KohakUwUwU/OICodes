#include<stdio.h>
#include<math.h>
double d=300000,p=6000,r=0.01;
int main()
{
	printf("m=%.1lf",(log10(p)-log10(p-d*r))/log10(1.0+r));
}

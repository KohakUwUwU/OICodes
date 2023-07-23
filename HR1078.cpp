#include<stdio.h>
int main()
{
	long long k=0,sum=1;
	for(int i=1;i<=20;i++)
	{
		sum*=i;
		k+=sum;
	}
	printf("%ld",k);
}

#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	long long k=0,sum=1;
	for(int i=1;i<=n;i++)
	{
		sum*=i;
		k+=sum;
	}
	printf("%ld",k);
}

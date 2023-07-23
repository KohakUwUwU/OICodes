#include<stdio.h>
int main()
{
	long long a;
	scanf("%lld",&a);
	for(register int i=1;i*i<=a;i++)printf("%lld ",i*i);
}

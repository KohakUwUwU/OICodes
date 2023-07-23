#include<stdio.h>
int n;
inline int prime()
{
	for(int i=2;i*i<=n;i++)if(n%i==0)return 2;
	return 1;
}
int main()
{
	scanf("%d",&n);
	if(prime()==1)printf("prime\n");
	else printf("not prime\n");
}

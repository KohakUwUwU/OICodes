#include<stdio.h>
inline int prime(int k)
{
	for(int i=2;i*i<=k;i++)if(k%i==0)return 0;
	return 1;
}
int main()
{
	for(int i=100;i<=200;i++)
	{
		if(prime(i)==1)printf("%d\n",i);
	}
}

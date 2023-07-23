#include<stdio.h>
int a[201];
inline void prime()
{
	for(int i=2;i<=200;i++)
	{
		if(i==1)continue;
		for(int j=i*i;j<=200;j+=i)a[j]=1;
	}
}
int main()
{
	prime();
	for(int i=100;i<=200;i++)if(a[i]==0)printf("%d\n",i);
}

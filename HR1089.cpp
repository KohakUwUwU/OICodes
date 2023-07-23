#include<stdio.h>
int n,a[102];
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(a[i]==0)
		{
			for(int j=i*i;j<=n;j+=i)a[j]=1;
		}
	}
	for(int i=2;i<=n;i++)if(a[i]==0)printf("%d\n",i);
}

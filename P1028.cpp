#include<stdio.h>
int a[1001]={1,1},n;
int main()
{
	for(int i=2;i<=1000;i++)
	{
		if(i%2)a[i]=a[i-1];
		else a[i]=a[i-1]+a[i/2];
	}
	scanf("%d",&n);
	printf("%d",a[n]);
}

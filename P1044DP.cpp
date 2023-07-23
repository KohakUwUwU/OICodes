#include<stdio.h>
short n,i,j;
int f[19]={1};
int main()
{
	scanf("%hd",&n);
	for(i=1;i<=n;i++)for(j=1;j<=i;j++)f[j]+=f[j-1];
	printf("%d",f[n]);
}

#include<stdio.h>
short i,j,t,m,w,c;
short f[1001];
int main()
{
	scanf("%hd%hd",&t,&m);
	for(;i<m;i++)
	{
		scanf("%hd%hd",&w,&c);
		for(j=t;j>=w;j--)f[j]=f[j]>f[j-w]+c?f[j]:f[j-w]+c;
	}
	printf("%hd",f[t]);
}

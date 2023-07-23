#include<stdio.h>
int i,j,m,n,w[26],c[26],f[50001];
int main()
{
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)scanf("%d%d",&w[i],&c[i]),c[i]*=w[i];
	for(i=1;i<=n;i++)for(j=m;j>=w[i];j--)f[j]=f[j]>f[j-w[i]]+c[i]?f[j]:f[j-w[i]]+c[i];
	printf("%d",f[m]);
}

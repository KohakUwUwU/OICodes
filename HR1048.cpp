#include<stdio.h>
int main()
{
	int a[3],maxx=-1;
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	for(int i=0;i<2;i++)maxx=a[i]>maxx?a[i]:maxx;
	printf("%d",maxx);
}

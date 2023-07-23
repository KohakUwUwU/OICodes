#include<stdio.h>
int a[4][4],sum=0;
int main()
{
	for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=3;i++)sum+=a[i][i];
	printf("%d",sum);
}

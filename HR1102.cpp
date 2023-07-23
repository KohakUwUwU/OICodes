#include<stdio.h>
int main()
{
	int a[4][4],b[4][4];
	for(int i=1;i<=2;i++)for(int j=1;j<=3;j++)scanf("%d",&a[i][j]),b[j][i]=a[i][j];
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=2;j++)printf("%d ",b[i][j]);
		printf("\n");
	}
}

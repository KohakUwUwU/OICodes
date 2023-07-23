#include<stdio.h>
int main()
{
	int a[5][5],maxx=-1,ii,jj;
	for(int i=1;i<=3;i++)for(int j=1;j<=4;j++)
	{
		scanf("%d",&a[i][j]);
		if(maxx<a[i][j])
		{
			maxx=a[i][j];
			ii=i;
			jj=j;
		}
	}
	printf("%d\n%d\n%d\n",maxx,ii-1,jj-1);
}

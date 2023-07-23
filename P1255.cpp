#include<cstdio>
using namespace std;
int n,a[5001][5001];
bool pd;
int main()
{
	a[0][1]=0;
	a[1][1]=1;
	a[2][1]=2;
	scanf("%d",&n);
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<1200;j++) 
		a[i][j]=a[i-1][j]+a[i-2][j];
		for(int j=1;j<1200;j++)
		{
			while(a[i][j]>9)
			{
				a[i][j+1]++;
				a[i][j]-=10;
			}
		}
	}
	for(int i=1200;i>1;i--)
	{
		if(!pd&&a[n][i]==0)continue;
		pd=1;
		printf("%d",a[n][i]);
	}
	printf("%d",a[n][1]);
}

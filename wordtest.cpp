#include<iostream>
using namespace std;
int n,m,d,X[10],ans[501][1<<11],sum[501][1<<11];
int main()
{
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	cin>>n>>m>>d;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		X[b-1]|=(1<<(a-1));
	}
	for(int i=0;i<d;i++)ans[1][1<<i]=1,sum[1][1<<i]=i;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<1<<d;j++)
		{
			if(!ans[i][j])continue;
			for(int k=0;k<d;k++)
			{
				if(!(j&X[k]))
				{
					ans[i+1][j|(1<<k)]+=ans[i][j];
					sum[i+1][j|(1<<k)]+=sum[i][j]*10+ans[i][j]*(k+1);
				}
			}
		}
	}
	int ans1=0,ans2=0;
	for(int i=0;i<1<<d;i++)ans1+=ans[n][i],ans2+=sum[n][i];
	cout<<ans1<<'\n'<<ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

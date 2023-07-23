#include<iostream>
#include<map>
using namespace std;
int m,n,maxTeam;
map<int,map<int,int> >w,c;
map<int,int>dp;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		register int a,b,cc;
		cin>>a>>b>>cc;
		maxTeam=max(maxTeam,cc);
		w[cc][++w[cc][0]]=a;
		c[cc][++c[cc][0]]=b;
	}
	for(int i=1;i<=maxTeam;i++)
	{
		for(int j=m;j>=1;j--)
		{
			for(int k=1;k<=w[i][w[i][0]];k++)
			{
				if(w[i][k]>=j)dp[j]=max(dp[j],dp[j-w[i][k]]+c[i][k]);
			}
		}
	}
	cout<<dp[m];
}

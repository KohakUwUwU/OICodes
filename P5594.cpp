#include<iostream>
using namespace std;
int n,m,k,vis[1001][1001],a,cnt;
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a,vis[a][j]=1;
	for(int i=1;i<=k;i++)
	{
		cnt=0;
		for(int j=1;j<=1000;j++)if(vis[i][j])cnt++;
		cout<<cnt<<' ';
	}
}

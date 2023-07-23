//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1505;
int n,m;
int dx[10]={0,1,1,1,-1,-1,-1,0,0};
int dy[10]={0,1,0,-1,1,0,-1,1,-1};
char ma[N][N];
int bin[(int)1e5+5];
inline int dfs(int x,int y)
{
	int ret=0;
	for(int i=1;i<=8;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(ma[xx][yy]=='.'||ma[xx][yy]==0)continue;
		ma[xx][yy]='.';
		ret+=1+dfs(xx,yy);
	}
	return ret;
}
signed main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		for(int j=1;j<=m;j++)ma[i][j]=str[j-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ma[i][j]=='.')continue;
			bin[dfs(i,j)]++;
		}
	}
	int ans=0,cnt=0;
	for(int i=0;i<=1e5;i++)
	{
		ans=max(ans,bin[i]*i);
		if(bin[i])cnt++;
	}
	cout<<cnt<<' '<<ans;
	return 0;
}

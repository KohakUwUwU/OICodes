//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=25;
int n,m;
int vis[N],q[N];
inline void dfs(int step)
{
	if(step==m+1)
	{
		for(int i=1;i<=m;i++)cout<<fixed<<setw(3)<<q[i];
		cout<<'\n';
		return ;
	}
	for(int i=q[step-1]+1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		q[step]=i;
		dfs(step+1);
		vis[i]=0;
	}
}
signed main()
{
	cin>>n>>m;
	dfs(1);
	return 0;
}


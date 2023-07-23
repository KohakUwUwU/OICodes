//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=10;
int n;
int vis[N],q[N];
inline void dfs(int step)
{
	if(step==n)
	{
		for(int i=1;i<=n;i++)cout<<fixed<<setw(5)<<q[i];
		cout<<'\n';
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		q[step+1]=i;
		dfs(step+1);
		vis[i]=0;
	}
}
signed main()
{
	cin>>n;
	dfs(0);
	return 0;
}


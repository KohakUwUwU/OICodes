//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e5+5;
int n,k,ans,cnt[1<<20],vis[N];
vector<int>G[N],E[N];
inline void addEdge(int x,int y,int val)
{
	G[x].push_back(y),G[y].push_back(x);
	E[x].push_back(val),E[y].push_back(val);
}
inline void dfs(int p,int val)
{
	vis[p]=1;
	cnt[val]++;
	ans+=cnt[val^k];
	for(int i=0;i<G[p].size();i++)if(!vis[G[p][i]])dfs(G[p][i],val^E[p][i]);
}
signed main()
{
	freopen("xor1.in","r",stdin);
	freopen("xor1.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1,a,b,c;i<n;i++)scanf("%lld%lld%lld",&a,&b,&c),addEdge(a,b,c);
	dfs(1,0);
	if(k==0)ans-=n;
	printf("%lld",ans);
	return 0;
}


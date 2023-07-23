//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e5+5;
int n,m,clr[N],cnt[N],q[N],ans[N];
vector<int> be[N],en[N];
signed main()
{
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&clr[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%lld%lld%lld",&x,&y,&q[i]);
		be[x-1].push_back(i),en[y].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		cnt[clr[i]]++;
		for(int j=0;j<be[i].size();j++)ans[be[i][j]]-=cnt[q[be[i][j]]];
		for(int j=0;j<en[i].size();j++)ans[en[i][j]]+=cnt[q[en[i][j]]];
	}
	for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
	return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5;
struct num
{
	int val,cnt;
	bool operator<(num x)const
	{
		return cnt>x.cnt||cnt==x.cnt&&val<x.val;
	}
};
set<num> s;
int m,mx,cnt[N];
inline input()
{
	scanf("%lld",&m);
}
inline int me()
{
	int mxnum=0,ans=0;
	for(int i=1;i<=mx;i++)
	{
		if(cnt[i]>mxnum)mxnum=cnt[i],ans=i;
	}
	if(ans)return ans;
	else return 1;
}
inline void solveBF()
{
	for(int i=1;i<=m;i++)
	{
		int op,val;
		scanf("%lld%lld",&op,&val);
		mx=max(mx,val);
		if(op==1)cnt[val]++;
		else if(cnt[val])cnt[val]--;
		printf("%lld\n",me());
	}
}
inline void solve()
{
	for(int i=1;i<=m;i++)
	{
		int opt,val;
		scanf("%lld%lld",&opt,&val);
		if(opt==1)
		{
			s.erase((num){val,cnt[val]});
			cnt[val]++;
			s.insert((num){val,cnt[val]});
		}
		else 
		{
			s.erase((num){val,cnt[val]});
			if(cnt[val])cnt[val]--;
			s.insert((num){val,cnt[val]});
		}
		printf("%lld\n",(!s.empty()?s.begin()->val:1));
	}
}
signed main()
{
	freopen("mode.in","r",stdin);
	freopen("modeSOLVE.out","w",stdout);
	input();
	solve();
	return 0;
}

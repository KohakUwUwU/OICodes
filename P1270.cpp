//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1e5;
struct node
{
	int ch[3],t[3],fa,cnt,val;
}t[N];
int plc,cnt=1,ok[N][605],f[N][605];
inline void input(int x,int fa,int c,int val)
{
//	cout<<"input("<<x<<','<<fa<<','<<c<<','<<val<<")\n";
	t[x].fa=fa;t[x].cnt=c;t[x].val=val;
	for(int cur=1,mode;cur<=c;++cur)
	{
		t[x].ch[cur]=++cnt;
		scanf("%lld%lld",&t[x].t[cur],&mode);
		if(!mode)input(t[x].ch[cur],x,2,0);
		else input(t[x].ch[cur],x,0,mode);
	}
}
inline int DP(int p,int remain)
{
//	cout<<"DP("<<p<<','<<remain<<")\n";
	if(ok[p][remain])return f[p][remain];
	ok[p][remain]=1;
	if(remain<5)return 0;
	if(t[p].cnt==0)
	{
		f[p][remain]=((t[p].val*5<=remain)?(t[p].val):(remain/5));
		return f[p][remain];
	}
	else if(t[p].cnt==1)
	{
		f[p][remain]=DP(t[p].ch[1],remain-2*t[p].t[1]);
		return f[p][remain];
	}
	else 
	{
		int ans=0;
		for(int tm=0;tm<=remain;tm++)
		{
			ans=max(ans,DP(t[p].ch[1],tm-2*t[p].t[1])+DP(t[p].ch[2],remain-tm-2*t[p].t[2]));
		}
		f[p][remain]=ans;
		return ans;
	}
}
signed main()
{
	scanf("%lld",&plc);
	input(1,0,1,0);
//	cout<<"48910y74891";
	cout<<DP(1,plc-1);
	return 0;
}


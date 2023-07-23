//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int n,m,r[N],d[N],s[N],t[N],cf[N];
inline bool check(int x)
{
	memset(cf,0,sizeof(cf));
	for(int i=1;i<=x;i++)cf[s[i]]+=d[i],cf[t[i]+1]-=d[i];
	if(cf[1]>r[1])return 1;
	for(int i=2;i<=n;i++)
	{
		cf[i]+=cf[i-1];
		if(cf[i]>r[i])return 1;
	}
	return 0;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>r[i];
	for(int i=1;i<=m;i++)cin>>d[i]>>s[i]>>t[i];
	int l=1,r=m;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(m==r)cout<<0;
	else cout<<"-1\n"<<r;
	return 0;
}


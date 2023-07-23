//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e6+1,INF=0x3f3f3f3f;
int n,m,t,h[N],p[N];
inline bool checkA()
{
	for(int i=1;i<=n;i++)if(h[i]<=t)return false;
	return true;
}
inline bool checkB()
{
	for(int i=1;i<=n;i++)if(h[i]!=1&&h[i]!=t-1&&h[i]!=t+1)return false;
	return true;
}
int f3[N];
inline void sub3()
{
	for(int i=1;i<=n;i++)
	{
		if(h[i]==t+1)
		{
			f3[i]=1;
			continue;
		}
		if(f3[i-1]==1&&h[i-1]!=1)f3[i]=1;
		if(h[i]==1&&h[i+1]==1&&h[i-1]==1)f3[i]=0;
	}
	for(int i=n;i>=1;i--)
	{
		if(h[i]==t+1)
		{
			f3[i]=1;
			continue;
		}
		if(f3[i+1]==1&&h[i+1]!=1)f3[i]=1;
		if(h[i]==1&&h[i+1]==1&&h[i-1]==1)f3[i]=0;
	}
	int cnt=0;
	bool ok=false;
	for(int i=1;i<=n;i++)if(!f3[i])ok=1,cnt++;
	cout<<cnt+(ok==1);
}
signed main()
{
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=m;i++)cin>>p[i];
	if(checkA())cout<<0;
	else if(checkB())sub3();
	return 0;
}


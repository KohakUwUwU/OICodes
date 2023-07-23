//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,a[N],pos[N],s[N],top;
pair<int,int>p[N];
inline void Search(int u,int v,int ans)
{
	if(u)Search(p[u].first,0,ans),Search(p[u].second,1,ans+(!v));
	else cout<<ans<<'\n';
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		while(top&&pos[i]<=pos[s[top]])p[i].first=s[top--];
		if(top)p[s[top]].second=i;
		s[++top]=i;
	}
	Search(s[1],-1,0);
}
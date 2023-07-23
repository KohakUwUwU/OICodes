//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n;
pair<int,int>p[N];
int pre[N],suc[N];
bool judge()
{
	for(int i=2;i<=n;i++)
	{
		if(p[i].second<p[i-1].second)return false;
	}
	return true;
}
signed main()
{
	freopen("duty.in","r",stdin);
	freopen("duty.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+n);
	if(judge())
	{
		pre[1]=p[1].second-p[1].first;
		for(int i=2;i<=n;i++)
		{
			pre[i]=pre[i-1]+p[i].second-p[i].first;
			if(p[i].first<p[i-1].second)pre[i]-=p[i-1].second-p[i].first;
		}
		suc[n]=p[n].second-p[n].first;
		for(int i=n-1;i>=1;i--)
		{
			suc[i]=suc[i+1]+p[i].second-p[i].first;
			if(p[i].second>p[i+1].first)suc[i]-=p[i].second-p[i+1].first;
		}
//		for(int i=1;i<=n;i++)cout<<pre[i]<<' ';
//		cout<<'\n';
//		for(int i=1;i<=n;i++)cout<<suc[i]<<' ';
//		cout<<'\n';
		int ans=max(pre[n-1],suc[2]);
		for(int i=2;i<=n-1;i++)
		{
			int ret=pre[i-1]+suc[i+1];
			if(p[i-1].second>p[i+1].first)ret-=p[i-1].second-p[i+1].first;
			ans=max(ans,ret);
		}
		cout<<ans;
	}
	else
	{
		pair<int,int>cur=p[1];
		int ans=0;
//		cout<<cur.first<<' '<<cur.second<<' '<<ans<<'\n';
		for(int i=2;i<=n;i++)
		{
			if(cur.first<=p[i].first&&p[i].first<=cur.second&&cur.second<=p[i].second)
			{
				cur.second=p[i].second;
			}
			else if(cur.first<=p[i].first&&p[i].second<=cur.second)continue;
			else
			{
				ans+=cur.second-cur.first;
				cur=p[i];
			}
//		cout<<cur.first<<' '<<cur.second<<' '<<ans<<'\n';
		}
		cout<<ans+cur.second-cur.first;
	}
	return 0;
}


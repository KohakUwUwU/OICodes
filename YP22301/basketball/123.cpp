//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n;
pair<int,int>p[N];
inline void MergeAll()
{
	int ans=0;
	pair<int,int>cur=p[1];
	for(int i=2;i<=n;i++)
	{
		if(cur.second>p[i].first)
		{
			cur.second=max(p[i].second,cur.second);
		}
		else
		{
			ans+=cur.second-cur.first;
			cur=p[i];
		}
	}
	cout<<ans;
}
int preans[N],sucans[N];
inline void DeleteOne()
{
	int ans=0;
	pair<int,int>cur=p[1];
	preans[1]=cur.second-cur.first;
	for(int i=2;i<=n;i++)
	{
		if(cur.second>p[i].first)
		{
			cur.second=max(p[i].second,cur.second);
		}
		else
		{
			ans+=cur.second-cur.first;
			cur=p[i];
		}
		preans[i]=ans+cur.second-cur.first;
	}
	cur=p[n];
	sucans[n]=cur.second-cur.first;
	for(int i=n-1;i>=1;i--)
	{
		if(cur.first<p[i].second)
		{
			cur.first=min(p[i].first,cur.first);
		}
		else
		{
			ans+=cur.second-cur.first;
			cur=p[i];
		}
		sucans[i]=ans+cur.second-cur.first;
	}
	ans=max(preans[n-1],sucans[2]);
	for(int i=2;i<=n-1;i++)
	{
		int ret=preans[i-1]+sucans[i+1];
		if(p[i-1].second>p[i+1].first)ret-=p[i-1].second-p[i+1].first;
		ans=max(ans,ret);
	}
	cout<<ans;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+n);
	bool b=false;
	for(int i=2;i<=n;i++)
	{
		if(p[i].second>p[i-1].second)b=true;
	}
	if(b)MergeAll();
	else DeleteOne();
	return 0;
}


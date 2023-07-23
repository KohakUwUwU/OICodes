//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,s,a[N];
inline bool ok(int k)
{
	priority_queue<int>q;
	int ans=0;
	for(int i=1;i<=n;i++)q.push(-(a[i]+k*i));
	for(int i=1;i<=k;i++)ans+=-q.top(),q.pop();
	if(ans>s)return 0;
	else return 1;
}
signed main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	int cur=0;
	for(int i=10;i>=0;i--)
	{
		int cc=cur+(1<<i);
		if(cc>n)continue;
		if(ok(cc))cur+=(1<<i);
	}
	int k=cur;
	cout<<k<<' ';
	priority_queue<int>q;
	int ans=0;
	for(int i=1;i<=n;i++)q.push(-(a[i]+k*i));
	for(int i=1;i<=k;i++)ans+=-q.top(),q.pop();
	cout<<ans;
	return 0;
}


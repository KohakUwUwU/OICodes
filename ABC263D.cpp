//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int a[N],n,l,r,pre[N],fx[N],prefx[N],fy[N],prefy[N];
priority_queue<int,vector<int>,greater<int> >q;
signed main()
{
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)cin>>a[i],pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++)fx[i]=l-a[i];
	for(int i=1;i<=n;i++)prefx[i]=prefx[i-1]+fx[i];
	for(int i=n;i>=1;i--)fy[i]=r-a[i];
	for(int i=n;i>=1;i--)prefy[i]=prefy[i+1]+fy[i];
	int ans=prefx[n];
	q.push(0);
	for(int i=n-1;i>=0;i--)
	{
		q.push(prefy[i+1]);
		ans=min(ans,q.top()+prefx[i]);
	}
	cout<<ans+pre[n];
	return 0;
}


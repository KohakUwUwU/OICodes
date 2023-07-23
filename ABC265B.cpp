//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,m,lmt,a[N],x[N],y[N],bonus[N];
signed main()
{
	cin>>n>>m>>lmt;
	n--;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>x[i]>>y[i],bonus[x[i]]=y[i];
	for(int i=1;i<=n;i++)
	{
		lmt+=bonus[i];
		if(lmt-a[i]<=0)
		{
			cout<<"No";
			return 0;
		}
		lmt-=a[i];
	}
	cout<<"Yes";
	return 0;
}


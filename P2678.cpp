//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e4+5;
int L,n,m,a[N],cf[N];
inline bool check(int x)
{
	int temp=0,cnt=0;
	for(int i=1;i<=n+1;i++)
	{
		if(temp+cf[i]<x)temp+=cf[i],cnt++;
		else temp=0;
//		cout<<temp<<' '<<cnt<<"        ";
	}
//	cout<<'\n';
	if(cnt<=m)return true;
	return false;
}
signed main()
{
	cin>>L>>n>>m;
	cf[n+1]=L;
	for(int i=1;i<=n;i++)cin>>a[i],cf[i]=a[i]-a[i-1];
	cf[n+1]=L-a[n];
//	for(int i=1;i<=n+1;i++)cout<<cf[i]<<' ';
//	cout<<'\n';
	int l=1,r=L;
	while(l!=r)
	{
//		cout<<l<<' '<<r<<'\n';
		int mid=l+r>>1;
		if(check(mid))l=mid;
		else r=mid;
		if(r-l==1)
		{
			int aa=check(l),bb=check(r);
			if(aa&&bb)l=r;
			else r=l;
			continue;
		}
	}
	cout<<l;
	return 0;
}


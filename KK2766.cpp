//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=114514;
int n,a[N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int xx=a[n];
	a[n]=-1;
	for(int i=n-1;i>=1;i--)a[i]=xx,xx=max(a[i],xx);
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,p[N],t[N],pos,neg;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)cin>>t[i],p[i]=p[i]-t[i],t[i]=p[i]-p[i-1];
	for(int i=1;i<=n;i++)(t[i]>0)?(pos+=t[i]):(neg+=-t[i]);
	cout<<max(pos,neg);
}

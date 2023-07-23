//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5,INF=(1ll<<31)-1;
int n,k,len[100],p[N],ans=INF;
vector<int>a[100];
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>len[i];
		for(int j=1,x;j<=len[i];j++)cin>>x,a[i].push_back(x);
		sort(a[i].begin(),a[i].end());
	}
	while(1)
	{
		int mx=0,mn=INF,k1,k2;
		for(int i=1;i<=k;i++)
		{
			if(a[i][p[i]]>mx) mx=a[i][p[i]],k1=i;
			if(a[i][p[i]]<mn) mn=a[i][p[i]],k2=i;
		}
		ans=min(ans,mx-mn);
		p[k2]++;
		if(p[k2]==len[k2])break;
	}
	cout<<ans;
	return 0;
}

//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF=1e9;
int n;
signed main()
{
	freopen("guess.in","r",stdin);
	freopen("guess.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a+b>INF&&a-b<1)cout<<"-2\n";
		else if(a+b<=INF&&a-b>=1)cout<<"-1\n";
		else if(a+b<=INF)cout<<a+b<<'\n';
		else cout<<a-b<<'\n';
	}
	return 0;
}


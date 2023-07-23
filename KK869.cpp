//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,ans;
signed main()
{
	freopen("merchant.in","r",stdin);
	freopen("merchant.out","w",stdout);
	cin>>n;
	for(int l=1,r;l<=n;l=r+1)
	{
		int val=n/l;
		r=n/val;
		ans+=val*(r-l+1);
	}
	cout<<ans;
	return 0;
}


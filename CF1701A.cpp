//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int t;
	cin>>t;
	while(t--) 
	{
		int a[5],cnt=0;
		for(int i=1;i<=4;i++)cin>>a[i],cnt+=a[i];
		if(cnt==4)cout<<2<<'\n';
		else if(cnt>0)cout<<1<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}


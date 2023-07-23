//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	signed a[6];
	while(1)
	{
		for(int i=1;i<=5;i++)cin>>a[i];
		for(int i=1;i<=5;i++)cout<<bitset<32>(a[i])<<endl;
		cout<<endl<<bitset<32>(a[1]^a[2]^a[3]^a[4])<<endl<<(a[1]^a[2]^a[3]^a[4])<<endl<<(a[1]^a[2]^a[3]^a[4]^a[5])<<endl;
	}
	return 0;
}


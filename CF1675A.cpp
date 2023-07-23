//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c,x,y;
		cin>>a>>b>>c>>x>>y;
		if(a<=x)
		{
			if(c<(x-a))
			{
				cout<<"NO\n";
				continue;
			}
			else c-=(x-a);
		}
		if(c+b<y)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}


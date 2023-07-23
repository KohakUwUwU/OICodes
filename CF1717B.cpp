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
		int n,k,r,c;
		cin>>n>>k>>r>>c;
		int mov=(n-r-c+1+2*n)%k;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if((n-i-j+1+2*n)%k==mov)cout<<"X";
				else cout<<'.';
			}
			cout<<'\n';
		}
	}
	return 0;
}


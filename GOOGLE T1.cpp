//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

int t;
signed main()
{
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		int n,m;
		cin>>n>>m;
		cout<<"Case #"<<tt<<":\n";
		for(int i=1;i<=n*2+1;i++)
		{
			for(int j=1;j<=m*2+1;j++)
			{
				if(i==1&&j==1||i==1&&j==2||i==2&&j==1)
				{
					cout<<".";
					continue;
				}
				if(i%2==0&&j%2==0)
				{
					cout<<".";
					continue;
				}
				if(i%2==0)
				{
					cout<<"|";
					continue;
				}
				if(j%2==0)
				{
					cout<<"-";
					continue;
				}
				cout<<"+";
			}
			cout<<'\n';
		}
	}
	return 0;
}

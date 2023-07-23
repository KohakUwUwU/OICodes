//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e3+5;
string str[4][N];
unordered_map<string,int>ma;
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ma.clear();
		int n;
		cin>>n;
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>str[i][j];
				ma[str[i][j]]++;
			}
		}
		for(int i=1;i<=3;i++)
		{
			int ans=0;
			for(int j=1;j<=n;j++)
			{
				if(ma[str[i][j]]==1)ans+=3;
				if(ma[str[i][j]]==2)ans+=1;
			}
			cout<<ans<<' ';
		}
		cout<<'\n';
	}
	return 0;
}


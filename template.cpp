//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		vector<int>G;
		for(int j=1;j<i;j++)
		{
			if(i%j==0)G.push_back(j),cnt+=j;
		}
		if(cnt==i)
		{
			cout<<i<<' ';
			for(int j=0;j<G.size();j++)cout<<G[j]<<' ';
			cout<<'\n';
		}
	}
	return 0;
}
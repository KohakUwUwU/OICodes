//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,cnt;
vector<int>G;
signed main()
{
	cin>>n;
	for(int i=max(0ll,n-100);i<=n;i++)
	{
		int tmp=i;
		int aa=0;
		while(tmp)aa+=tmp%10,tmp/=10;
		if(aa+i==n)G.push_back(i);
	}
	cout<<G.size()<<'\n';
	for(int i=0;i<G.size();i++)cout<<G[i]<<' ';
	return 0;
}


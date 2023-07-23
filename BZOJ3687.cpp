//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5;
int n,ans;
bitset<N>f;
signed main()
{
	int n;
	cin>>n;
	f[0]=1;
	for(int i=1,x;i<=n;++i)cin>>x,f=f^(f<<x);
	for(int i=1;i<=N-5;++i)if(f[i])ans^=i;
	cout<<ans;
	return 0;
}


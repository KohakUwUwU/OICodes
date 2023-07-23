//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e3+5;
const int MOD=998244353;
int n,m,l[N],r[N],bin[N];
inline bool checklr()
{
	for(int i=1;i<=m;i++)
	{
		bin[l[i]]=1;
		if(l[i]!=r[i])return false;
	}
	return true;
}
inline int sub3()
{
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		if(bin[i])(ans*=4)%=MOD;
		else (ans*=7)%=MOD;
	}
	return ans;
}
signed main()
{
	freopen("product.in","r",stdin);
	freopen("product.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>l[i]>>r[i];
	}
	if(checklr())cout<<sub3();
	else cout<<114514;
	return 0;
}


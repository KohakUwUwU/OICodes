//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
const int MOD=1e9+7;
int n,a[N],f[1<<21];
inline int lowbit(int k)
{
	return k&-k;
}
inline int pop(int k)
{
	int cnt=0;
	while(k)k-=lowbit(k),cnt++;
	if(cnt&1)return 1;
	else return -1;
}
inline int qpow(int k)
{
	int mul=2,ans=1;
	for(int i=0;i<=25;i++)
	{
		if(k&(1<<i))(ans*=mul)%=MOD;
		(mul*=mul)%=MOD;
	}
	return ans;
}
signed main()
{
//	freopen("teams.in","r",stdin);
//	freopen("teams.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],f[a[i]]++;
	for(int p=0;p<20;p++)
	{
		for(int msk=0;msk<(1<<20);msk++)
		{
			if(((msk>>p)&1)==0)f[msk]+=f[msk^(1<<p)];
		}
	}
	//此时f_i含义为同时拥有缺点集合i的人总共有多少 
	for(int msk=0;msk<(1<<20);msk++)(f[msk]=qpow(f[msk])-1+MOD)%=MOD;
	int sum=0;
	for(int i=0;i<(1<<20);i++)(((sum+=pop(i)*f[i])%=MOD)+=MOD)%=MOD;
	cout<<-(sum-MOD);
	return 0;
}


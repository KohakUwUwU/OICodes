//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
const int INF=1e9;
int frst[N*2];
int n,m,x[N],cnt[N],CNT[N];
inline int bst(int a,int b)
{
	int len=0,sum=0;
	for(int v=0;v<=n*2;v++)frst[v]=INF;
	frst[n]=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]==a)sum++;
		else if(x[i]==b)sum--;
		if(frst[sum+n]==INF)frst[sum+n]=i;
		else len=max(len,i-frst[sum+n]);
	}
	return len;
}
inline int creep(int c)
{
	memset(cnt,0,sizeof(cnt));
	int cnt_c=0,res=0,l=1;
	for(int r=1;r<=n;r++)
	{
		cnt[x[r]]++;
		if(cnt[x[r]]==c)cnt_c++;
		while(l<=r&&cnt[x[r]]>c)
		{
			if(cnt[x[l]]==c)cnt_c--;
			cnt[x[l]]--;
			l++;
		}
		if(cnt_c>=2)res=max(res,r-l+1);
	}
	return res;
}
inline void solve()
{
	memset(cnt,0,sizeof(cnt));
	memset(CNT,0,sizeof(CNT));
	int mode=0;
	for(int i=1;i<=n;i++)
	{
		CNT[cnt[x[i]]]--;
		cnt[x[i]]++;
		CNT[cnt[x[i]]]++;
		if(cnt[x[i]]>cnt[mode])mode=x[i];
	}
	if(CNT[cnt[mode]]>=2)
	{
		printf("%lld",n);
		return ;
	}
	int L=sqrt(n),ans=0;
	for(int v=1;v<=n;v++)if(cnt[v]>L&&v!=mode)ans=max(ans,bst(mode,v));
	for(int c=1;c<=L;c++)ans=max(ans,creep(c));
	printf("%lld",ans);
}
signed main()
{
	freopen("cooperation.in","r",stdin);
	freopen("cooperation.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	solve();
	return 0;
}


#include<bits/stdc++.h>
//#define int long long
using namespace std;
int fa[100003],a[10003];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool f[10003];
int cnt;
signed main()
{
	long long x,y,n;
	cin>>n>>x>>y;
	for(int i=1; i<=n; i++) cin>>a[i],fa[i]=i;
	if(x==y) printf("%lld\n",x*(n-1)),exit(0);
	else if(x<y)
	{
		for(int i=1; i<n; i++) for(int j=i+1; j<=n; j++) 
		{
			int x=a[i]^a[j],p,q;
			if(__builtin_popcount(x)==1) p=find(i),q=find(j),(p!=q)&&(fa[p]=q);
		}
		for(int i=1; i<=n; i++) if(!f[find(i)]) f[find(i)]=1,++cnt;
		printf("%lld\n",y*(cnt-1)+x*(n-cnt));
	}
	else 
	{
		for(int i=1; i<n; i++) for(int j=i+1; j<=n; j++) 
		{
			int x=a[i]^a[j],p,q;
			if(__builtin_popcount(x)>1) p=find(i),q=find(j),(p!=q)&&(fa[p]=q);
		}
		for(int i=1; i<=n; i++) if(!f[find(i)]) f[find(i)]=1,++cnt;
		printf("%lld\n",x*(cnt-1)+y*(n-cnt));
	}
}       

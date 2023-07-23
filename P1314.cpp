//TEmPTaTiON
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,a,b) for(register int i=a;i<=b;++i)

const int neko=3e5+7;
struct node
{
    int l,r;
}q[neko];
int n,m,l,r,mid,minn=114514114514,maxn,w[neko],c[neko];
int stdd,sum,ans=1e13,v[neko],s[neko];
signed main()
{
    cin>>n>>m>>stdd;
    f(i,1,n)cin>>w[i]>>v[i],minn=std::min(minn,w[i]),maxn=std::max(maxn,w[i]);
    l=minn-1,r=maxn+1;
    f(i,1,m)cin>>q[i].l>>q[i].r;
    while(l<r)
    {
        mid=(l+r)>>1,sum=0,memset(c,0,sizeof(c)),memset(s,0,sizeof(s));
        f(i,1,n)
        {
            if(w[i]>=mid)c[i]=c[i-1]+1,s[i]=s[i-1]+v[i];
            else c[i]=c[i-1],s[i]=s[i-1];
        }
        f(i,1,m)sum+=(c[q[i].r]-c[q[i].l-1])*(s[q[i].r]-s[q[i].l-1]);
        if(llabs(stdd-sum)<ans)ans=llabs(stdd-sum);
        if(sum>stdd)l=mid+1;
        else r=mid;
    }
    cout<<ans;
    return 0;
}

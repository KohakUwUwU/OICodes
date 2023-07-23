#include<bits/stdc++.h>
using namespace std;
const int maxn=1100010;
int n,op,x,q,lstans,ans;
double a=0.725;
int rt,cur,val[maxn],lc[maxn],rc[maxn],cnt[maxn],siz[maxn],siz2[maxn],sum[maxn];
int t,g[maxn];
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void print(int x){if(!x)return;print(lc[x]);if(cnt[x])g[++t]=x;print(rc[x]);}
void maintain(int x)
{
    siz[x]=siz[lc[x]]+siz[rc[x]]+(cnt[x]?1:0);
    siz2[x]=siz2[lc[x]]+siz2[rc[x]]+1;
    sum[x]=sum[lc[x]]+sum[rc[x]]+cnt[x];
}
int build(int l,int r)
{
    if(l>r)return 0;
    if(l==r){lc[g[l]]=rc[g[l]]=0;maintain(g[l]);return g[l];}
    int mid=(l+r)>>1;
    lc[g[mid]]=build(l,mid-1);rc[g[mid]]=build(mid+1,r);
    maintain(g[mid]);
    return g[mid];
}
void rebuild(int&x){t=0;print(x);x=build(1,t);}
bool bad(int x){return sum[x]&&(a*siz2[x]<=max(siz2[lc[x]],siz2[rc[x]])||a*siz2[x]>=siz[x]);}
void insert(int&x,int v)
{
    if(!x){x=++cur;val[x]=v;cnt[x]=1;maintain(x);return;}
    if(v==val[x])cnt[x]++;
    else if(v<val[x])insert(lc[x],v);
    else insert(rc[x],v);
    maintain(x);
    if(bad(x))rebuild(x);
}
void erase(int&x,int v)
{
    if(v==val[x])cnt[x]--;
    else if(v<val[x])erase(lc[x],v);
    else erase(rc[x],v);
    maintain(x);
    if(bad(x))rebuild(x);
}
int rnk(int x,int v)
{
    if(!x)return 1;
    if(v==val[x])return sum[lc[x]]+1;
    if(v<val[x])return rnk(lc[x],v);
    return sum[lc[x]]+cnt[x]+rnk(rc[x],v);
}
int kth(int x,int k)
{ 
    if(!x)return -1;
    if(sum[lc[x]]<k&&k<=sum[lc[x]]+cnt[x])return val[x];
    if(k<=sum[lc[x]])return kth(lc[x],k);
    return kth(rc[x],k-sum[lc[x]]-cnt[x]);
}
int pre(int v){return kth(rt,rnk(rt,v)-1);}
int suf(int v){return kth(rt,rnk(rt,v+1));}
int main()
{
	freopen("submission.in","r",stdin);
	freopen("submission.out","w",stdout);
    t=n=read();
    for(int i=1;i<=n;i++) insert(rt,i);
    for(int i=1;i<=n;i++)
    {
    	int x=read();
    	int t=kth(rt,x);
    	if(i+1>=n)
    	{
    		printf("%d ",t);
		}
        erase(rt,t);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

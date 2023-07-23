//And in that light, I find deliverance.
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e6+51;
struct SegmentTree{
    ll l,r,prefix,suffix,sum,maxn;  
};
SegmentTree tree[MAXN];
ll cnt,qcnt,l,r;
ll num[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline void update(ll node)
{
    ll res;
    tree[node].sum=tree[node<<1].sum+tree[(node<<1)|1].sum;
    tree[node].maxn=max(tree[node<<1].maxn,tree[(node<<1)|1].maxn);
    res=tree[node<<1].suffix+tree[(node<<1)|1].prefix;
    tree[node].maxn=max(tree[node].maxn,res);
    res=tree[node<<1].sum+tree[(node<<1)|1].prefix;
    tree[node].prefix=max(tree[node<<1].prefix,res);
    res=tree[node<<1].suffix+tree[(node<<1)|1].sum;
    tree[node].suffix=max(tree[(node<<1)|1].suffix,res);
}
inline SegmentTree merge(SegmentTree x,SegmentTree y)
{
    SegmentTree res;
    res.sum=x.sum+y.sum;
    res.maxn=max(x.maxn,max(y.maxn,x.suffix+y.prefix));
    res.prefix=max(x.prefix,x.sum+y.prefix);
    res.suffix=max(y.suffix,x.suffix+y.sum);
    return res;
}
inline void create(ll l,ll r,ll node)
{
    tree[node].l=l,tree[node].r=r;
    if(l==r)
    {
        tree[node].sum=tree[node].maxn=num[l];
        tree[node].prefix=tree[node].suffix=num[l];
        return;
    }
    ll mid=(l+r)>>1;
    create(l,mid,node<<1);
    create(mid+1,r,(node<<1)|1);
    update(node);
}
inline SegmentTree queryMax(ll l,ll r,ll node)
{
    if(l<=tree[node].l&&r>=tree[node].r)
    {
        return tree[node];
    }
    ll mid=(tree[node].l+tree[node].r)>>1;
    SegmentTree res;
    if(l>mid)
    {
        return queryMax(l,r,(node<<1)|1);
    }
    if(r<=mid)
    {
        return queryMax(l,r,node<<1);
    }
    else
    {
        SegmentTree x=queryMax(l,r,node<<1),y=queryMax(l,r,(node<<1)|1);
        return merge(x,y);
    }
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
    cnt=read();qcnt=read();
    for(register int i=1;i<=cnt;i++)
    {
        num[i]=read();
    }
    create(1,cnt,1);
    for(register int i=0;i<qcnt;i++)
    {
    	l=read(),r=read();
    	printf("%d\n",queryMax(l,r,1).maxn);
    }
    return 0;
}

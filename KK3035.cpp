//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5; 
struct Node
{
    int l,r,sum;
}tree[3*N];
int a[N],number[N],root[N],node_num;
void maketree(int l,int r,int &node)
{
    node=++node_num;
    if(l==r)return;
    int mid=(l+r)>>1;
    maketree(l,mid,tree[node].l);
    maketree(mid+1,r,tree[node].r);
} 
void addtree(int l,int r,int &node,int pre,int pos)
{
    node=++node_num;
    tree[node]=tree[pre];
    tree[node].sum++;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid)addtree(l,mid,tree[node].l,tree[pre].l,pos);
    else addtree(mid+1,r,tree[node].r,tree[pre].r,pos);
}
int query(int l,int r,int node,int pre,int k)
{
    if(l==r)return l;
    int chal=tree[tree[node].l].sum-tree[tree[pre].l].sum;
    int mid=(l+r)>>1;
    if(k<=chal)return query(l,mid,tree[node].l,tree[pre].l,k);
    else return query(mid+1,r,tree[node].r,tree[pre].r,k-chal);
}
signed main()
{
	freopen("bigk.in","r",stdin);
	freopen("bigk.out","w",stdout);
    int n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),number[i]=a[i];
    sort(number+1,number+1+n);
    int num=unique(number+1,number+1+n)-number-1;
    node_num=0;
    maketree(1,num,root[0]);
    for(int i=1;i<=n;i++)
	{
        int pos=lower_bound(number+1,number+1+num,a[i])-number;
        addtree(1,num,root[i],root[i-1],pos);
    }
    int l,r,k;
    while(m--)
	{
        scanf("%lld%lld%lld",&l,&r,&k);
        int pos=query(1,num,root[r],root[l-1],r-l+2-k);
        printf("%lld ",number[pos]);
    }
    return 0;
}

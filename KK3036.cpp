//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

using namespace std;
const int N=10010;
int n,qe;
struct Q{
    int x,y,k;
}q[10010];
struct tree{
    int sum,l,r;
}tr[400*N];
int lsh[2*N];
char s[2];
int root[N];
int size,a[N],maxn;
int x,y,tx[30],ty[30],numx,numy;
void update(int &now,int x,int l,int r,int v,int pos)
{
    now=++size;
    tr[now]=tr[x];
    tr[now].sum+=v;
    if (l==r) return;
    int mid=l+r>>1;
    if (pos<=mid) update(tr[now].l,tr[x].l,l,mid,v,pos);
    else update(tr[now].r,tr[x].r,mid+1,r,v,pos);
}
void add(int pos,int v)
{
    int npos=lower_bound(lsh+1,lsh+1+maxn,a[pos])-lsh;
    for (int i=pos;i<=n;i+=(i&-i))
        update(root[i],root[i],1,maxn,v,npos);
}
int query(int k,int l,int r)
{
    if (l==r) return l;
    int lsum=0;
    for (int i=1;i<=numx;i++)
        lsum-=tr[tr[tx[i]].l].sum;
    for (int i=1;i<=numy;i++)
        lsum+=tr[tr[ty[i]].l].sum;
    int mid=l+r>>1;
    if (k>lsum)
    {
        for (int i=1;i<=numx;i++)
            tx[i]=tr[tx[i]].r;
        for (int i=1;i<=numy;i++)
            ty[i]=tr[ty[i]].r;
        query(k-lsum,mid+1,r);
    }
    else
    {
        for (int i=1;i<=numx;i++)
            tx[i]=tr[tx[i]].l;
        for (int i=1;i<=numy;i++)
            ty[i]=tr[ty[i]].l;
        query(k,l,mid);
    }
}
int read()
{
    int f=1,x=0;
    char ch;
    ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();if(ch=='-')f=-1;}
    while(ch>='0'&&ch<='9'){
  x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
signed main()
{
	freopen("k.in","r",stdin);
	freopen("k.out","w",stdout);
    n=read();qe=read();
    for (int i=1;i<=n;i++)
        a[i]=read(),lsh[++maxn]=a[i];
    for (int i=1;i<=qe;i++)
    {
        scanf("%s",s);
        q[i].x=read();q[i].y=read();
        if (s[0]=='Q') q[i].k=read();
        else lsh[++maxn]=q[i].y;
    }
    sort(lsh+1,lsh+1+maxn);
    maxn=unique(lsh+1,lsh+1+maxn)-lsh-1;
    for (int i=1;i<=n;i++) add(i,1);
    for (int i=1;i<=qe;i++)
    {
        if (q[i].k)
        {
            numx=numy=0;
            for (int j=q[i].x-1;j;j-=(j&-j))
                tx[++numx]=root[j];
            for (int j=q[i].y;j;j-=(j&-j))
                ty[++numy]=root[j];
            printf("%d\n",lsh[query(q[i].k,1,maxn)]);
        }
        else add(q[i].x,-1),a[q[i].x]=q[i].y,add(q[i].x,1);
    }
    return 0;
} 

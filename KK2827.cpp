#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=4e4+5;
int m;
struct Segment
{
    int l,r,len,lc,rc,val,tag;
}t[M*60];
int cnt=1;
#define mid (l+r>>1)
inline void Expand(int p)
{
    if(t[p].lc)return ;
    t[p].lc=++cnt;
    t[p].rc=++cnt;
    t[t[p].lc]=(Segment){t[p].l,(t[p].l+t[p].r>>1),(t[p].l+t[p].r>>1)-t[p].l+1,0,0,0,0};
    t[t[p].rc]=(Segment){(t[p].l+t[p].r>>1)+1,t[p].r,t[p].r-(t[p].l+t[p].r>>1),0,0,0,0};
}
inline void PushDown(int p)
{
    if(!t[p].tag)return ;
    t[t[p].lc].tag=t[t[p].rc].tag=t[p].tag;
    t[t[p].lc].val=t[t[p].lc].len*t[p].tag;
    t[t[p].rc].val=t[t[p].rc].len*t[p].tag;
    t[p].tag=0;
}
inline void Modify(int l,int r,int x,int y,int val,int p)
{
    Expand(p);PushDown(p);
    if(x<=l&&r<=y)
    {
        t[p].val=t[p].len*val;
        t[p].tag=val;
        return ;
    }
    if(x>r||y<l)return ;
    Modify(l,mid,x,y,val,t[p].lc);
    Modify(mid+1,r,x,y,val,t[p].rc);
    t[p].val=t[t[p].lc].val+t[t[p].rc].val;
}
pair<int,pair<int,int> >pp[M];
inline bool cmp(pair<int,pair<int,int> >x,pair<int,pair<int,int> >y)
{
    return x.second.second<y.second.second;
}
signed main()
{
    freopen("master.in","r",stdin);
    freopen("master.out","w",stdout);
    cin>>m;
    t[1]=(Segment){1,1000000000,0,0,0,0};
    for(int i=1;i<=m;i++)cin>>pp[i].first>>pp[i].second.first>>pp[i].second.second;
    sort(pp+1,pp+1+m,cmp);
    for(int i=1;i<=m;i++)
    { 
        if(pp[i].second.first>pp[i].first)Modify(1,1000000000,pp[i].first,pp[i].second.first-1,pp[i].second.second,1);
    }
    cout<<t[1].val;
    return 0;
}
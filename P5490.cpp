//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i,l,u,d) for(register int i=(l);i<=(u);i+=(d))
#define mid (l+r>>1)
#define ls (rt<<1)
#define rs (rt<<1|1)
typedef long long ll;
typedef struct _line{
    int xl,xr,h,f;
    _line(int a=0,int b=0,int c=0,int d=0):xl(a),xr(b),h(c),f(d){}
    bool operator <(const _line &t) const{ return h<t.h; }
}line;

const int N=1e5+5;
int n,xl,yl,xr,yr;
int x[N<<1]; line l[N<<1];
int tag[N<<3]; ll len[N<<3];
ll ans;
inline void push_up(int rt,int l,int r){
    len[rt]=tag[rt]?len[rt]:(l==r?0:len[ls]+len[rs]);
}
inline void modify(int rt,int l,int r,int xl,int xr,int d){
    if(xl<=l&&r<=xr){
        len[rt]=(tag[rt]+=d)?x[r+1]-x[l]:0;
        return push_up(rt,l,r);
    }
    if(xl<=mid) modify(ls,l,mid,xl,xr,d);
    if(xr>mid) modify(rs,mid+1,r,xl,xr,d);
    push_up(rt,l,r);
}
signed main()
{
	cin>>n;
    rep(i,1,n,1){
        cin>>xl>>yl>>xr>>yr;
        x[(i<<1)-1]=xl,x[i<<1]=xr;
        l[(i<<1)-1]=line(xl,xr,yl,1),l[i<<1]=line(xl,xr,yr,-1);
    }
    sort(x+1,x+2*n+1),sort(l+1,l+2*n+1);
    int ct=unique(x+1,x+2*n+1)-x-2;
    rep(i,1,2*n,1){
        int xl=lower_bound(x+1,x+ct+1,l[i].xl)-x;
        int xr=lower_bound(x+1,x+ct+1,l[i].xr)-x-1;
        ans+=len[1]*(l[i].h-l[i-1].h);
        modify(1,1,ct,xl,xr,l[i].f);
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
typedef long long ll;
const int N=100010;
int n,m,type,x,y , mod;
ll tree[N<<2],addv[N<<2],mul[N<<2],c[N], k;   //�ı��ռ�
#define lson o<<1
#define rson o<<1|1
#define mid (l+r>>1)  //Ϊ��͵������
inline void up(int o) { tree[o]=tree[lson]+tree[rson] ; }  //�ϲ�������Ϣ
inline void build(int o,int l,int r) {
    mul[o]=1;
    if(l==r) { tree[o]=c[l]%mod; return ;}
    build(lson,l,mid) ; build(rson,mid+1,r) ; up(o);
}
inline void down(int o,int l,int r,int ls,int rs) {  //�´�2��lazytag
    if(mul[o]!=1) {   //ע���ȳ˺��
        ll x=mul[o] ; mul[o]=1;  //������м����Ҳһ��Ҫ��long long 
        (addv[ls]*=x) %=mod ; (mul[ls]*=x) %=mod ; (tree[ls]*=x) %=mod;
        (addv[rs]*=x) %=mod ; (mul[rs]*=x) %=mod ; (tree[rs]*=x) %=mod;
    }
    if(addv[o]!=0) {
        ll x=addv[o] ; addv[o]=0;
        (addv[ls]+=x) %=mod ; (tree[ls]+=x*(mid-l+1)) %=mod;
        (addv[rs]+=x) %=mod ; (tree[rs]+=x*(r - mid)) %=mod;
    }
}
inline void update(int o,int l,int r,int L,int R ,ll x, int type) {
    if(L<=l && r<=R ) {
        if(type==2) (addv[o]+=x)%=mod , (tree[o]+=x*(r-l+1)) %=mod ;
        else (addv[o]*=x) %=mod , (mul[o]*=x) %=mod , (tree[o]*=x) %=mod; return ;
    }
    down(o,l,r,lson,rson) ;
    if(L<=mid) update(lson,l,mid,L,R,x,type); 
    if(R>mid) update(rson,mid+1,r,L,R,x,type);
    up(o) ;
}
inline ll query(int o,int l,int r,int L,int R ){
    if(L<=l && r<=R ) return tree[o] ;
    down(o,l,r,lson,rson) ; ll ret =0 ;
    if(L<=mid)  (ret+=query(lson,l,mid,L,R) ) %=mod;
    if(R>mid) (ret+=query(rson,mid+1,r,L,R) ) %=mod;
    return ret; 
}
int main() {
    scanf("%d%d%d",&n,&m,&mod);
    rep(i,1,n) scanf("%lld",&c[i]) ;
    build(1,1,n) ;
    while(m--) {
        scanf("%d",&type);
        if(type==3) scanf("%d%d",&x,&y) , printf("%lld\n",query(1,1,n,x,y)) ;
        else scanf("%d%d%lld",&x,&y,&k) , update(1,1,n,x,y,k,type);
    }
    return 0;
}

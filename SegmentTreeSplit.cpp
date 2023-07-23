//�߶������� ������ʵ�ɿ��������ѯ ÿ���������O(2logn)���
//ά��������ؼ� �ϲ����ڴ����
//0.p������ֵ��x��y�ķ�������¼���
//1.��t�ϲ���p�У����t(t�Ժ󲻳���) ���������ڴ���� 2.p�м���x��q
//3.��ѯp��x��y����     4.��ѯp�е�kС
#include<bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
typedef long long ll;
#define N maxn*32
const int maxn=2e5+5;
int n,m,op,cntset=1,a[maxn];
struct SementTree{
    int rt[maxn*3],lc[N],rc[N],tot,rub[N],cnt=0;
    ll sum[N];
    int New(){//�ڴ����  ���Ѻϲ�ͬʱ�е�ʱ�����ʹ��
        if(cnt)return rub[cnt--];
        return ++tot;
    }
    void del(int&p){
        ls=rs=sum[p]=0;
        rub[++cnt]=p;
        p=0;
    }
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void build(int&p,int l,int r){
        if(!p)p=New();
        if(l==r){
            sum[p]=a[l];return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void update(int&p,int l,int r,int x,int val){
        if(!p)p=New();
        if(l==r){
            sum[p]+=val;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int merge(int &p,int &q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){
            sum[p]+=sum[q];
            del(q);
            return p;
        }
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        del(q);
        pushUp(p);
        return p;
    }
    void split(int&p,int&q,int l,int r,int L,int R){
        if(L>r||R<l)return;
        if(!p)return;
        if(L<=l&&r<=R){
            q=p;
            p=0;return;//ֱ�Ӷϱ߽���
        }
        if(!q)q=New();
        int mid=l+r>>1;
        if(L<=mid)split(ls,lc[q],l,mid,L,R);
        if(R>mid)split(rs,rc[q],mid+1,r,L,R);
        pushUp(p);//���Ÿ���
        pushUp(q);
    }
    ll query(int p,int l,int r,int L,int R){
        if(!p)return 0;
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
    int kth(int p,int l,int r,int k){
        if(l==r)return l;
        int mid=l+r>>1;
        if(sum[ls]>=k)return kth(lson,k);
        else return kth(rson,k-sum[ls]);
    }
}tr;
int main(){
    int x,y,z;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    tr.build(tr.rt[1],1,n);
    for(int i=1;i<=m;++i){
        cin>>op;
        if(!op){
            cin>>x>>y>>z;
            tr.split(tr.rt[x],tr.rt[++cntset],1,n,y,z);
        }else if(op==1){
            cin>>x>>y;
            tr.rt[x]=tr.merge(tr.rt[x],tr.rt[y],1,n);
        }else if(op==2){
            cin>>x>>y>>z;
            tr.update(tr.rt[x],1,n,z,y);
        }else if(op==3){
            cin>>x>>y>>z;
            cout<<tr.query(tr.rt[x],1,n,y,z)<<"\n";
        }else if(op==4){
            cin>>x>>y;
            if(tr.sum[tr.rt[x]]<y)cout<<-1<<"\n";
            else cout<<tr.kth(tr.rt[x],1,n,y)<<"\n";
        }
    }
    return 0;
}


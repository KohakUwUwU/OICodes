//Project Sekai
#include<bits/stdc++.h>
using namespace std;
const int MAXT = 50010;
const int T = 50000;
struct node{double mn,mx;}tree[MAXT<<2];
void pushup(int k){tree[k].mn = min(tree[k<<1].mn,tree[k<<1|1].mn);tree[k].mx = max(tree[k<<1].mx,tree[k<<1|1].mx);}
void modify(int k,int l,int r,double first,double p){
    if(l==r){	
        tree[k].mn = tree[k].mx = max(tree[k].mx,first+p*double(r-1));
        return;
    }
    if(tree[k].mn>first+p*double(r-1))return;
    int mid = l+r>>1;
    modify(k<<1,l,mid,first,p);modify(k<<1|1,mid+1,r,first,p);
    pushup(k);
}
double query(int k,int l,int r,int pos){
    if(l==r){return tree[k].mx;}
    int mid = l+r>>1;
    if(pos<=mid)return query(k<<1,l,mid,pos);
    else return query(k<<1|1,mid+1,r,pos);
}
int main(){
	freopen("fly.in","r",stdin);
	freopen("fly.out","w",stdout);
    int n;scanf("%d",&n);
    char c[20];
    double S,P;
    int D;
    while(n--){
        scanf("%s",c);
        if(c[0]=='F'){
            scanf("%lf%lf",&S,&P);
            modify(1,1,T,S,P);
        }else{
            scanf("%d",&D);
            printf("%d\n",((int)(query(1,1,T,D)))/100);
        }
    }
    return 0;
}

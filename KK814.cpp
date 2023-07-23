//And in that light, I find deliverance.
#include<bits/stdc++.h> 
#define int long long
using namespace std;
inline int read(){
    int f=1,ans=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return f*ans;
}
const int N=300001;
int l,r,num[N];
int f[N],t[N],c[N],S,n,que[N];
int query(int pos,int X){
    int L=l,R=r,maxn=0;
    int mid;
    while(L<=R){
        mid=L+R>>1;
        if(f[que[mid+1]]-f[que[mid]]<=X*(c[que[mid+1]]-c[que[mid]])) L=mid+1,maxn=max(maxn,mid);
        else R=mid-1;
    }
    return que[maxn+1];
}
signed main(){
    n=read(),S=read();
    for(int i=1;i<=n;i++) t[i]=t[i-1]+read(),c[i]=c[i-1]+read();
    l=1,r=1;f[0]=0;
    for(int i=1;i<=n;i++){
        int H=query(i,S+t[i]);
        f[i]=f[H]-(S+t[i])*c[H]+t[i]*c[i]+S*c[n];
        while(l<r&&(f[que[r]]-f[que[r-1]])*(c[i]-c[que[r]])>=(f[i]-f[que[r]])*(c[que[r]]-c[que[r-1]])) r--;
        que[++r]=i;
    }printf("%lld\n",f[n]);
    return 0;
}

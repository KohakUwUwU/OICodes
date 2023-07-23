#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,d[12],f[12][2];
ll n;
ll dfs(int len,bool fl,bool st){
    if (!len) return st;
    if (!fl && f[len][st]) return f[len][st];
    int up=fl?d[len]:9;ll sum=0;
    for (int i=0;i<=up;i++) sum+=dfs(len-1,fl && (i==up),st || (i==7));
    if (!fl) f[len][st]=sum;
    return sum;
}
ll cal(ll x){
    int len=0;
    while (x) d[++len]=x%10,x/=10;
    return dfs(len,1,0);
}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%lld",&n);
        printf("%lld\n",n-cal(n));
    }
    return 0;
}

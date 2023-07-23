//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;
int xx,yy,n,m,oshama,scramble,a[10001],c[10001],t[10001],f[10001];

signed main()
{
    scanf("%lld:%lld %lld:%lld",&xx,&yy,&oshama,&scramble);
    if(yy>scramble)scramble+=60,oshama--;
    m=(oshama-xx)*60+scramble-yy;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i]>>t[i];
    for(int i=1;i<=n;i++)
    {
        if(t[i])for(int k=1;k<=t[i];k++)for(int j=m;j>=a[i];j--)f[j]=max(f[j],f[j-a[i]]+c[i]);
        else for(int j=a[i];j<=m;j++)f[j]=max(f[j],f[j-a[i]]+c[i]);
    }
    cout<<f[m];
    return 0;
}


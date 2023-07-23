//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=155;
int n,m=-1,a[N],b[N],c[N];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=c[i]=1;
    for(int i=2;i<=n;i++)for(int j=1;j<i;j++)if(a[i]>a[j]&&b[j]+1>=b[i])b[i]=b[j]+1;
    for(int i=n-1;i>=1;i--)for(int j=i+1;j<=n;j++)if(a[i]>a[j]&&c[j]+1>=c[i])c[i]=c[j]+1;
    for(int i=1;i<=n;i++)if(b[i]+c[i]>m)m=b[i]+c[i];
    cout<<n-m+1;
    return 0;
}

//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,e[300],s[300][300],mx=-1;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>e[i],e[i+n]=e[i];
    for(int i=2;i<2*n;i++)for(int j=i-1;i-j<n&&j>=1;j--)for(int k=j;k<i;k++)
		s[j][i]=max(s[j][i],s[j][k]+s[k+1][i]+e[j]*e[k+1]*e[i+1]),
        mx=max(mx,s[j][i]);
    cout<<mx;
    return 0;
}

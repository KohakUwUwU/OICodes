//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+7;
int n,m,p[N],q[N],chunithm[N];
signed main()
{
	cin>>n>>m;
	for(int i=1,u,v;i<=n;i++)cin>>u>>v,p[u]++,q[v]++;
    for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)chunithm[i+j]+=p[i]*p[j],chunithm[i+j+1]-=q[i]*q[j];
    for(int i=0;i<=2*m;i++)i?chunithm[i]+=chunithm[i-1]:1,cout<<chunithm[i]<<'\n';
    return 0;
}

//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=67;
const int M=2e4+7;
int n,m,v[N],w[N],f[M],c[N][N];
signed main()
{
	cin>>m>>n;
	m/=10;
	for(int i=1,d;i<=n;++i)cin>>v[i]>>w[i]>>d,w[i]*=(v[i]/=10),c[d][++c[d][0]]=i;
	for(int i=1;i<=c[0][0];++i)for(int k=m;k>=v[i];--k)
			f[k]=max(f[k],max(max((k-v[c[0][i]])>=0?f[k-v[c[0][i]]]+w[c[0][i]]:0,(k-v[c[0][i]]-v[c[c[0][i]][1]])>=0?f[k-v[c[0][i]]-v[c[c[0][i]][1]]]+w[c[0][i]]+w[c[c[0][i]][1]]:0),max((k-v[c[0][i]]-v[c[c[0][i]][2]])>=0?f[k-v[c[0][i]]-v[c[c[0][i]][2]]]+w[c[0][i]]+w[c[c[0][i]][2]]:0,(k-v[c[0][i]]-v[c[c[0][i]][1]]-v[c[c[0][i]][2]])>=0?f[k-v[c[0][i]]-v[c[c[0][i]][1]]-v[c[c[0][i]][2]]]+w[c[0][i]]+w[c[c[0][i]][1]]+w[c[c[0][i]][2]]:0)));
	cout<<f[m]*10;
	return 0;
}

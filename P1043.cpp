//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
#define f(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int N = 55;
using namespace std;
int n,m,dmax[15][N],dmin[15][N];
int sum[N],a[N],ans,anss=1e9;
signed main() {
	scanf("%lld%lld",&n,&m);
	f(i,1,n) scanf("%lld",&a[i]);
	f(l,0,n-1) {
		memset(dmax,0,sizeof dmax);
		memset(dmin,0,sizeof dmin);
		f(i,1,n)dmin[1][i]=dmax[1][i]=sum[i]=(sum[i-1]+a[(i+l-1)%n+1]+10000)%10;
		f(k,2,m) f(i,1,n-m+k) {
			dmin[k][i]=1e9;
			f(j,1,i-1) if(dmin[k-1][j]<1e9) {
				dmax[k][i]=max(dmax[k][i],
				dmax[k-1][j]*((sum[i]-sum[j]+10000)%10));
				dmin[k][i]=min(dmin[k][i],
				dmin[k-1][j]*((sum[i]-sum[j]+10000)%10));
			}
		}
		ans=max(ans,dmax[m][n]);
		anss=min(anss,dmin[m][n]);
	}
	cout<<anss;
	cout<<'\n';
	cout<<ans;
    return 0;
}

//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 23;
typedef long double type;
const type eps = 1e-7;
struct Pos{
	type x,y;
}val[maxn];
int t,n,m,dp[1 << maxn],lowbit[1 << maxn],line[maxn][maxn];//lowbit表示最小的为0的点的编号
inline bool cmp(type a,type b){return abs(a - b) < eps;}
inline void gauss(type &x,type &y,type a1,type b1,type c1,type a2,type b2,type c2){
	x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
	y = (c1 - a1 * x) / b1;
}
inline void solve(){
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		cin >> val[i].x >> val[i].y;
	memset(line,0,sizeof(line));
	memset(dp,0x3f,sizeof(dp));
	dp[0] = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++){
			if(cmp(val[i].x,val[j].x))continue;
			type a,b;
			gauss(a,b,val[i].x * val[i].x,val[i].x,val[i].y,val[j].x * val[j].x,val[j].x,val[j].y);
			if(a > -eps)continue;
			for(int k = 0;k < n;k++)
				if(cmp(a * val[k].x * val[k].x + b * val[k].x,val[k].y))line[i][j] |= 1 << k;
		}
	for(int i = 0;i < 1 << n;i++){
		int j = lowbit[i];
		dp[i | (1 << j)] = min(dp[i | (1 << j)],dp[i] + 1);
		for(int k = 0;k < n;k++)
			dp[i | line[j][k]] = min(dp[i | line[j][k]],dp[i] + 1);
	}
	cout << dp[(1 << n) - 1] << '\n';
}
signed main(){
	for(int i = 0;i < (1 << 18);i++){
		int j = 0;
		for(;(i >> j) & 1;j++);
		lowbit[i] = j;
	}
	cin >> t;
	while(t--)solve();
	return 0;
}

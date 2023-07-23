#include<bits/stdc++.h>
#define int long long
#define ll long long
#define RG register 
#define rep(i, l, r) for(RG int i = l; i <= r; i++) 
#define per(i, r, l) for(RG int i = r; i >= l; i--)
//RAISE A SUILEN
//All Rights Reserved
//By CHUCHU
using namespace std;
 
void INIT() {
  ios :: sync_with_stdio(false); cin.tie(0); 
}
 
const int N = 1e6+5; 
 
int n, c[5], d[5]; int dp[N]; 
signed main() {
  freopen("shopping.in","r",stdin);
  freopen("shopping.out","w",stdout);
  INIT(); dp[0] = 1; 
  rep(i, 1, 4) cin >> c[i]; cin >> n; 
  rep(j, 1, 4) rep(i, 0, 100000)
      if(i + c[j] <= 100000) 
        dp[i + c[j]] += dp[i]; 
  rep(i, 1, n) { int s; int ans = 0; 
    rep(j, 1, 4) cin >> d[j]; cin >> s;  
    rep(j, 0, 15) {
      int s1 = 0, s2 = s; 
      rep(t, 1, 4) 
        if(j & (1 << (t - 1))) {
          s1++; s2 -= (d[t] + 1) * c[t]; 
        }
      ans += ((s1 & 1) ? -1 : 1) * (s2 >= 0 ? dp[s2] : 0); 
    }  cout << ans << endl; 
  }
  return 0; 
}

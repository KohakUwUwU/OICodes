//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

// C++ Version
const int MAXN=1e9;
int phi[(int)1e9+5],pri[1];
int cnt,vis[(int)1e9];
void init() {
  phi[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    if (!vis[i]) {
      pri[cnt++] = i;
    }
    for (int j = 0; j < cnt; ++j) {
      if (1ll * i * pri[j] >= MAXN) break;
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        // i % pri[j] == 0
        // 换言之，i 之前被 pri[j] 筛过了
        // 由于 pri 里面质数是从小到大的，所以 i 乘上其他的质数的结果一定也是
        // pri[j] 的倍数 它们都被筛过了，就不需要再筛了，所以这里直接 break
        // 掉就好了
        break;
      }
    }
  }
}
signed main()
{
	init();
	for(int i=1;i<=cnt;i++)cout<<pri[i]<<',';
	return 0;
}


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
        // ����֮��i ֮ǰ�� pri[j] ɸ����
        // ���� pri ���������Ǵ�С����ģ����� i ���������������Ľ��һ��Ҳ��
        // pri[j] �ı��� ���Ƕ���ɸ���ˣ��Ͳ���Ҫ��ɸ�ˣ���������ֱ�� break
        // ���ͺ���
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


#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}

string s;
signed main()
{
	cin>>s;
	int n=s.length()-1,ans=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s[i]!=s[j])continue;
			int len=0;
			while(s[i+len]==s[j+len]&&j+len<=n)len++;
			len--;
			int r1=i+len,r2=j+len;
			ans+=(n-i+1+n-j+1)*(len+1);
		}
	}
	cout<<ans;
	return 0;
}


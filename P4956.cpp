#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s;
}
signed main()
{
    int n, x, k=1;
    n=read();
    for (;;++k)//k越小越好，上限没有定
    for (x = 100; x > 0; --x)//x范围1~100
    if ((7 * x + 21 * k) * 52 == n)//刚好52周筹完
    {
        printf("%d\n%d\n", x, k);
        return 0;
    }
}


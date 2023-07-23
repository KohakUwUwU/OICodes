#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100001],dis;
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
	n=read();a[1]=read();
	for(int i=2;i<=n;i++)a[i]=read(),dis+=max(a[i],a[i-1]);
    cout<<dis;
	return 0;
}


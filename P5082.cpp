#include<bits/stdc++.h>
using namespace std;
double n,a,b,c;
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
	int tmp;
	n=read();
	for(int i=1;i<=n;++i)tmp=read(),a+=tmp;
	for(int i=1;i<=n;++i)tmp=read(),b+=tmp;
	cout<<fixed<<setprecision(6)<<(a*3-b*2)/(a-b);
    return 0;
}


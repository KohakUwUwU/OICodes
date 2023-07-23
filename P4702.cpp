#include<bits/stdc++.h>
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
	int n,sum=0,tmp;
	n=read();
	for(int i=1;i<=n;++i)
	{
		tmp=read();
		sum+=tmp;
	}
	if(sum&1)cout<<"Alice";
	else cout<<"Bob";
    return 0;
}


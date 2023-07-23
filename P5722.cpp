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
	int n=read(),sum=0;
	for(int i=1;i<=n;i++)sum+=i;
	printf("%d",sum);
    return 0;
}


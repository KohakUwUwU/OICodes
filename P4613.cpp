#include<bits/stdc++.h>
using namespace std;
int n,a[1000],b[1000];
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
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	sort(a+1,a+1+n,greater<int>());
	sort(b+1,b+1+n,greater<int>());
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i])
		{
			cout<<"NE";
			return 0;
		}
	}
	cout<<"DA";
    return 0;
}


//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*w;
}

signed main()
{
	int cnt=0;
	for(int i=2000;i<=2999;i++)
	{
		if(i/1000+i/100%10+i/10%10+i%10==7)cnt++;
	}
	cout<<cnt;
	return 0;
}


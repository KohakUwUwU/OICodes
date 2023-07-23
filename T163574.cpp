#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,a[10001];
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int sum=0;
	sort(a+1,a+1+n);
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(i>(1<<cnt)-1)cnt++;
		sum+=cnt*a[i];
	}
	cout<<sum;
}

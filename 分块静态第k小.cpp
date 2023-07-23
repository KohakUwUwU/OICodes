//Find the k-th element
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int f[100003][320];
//前 i 个数中，小于等于 j*block 的有几个 
int g[320][100003];
//前 i 块中，小于等于 j 的有几个
int a[100003];
//数值 
const int B=320;
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	//预处理 f 和 g
	int l=read(),r=read(),k=read();
	int ans=0;
	while(1)
	{
		ans+=B;
		if(getgreater1(l,r,ans/B)>k) 
		{
			ans-=B;
			break;
		}	
	} 
	while(1)
	{
		++ans;
		if(getgreater2(l,r,ans)>k) 
		{
			--ans;
			break;
		}
	}
	return 0;
}


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
//ǰ i �����У�С�ڵ��� j*block ���м��� 
int g[320][100003];
//ǰ i ���У�С�ڵ��� j ���м���
int a[100003];
//��ֵ 
const int B=320;
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	//Ԥ���� f �� g
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


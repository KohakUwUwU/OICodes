#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003],f[100003];
int k[100003],b[100003],c,cur;
int Get(int id,int x)
{
	return k[id]*x+b[id];
}
bool check(int k1,int b1,int k2,int b2,int k3,int b3)
{
	return (k2-k1)*(b3-b2)<(k3-k2)*(b2-b1);
}
signed main()
{
	
	freopen("cable.in","r",stdin);
	freopen("cable.out","w",stdout); 
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	k[0]=0,b[0]=0,c=0,cur=0;
	for(int i=1; i<=n; ++i)
	{
		while(cur<c&&Get(cur,-i)>=Get(cur+1,-i)) ++cur;
		f[i]=Get(cur,-i)+a[i]+i*(i-1)/2;
		int C=f[i]+i*(i+1)/2;
		while(c>=1&&check(k[c-1],b[c-1],k[c],b[c],i,C)) --c;
		(cur>c)&&(cur=c);
		++c,k[c]=i,b[c]=C;
	}
	printf("%lld\n",f[n]);
	return 0;
}

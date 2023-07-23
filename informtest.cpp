#include<bits/stdc++.h>
#define N (int)1e5+1
#define int long long
using namespace std;
int n,v,x[N],y[N],ok[N],d[N];
long long ans;
#define dis(i,j) (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])
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
	freopen("inform.in","r",stdin);
	freopen("inform.out","w",stdout);
	n=read();v=read();d[n+1]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
	ok[1]=1;d[1]=0;d[0]=v;x[0]=y[0]=0x3f3f3f3f;
	for(int i=2;i<=n;i++)d[i]=min(dis(1,i),v);
	for(int i=1;i<=n;i++)
	{
		int pos=n+1;
		for(int j=1;j<=n;j++)if(!ok[j]&&d[pos]>d[j])pos=j;
		if(v<d[pos])pos=0;
		ok[pos]=1;
		ans+=d[pos];
//		cout<<d[pos]<<' '<<pos<<'\n';
		for(int j=1;j<=n;j++)d[j]=min(d[j],dis(pos,j));
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}	

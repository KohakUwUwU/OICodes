#include<iostream>
#define N (int)1e5+5
using namespace std;
int n,m,a[N],f[1<<20][200],LOG[N]={-1};
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read(),LOG[i]=LOG[i/2]+1,f[i][0]=a[i];
	for(int i=1;i<=16;i++)for(int j=1;j<=n;j++)f[j][i]=max(f[j][i-1],f[j+(1<<i-1)][i-1]);
	while(m--)
	{
		int x,y;
		x=read();
		y=read();
		int k=LOG[y-x+1];
		cout<<max(f[x][k],f[y+1-(1<<k)][k])<<'\n';
	}
}

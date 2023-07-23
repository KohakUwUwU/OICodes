#include<bits/stdc++.h>
using namespace std;
int n,m,q[101],c[101][201],sum[101][201],f[10001],g[101][201];
#define select(role,length,first) (sum[i][first+length-1]-sum[i][first-1])
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int main()
{
//	freopen("books.in","r",stdin);
//	freopen("books.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		q[i]=read();
		for(int j=1;j<=q[i];j++)c[i][j]=read(),sum[i][j]=sum[i][j-1]+c[i][j];
		int T=min(q[i],m);
		for(int j=1;j<=T;j++)
		{
			int bst=-1;
			for(int k=1;k+j<=q[i];k++)bst=min(bst,select(i,j,k));
			g[i][j]=sum[i][q[i]]-bst;
			cout<<g[i][j]<<" ";
		}
		cout<<'\n';
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			int T=min(q[i],j);
			for(int k=1;k<=q[i];k++)
			{
				f[k]=max(f[k],f[k-1]+c[i][k]);
			}
		}
	}
	cout<<f[m];
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

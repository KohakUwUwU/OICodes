#include<bits/stdc++.h>
using namespace std;
int n,m,q[101],c[101][201],sum[101][201],f[10001],g[101][201];
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
	freopen("books.in","r",stdin);
	freopen("books.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		q[i]=read();
		for(int j=1;j<=q[i];j++)c[i][j]=read(),sum[i][j]=sum[i][j-1]+c[i][j];
		int T=min(q[i],m);
		g[i][q[i]]=sum[i][q[i]];
		for(int j=1;j<=T;j++)
		{
			int bst=0x3f3f3f3f;
			for(int k=1;k+j<=q[i]+1;k++)bst=min(bst,sum[i][k+j-1]-sum[i][k-1]);
			g[i][q[i]-j]=sum[i][q[i]]-bst;
		}
	}
	for(int i=1;i<=n;i++)//层 
	{
		for(int j=m;j>=0;j--)//质量 
		{
			int T=min(q[i],j);
			for(int k=1;k<=q[i];k++)//第i层取了多少书 
			{
				if(j>=k)f[j]=max(f[j],f[j-k]+g[i][k]);
			}
		}
	}
	cout<<f[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

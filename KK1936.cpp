#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,W,w[N],b[N],sumw[N],sumb[N],f[N];
int fa[N];
int p,q;
vector<int>fw[N],fb[N];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
inline int find(const int& x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline int merge(const int& x,const int& y)
{
	fa[find(x)]=find(y);
}
int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	n=read();m=read();W=read();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)p=read(),q=read(),merge(p,q);
	for(int i=1;i<=n;i++)fw[find(i)].push_back(w[i]),fb[find(i)].push_back(b[i]),sumw[find(i)]+=w[i],sumb[find(i)]+=b[i];
	for(int i=1;i<=n;i++)fw[i].push_back(sumw[i]),fb[i].push_back(sumb[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=W;j>=0;j--)
		{
			for(int k=0;k<fw[i].size();k++)
			{
				if(j>=fw[i][k])f[j]=max(f[j],f[j-fw[i][k]]+fb[i][k]);
			}
		}
	} 
	cout<<f[W]<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

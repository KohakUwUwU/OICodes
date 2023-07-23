#include<iostream>
#define int long long
#define N 105
#define mod 998244353
using namespace std;
int n,m,k,x,y;
int ma[105][105][1001],a[105][105];
#define ju(i,j,d1,d2) ((a[i][j]<=a[d1][d2])?x:y)
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
signed main()
{
	n=read();m=read();k=read();x=read();y=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
	ma[1][1][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int aa=ju(i,j,i+1,j),bb=ju(i,j,i,j+1);//´ú¼Û 
			for(int l=0;l<=k-aa;l++)ma[i+1][j][l+aa]+=ma[i][j][l]%mod;
			for(int l=0;l<=k-bb;l++)ma[i][j+1][l+bb]+=ma[i][j][l]%mod;
		}
	}
	int sum=0;
	for(int i=0;i<=k;i++)sum+=ma[n][m][i],sum%=mod;
	cout<<(sum!=0?sum:-1);
}

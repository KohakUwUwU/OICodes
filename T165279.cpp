#include<bits/stdc++.h>
using namespace std;
const int N=20001;
int n,m;
vector<vector<int> >sum;
vector<int>rl,rr;
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
	int l,r,x,y,maxr=-1;
	n=read();
	rl.push_back(0);rr.push_back(0);
	for(int i=1;i<=n;i++)
	{
		l=read(),r=read();maxr=max(maxr,r);
		rl.push_back(l);rr.push_back(r);
	}
	sum.resize(maxr+1);
	for(int i=1;i<=maxr;i++)sum[i].resize(n+1);
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)for(int k=rl[i];k<=rr[i];k++)sum[k][j]++;
//	for(int i=1;i<=maxr;i++)
//	{
//		for(int j=1;j<=n;j++)cout<<sum[i][j]<<' ';
//		cout<<'\n';
//	}
	m=read();
	int mx;
	while(m--)
	{
		mx=-1;
		l=read();r=read();x=read();y=read();
		for(int i=l;i<=r;i++)mx=max(mx,sum[i][y]-sum[i][x-1]);
		cout<<mx<<endl;
	}
}

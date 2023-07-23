//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int N=2e3+5,HASH=114514191981;
int n,q,ma[N][N],hor1[N][N],hor2[N][N],ver1[N][N],ver2[N][N];
int hapow[3005];
inline void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<(char)ma[i][j]<<' ';
		cout<<'\n';
	}
}
inline void print1()
{
	cout<<"hor1:\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<hor1[i][j]<<' ';
		cout<<'\n';
	}
	cout<<"hor2:\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<hor2[i][j]<<' ';
		cout<<'\n';
	}
	cout<<"ver1:\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<ver1[i][j]<<' ';
		cout<<'\n';
	}
	cout<<"ver2:\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<ver2[i][j]<<' ';
		cout<<'\n';
	}
}
inline void init()
{
	hapow[0]=1;
	for(int i=1;i<=3000;i++)hapow[i]=hapow[i-1]*HASH;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			hor1[i][j]=hor1[i][j-1]+ma[i][j]*hapow[j];
			ver1[i][j]=ver1[i-1][j]+ma[i][j]*hapow[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			hor2[n-i][n-j]=hor2[n-i][n-j+1]+ma[n-i][n-j]*hapow[j+1];
			ver2[n-i][n-j]=ver2[n-i+1][n-j]+ma[n-i][n-j]*hapow[i+1];
		}
	}
}
inline int hor1val(int x,int y,int len)//均乘到3000次为最低次幂,[x,x+len-1]
{
	return (hor1[x][y+len-1]-hor1[x][y-1])*hapow[3000-y];
} 
inline int hor2val(int x,int y,int len)
{
	return (hor2[x][y-len+1]-hor2[x][y+1])*hapow[3000-(n+1-y)];
}
inline int ver1val(int x,int y,int len)
{
	return (ver1[x+len-1][y]-ver1[x-1][y])*hapow[3000-x];
}
inline int ver2val(int x,int y,int len)
{
	return (ver2[x-len+1][y]-ver2[x+1][y])*hapow[3000-(n+1-x)];
}
inline int check_hor(int x,int y)
{
	long long lo=13,ans=1;
	while(lo>=0)
	{
		lo--;
		if(y-ans+1-(1<<lo)<=0||y+ans-1+(1<<lo)>n)continue;
		if(hor1val(x,y,ans+(1<<lo))==hor2val(x,y,ans+(1<<lo)))ans+=(1<<lo);
	}
	return ans;
}
inline int check_ver(int x,int y)
{
	long long lo=13,ans=1;
	while(lo>=0)
	{
		lo--;
		if(x-ans+1-(1<<lo)<=0||x+ans-1+(1<<lo)>n)continue;
		if(ver1val(x,y,ans+(1<<lo))==ver2val(x,y,ans+(1<<lo)))ans+=(1<<lo);
	}
	return ans;
}
inline void check(int x,int y)
{
//	cout<<1;
	cout<<max(check_hor(x,y),check_ver(x,y))*2-1<<'\n';
//	cout<<check_hor(x,y)*2-1<<' '<<check_ver(x,y)*2-1<<"%\n";
}
signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		for(int j=0;j<str.length();j++)ma[i][j+1]=str[j];
	}
//	print();
	init();
//	print1();
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		check(x,y);
	}
	return 0;
}


//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e3+5;
string s1,s2,s1_1,s2_1;
int k,n,m;
int f[N][N];//s1串前i位置和s2串前j位置的距离
//转移：
//1、f[i-1][j-1]+abs(s1[i]-s2[i]) 
//2、f[i-1][j]+k
//3、f[i][j-1]+k
inline void init()
{
	n=s1.length()-1,m=s2.length()-1;
	for(int i=1;i<=n;i++)f[i][0]=i*k;
	for(int i=1;i<=m;i++)f[0][i]=i*k;
} 
inline void dp()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=min(f[i-1][j-1]+abs(s1[i]-s2[j]),min(f[i-1][j]+k,f[i][j-1]+k));
		}
	}
}
inline void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)cout<<f[i][j]<<' ';
		cout<<'\n';
	}
}
signed main()
{
	cin>>s1_1>>s2_1>>k;
	s1+='0';s2+='0';
	s1+=s1_1;s2+=s2_1;
//	cout<<s1<<'\n'<<s2<<'\n';
	init();
	dp();
//	print();
	cout<<f[n][m];
	return 0;
}


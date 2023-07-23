#include<iostream>
using namespace std;
int n,m,ma[1001][1001];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int j=a;j<=c;j++)for(int k=b;k<=d;k++)ma[j][k]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<ma[i][j]<<' ';
		cout<<'\n';
	}
}

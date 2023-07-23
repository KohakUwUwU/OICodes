#include<iostream>
using namespace std;
int x,y,k;
int ma[1000][1000];
int main()
{
	cin>>x>>y>>k;
	for(int i=1;i<=k;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int j=a;j<=c;j++)for(int k=b;k<=d;k++)ma[j][k]=1;
	}
	int cnt=0;
	for(int i=1;i<=x;i++)for(int j=1;j<=y;j++)if(ma[i][j])++cnt;
	cout<<cnt;
}

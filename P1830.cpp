#include<iostream>
using namespace std;
int n,m,x,y;
int a[101][101],sum[101][101];
int main()
{
	cin>>n>>m>>x>>y;
	for(int i=1;i<=x;i++)
	{
		register int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int j=x1;j<=x2;j++)
		{
			for(int k=y1;k<=y2;k++)a[j][k]=i,sum[j][k]++;
		}
	}
	for(int i=1;i<=y;i++)
	{
		register int x1,y1;
		cin>>x1>>y1;
		if(a[x1][y1]>0)cout<<"Y "<<sum[x1][y1]<<" "<<a[x1][y1]<<endl;
		else cout<<"N"<<endl;
	}
}

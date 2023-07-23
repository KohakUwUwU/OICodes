#include<iostream>
using namespace std;
int v,n,p,i,j;
int f[1001][1001];
int main()
{
	cin>>v>>n;
	for(int i=1;i<=v;i++)
	{
		cin>>p;
		f[i][0]=1;
		if(i>1)
		{
			for(j=0;j<p;j++)
			{
				f[i][j]=f[i-1][j];
			}
			for(j=p;j<=n;j++)
			{
				f[i][j]=f[i-1][j]+f[i][j-p];
			}
		}
	}
	cout<<f[v][n];
}

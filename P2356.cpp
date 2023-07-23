#include<iostream>
#define N 1005
using namespace std;
long long n,map[N][N],c[N],r[N];
int main()
{
	bool ify=true;
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		cin>>map[i][j];
		if(map[i][j]==0)ify=false;
		c[i]+=map[i][j],r[j]+=map[i][j];
	}
	if(ify)
	{
		cout<<"Bad Game!";
		return 0;
	}
	long long mx=-1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		if(map[i][j]==0)mx=max(mx,c[i]+r[j]);
	}
	cout<<mx;
}

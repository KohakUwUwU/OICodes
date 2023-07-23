#include<iostream>
using namespace std;
int t[1001],m[1001],f[1001][1001];
int main()
{
	int time,num;
	cin>>time>>num;
	for(int i=1;i<=num;i++)cin>>t[i]>>m[i];
	for(int i=2;i<=num;i++)for(int j=1;j<=time;j++)
	{
		if(j>=t[i])f[i][j]=max(f[i-1][j-t[i]]+m[i],f[i-1][j]);
		else f[i][j]=f[i-1][j];
	}
	cout<<f[num][time];
}

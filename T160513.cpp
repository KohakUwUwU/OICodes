#include<iostream>
using namespace std;
const int mod=1000000007;
long long n,k,f[15][1005],pre[10];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=6;i++)++f[1][i%k],pre[i]=i%k;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=6;j++)pre[j]*=10,pre[j]%=k;
		for(int j=0;j<k;j++)
		{
			for(int dd=1;dd<=6;dd++)
			{
				f[i+1][(pre[dd]+j)%k]+=f[i][j];
				f[i+1][(pre[dd]+j)%k]%=mod;
			}
		}
	}
	cout<<f[n][0];
}

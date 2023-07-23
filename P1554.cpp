#include<iostream>
using namespace std;
int cnt[11];
inline void j(int k)
{
	while(k>0)
	{
		++cnt[k%10];
		k/=10;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=n;i<=m;i++)
	{
		j(i);
	}
	for(int i=0;i<10;i++)cout<<cnt[i]<<" ";
}

#include<iostream>
#include<map>
using namespace std;
int n;
map<int,bool> vis;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		double tmp1;
		int tmp2;
		cin>>tmp1>>tmp2;
		for(int j=1;j<=tmp2;j++)
		{
			vis[int(double(j)*tmp1)]=!vis[int(double(j)*tmp1)];
		}
	}
	int i=1;
	while(1)
	{
		if(vis[i]==true)
		{
			cout<<i;
			return 0;
		}
		i++;
	}
}

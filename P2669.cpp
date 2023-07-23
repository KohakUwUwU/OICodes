#include<iostream>
using namespace std;
int main()
{
	int n,coin=1,cnt=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cnt++;
		sum+=coin;
		if(cnt==coin)cnt=0,coin++;
	}
	cout<<sum;
}

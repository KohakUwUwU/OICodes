#include<iostream>
using namespace std;
int n,x;
inline int tj(int k)
{
	register int cnt=0;
	while(k>0)
	{
		if(k%10==x)cnt++;
		k/=10;
	}
	return cnt;
}
int main()
{
	int count=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		count+=tj(i);
	}
	cout<<count;
}

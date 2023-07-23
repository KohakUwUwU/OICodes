#include<iostream>
using namespace std;
int k,m,n;
int main()
{
	int tmp=0;
	cin>>k>>m>>n;
	for(int i=1;i<=m;i++)
	{
		register int x,y;
		cin>>x>>y;
		if(x==0&&y!=0)tmp=1,cout<<i<<" ";
		else if(k/x*y>=n)cout<<i<<" ",tmp=1;
	}
	if(tmp==0)cout<<-1;
}

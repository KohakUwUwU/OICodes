#include<bits/stdc++.h>
#include<map>
using namespace std;
int m,n,tmp;
map<int,int>q;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>tmp;
		if(!q[tmp])q[tmp]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		if(q[tmp]==0)cout<<-1<<" ";
		else cout<<q[tmp]<<" ";
	}
}

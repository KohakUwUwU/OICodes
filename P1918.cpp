#include<iostream>
#include<map>
using namespace std;
int n,q,tmp;
map <int,int> m;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		m[tmp]=i;
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>tmp;
		cout<<m[tmp]<<endl;
	}
}

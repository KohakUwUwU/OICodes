//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,q;
string str;
signed main()
{
	int add=0;
	cin>>n>>q>>str;
	for(int i=1;i<=q;i++)
	{
		int opt,x;
		cin>>opt>>x;
		if(opt==1)(add+=x)%=n;
		else
		{
			cout<<str[((x-1-add)%n+n)%n]<<'\n';
		}
	}
	return 0;
}


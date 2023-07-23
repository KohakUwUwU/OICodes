//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int a[N],b[N];
signed main()
{
	freopen("number1.out","r",stdin);
	for(int i=1;i<=200000;i++)cin>>a[i];
	freopen("number2.out","r",stdin);
	for(int i=1;i<=200000;i++)cin>>b[i];
	for(int i=1;i<=200000;i++)
	{
		if(a[i]!=b[i])
		{
			cout<<i<<'\n';
		}
	}
	cout<<"yes";
	return 0;
}


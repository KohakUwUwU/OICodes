//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

int t;
signed main()
{
	cin>>t;
	string name="Timur";
	sort(name.begin(),name.end());
	while(t--)
	{
		int n;
		string str;
		cin>>n;
		if(n!=5)
		{
			cin>>str;
			cout<<"NO"<<'\n';
			continue;
		}
		cin>>str;
		sort(str.begin(),str.end());
		if(str==name)
		{
			cout<<"YES"<<'\n';
			continue;
		}
		else cout<<"NO"<<'\n';
	}
	return 0;
}


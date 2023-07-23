//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

string str;
signed main()
{
	int ans=0,last=0,cnt=0;
	int n;
	cin>>n;
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		if(last==str[i])cnt++;
		else
		{
			ans+=cnt*(cnt-1)/2;
			cnt=1;
		}
		last=str[i];
//		cout<<cnt;
	}
	ans+=cnt*(cnt-1)/2;
	cout<<ans;
	return 0;
}


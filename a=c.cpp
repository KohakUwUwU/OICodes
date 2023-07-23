//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	string str;
	cin>>str;
	for(int i=-5;i<=5;i++)
	{
		for(int j=0;j<str.length();j++)cout<<char(str[i]+j);
	}
	return 0;
}


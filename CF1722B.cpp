//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str1,str2;
		cin>>str1>>str2;
		for(int i=0;i<n;i++)
		{
			if(str1[i]=='G')str1[i]='B';
			if(str2[i]=='G')str2[i]='B';
		}
		if(str1==str2)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}


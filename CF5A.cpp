//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

signed main()
{
	int cnt=0,ans=0;
	string str;
	while(getline(cin,str))
	{
		if(str[0]=='+')cnt++;
		else if(str[0]=='-')cnt--;
		else
		{
			int i=0;
			for(;i<str.length();i++)if(str[i]==':')break;
//			cout<<i<<' '<<str.length()<<endl;
			ans+=(str.length()-i-1)*cnt;
		}
	}
	cout<<ans;
	return 0;
}


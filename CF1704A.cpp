//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n,m,visa[2],visb[2];
string stra,strb;
inline bool judgeTail()
{
	for(int i=0;i<strb.length()-1;i++)
	{
		if(strb[strb.length()-1-i]!=stra[stra.length()-1-i])return false;
	}
	return true;
}
signed main()
{
	cin>>t;
	while(t--)
	{
		visa[0]=visa[1]=visb[0]=visb[1]=0;
		cin>>n>>m;
		cin>>stra>>strb;
		if(stra.length()<strb.length())
		{
			cout<<"No\n";
			continue;
		}
		if(!judgeTail())
		{
			cout<<"No\n";
			continue;
		}
		for(int i=0;i<=stra.length()-strb.length();i++)visa[stra[i]-'0']=1;
		if(visa[strb[0]-'0']==1)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	return 0;
}


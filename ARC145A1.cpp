//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,vis[N],timer,q[N];
string str;
inline bool judge(string str)
{
	for(int i=0;i<str.length()/2;i++)
	{
		if(str[i]!=str[str.length()-1-i])return false;
	}
	return true;
}
signed main()
{
	cin>>n>>str;
	for(int i=0;i<str.length()/2;i++)
	{
		if(str[i]!=str[str.length()-i-1])vis[i]=1,q[++timer]=i;
	}
	if(n==2)
	{
		cout<<"No";
		return 0;
	}
	if(timer>2)
	{
		cout<<"No";
		return 0;
	}
	if(timer==0)
	{
		for(int i=0;i<str.length()-1;i++)
		{
			if(str[i]=='A'&&str[i+1]=='B')
			{
				cout<<"Yes";
				return 0;
			}
		}
		cout<<"No";
		return 0;
	}
	for(int i=1;i<=timer;i++)
	{
		for(int i=max(0ll,q[i]-1);i<=(q[i]!=str.length()-1?q[i]:q[i-1]);i++)
		{
			char temp1=str[i],temp2=str[i+1];
			str[i]='A',str[i+1]='B';
			if(judge(str))
			{
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
	return 0;
}


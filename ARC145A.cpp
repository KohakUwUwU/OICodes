//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,vis[N],q[N],timer;
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
		if(str[i]!=str[str.length()-1-i])vis[i]=1,q[++timer]=i;
	}
	if(n==2)
	{
		cout<<"No";
		return 0;
	}
	if(n<=10)
	{
		for(int i=0;i<n-1;i++)
		{
			int temp1=str[i],temp2=str[i+1];
			str[i]='A',str[i+1]='B';
			if(judge(str))
			{
				cout<<"Yes";
				return 0;
			}
			str[i]=temp1,str[i+1]=temp2;
		}
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
	if(timer==1)
	{
		int k=q[1];
		if(k==0)
		{
			if(str[k]=='B'&&str[k+1]=='B')
			{
				cout<<"Yes";
				return 0;
			}
			else
			{
				cout<<"No";
				return 0;
			}
		}
		else if(k==str.length()/2-1)
		{
			if(str.length()%2==0)
			{
				if(str[k]=='A'&&str[k-1]=='A')
				{
					cout<<"Yes";
					return 0;
				}
				cout<<"No";
				return 0;
			}
			else
			{
				if(str[k]=='A'&&str[k-1]=='A')
				{
					cout<<"Yes";
					return 0;
				}
				if(str[k]=='B')
				{
					cout<<"Yes";
					return 0;
				}
				cout<<"No";
				return 0;
			}
		}
		else
		{
			if(str[k-1]=='A'&&str[k]=='A'||str[k]=='B'&&str[k+1]=='B')
			{
				cout<<"Yes";
				return 0;
			}
			else
			{
				cout<<"No";
				return 0;
			}
		}
	}
	if(timer==2)
	{
		if(q[1]!=q[2]-1)
		{
			cout<<"No";
			return 0;
		}
		if(str[q[1]]=='B'&&str[q[2]]=='A')
		{
			cout<<"Yes";
			return 0;
		}
		else
		{
			cout<<"No";
			return 0;
		}
	}
	return 0;
}


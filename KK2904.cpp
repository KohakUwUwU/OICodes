//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,cnt;
int vis[1005];//Ԫexist
int pos[1005];//Ԫshoot 
bitset<1005>a[2005];
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		string str;
		int k;
		cin>>str>>k;
		for(int j=0;j<str.length();j++)a[i][j+1]=str[j]-'0';
		a[i][str.length()]=k;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j])continue;
			if(a[i][j])a[i]^=a[pos[j]];
		}
		int b=0;
		for(int j=1;j<=n;j++)if(a[i][j])
		{
			vis[j]=1;
			pos[j]=i;
			break;
		}
		cnt++;
		if(cnt==n)break;
	}
	if(cnt==n)
	{
		for(int i=n;i>=1;i--)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(a[pos[j]][pos[i]])a[pos[j]]^=a[pos[i]];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[pos[i]][n+1])cout<<"Odd"<<'\n';
			else cout<<"Even"<<'\n';
		}
	}
	else cout<<"???";
	return 0;
}


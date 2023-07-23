//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

int ans;
map<string,bool>ma;
inline bool check(string str)
{
	for(int i=0;i<=str.length()-3;i++)
	{
		if(str[i]=='a'&&str[i+1]=='b'&&str[i+2]=='c')return true;
	}
	return false;
}
inline void dfs(int a,int b,int c,string str)
{
	if(a==0&&b==0&&c==0)
	{
		if(ma[str])return ;
		if(check(str))ans++;
		return ;
	}
	if(a)dfs(a-1,b,c,str+'a');
	if(b)dfs(a,b-1,c,str+'b');
	if(c)dfs(a,b,c-1,str+'c');
}
signed main()
{
	string str;
	dfs(3,5,2,str);
	cout<<ans;
	return 0;
}


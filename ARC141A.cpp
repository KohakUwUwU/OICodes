//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

int T;
int time10[20];
inline int range(string str,int l,int r)
{
	int ans=0;
	for(int i=l;i<=r;i++)
	{
		int add=str[i]-'0';
		ans=10*ans+add;
	}
	return ans;
}
inline int Bit(int k)
{
	int cnt=0;
	while(k)cnt++,k/=10;
	return cnt;
}
inline void run(string str)
{
	int ret=-1;
	int n=str.length();
	for(int i=1;i*2<=str.length();i++)
	{
		if(n%i!=0)continue;
		int tmp=922337203685477;
		for(int j=0;j<n;j+=i)tmp=min(tmp,range(str,j,j+i-1));
		if(tmp!=range(str,0,0+i-1))tmp=range(str,0,0+i-1)-1;
		int s=i;
		while(range(str,0,0+i-1)==range(str,s,s+i-1))s+=i;
		if(range(str,0,0+i-1)<range(str,s,s+i-1))tmp=range(str,0,0+i-1);
		int ans=0;
		for(int j=0;j<n;j+=i)ans=ans*time10[Bit(tmp)]+tmp;
		ret=max(ret,ans);
	}
	int u=0;
	for(int i=1;i<n;i++)u=u*10+9;
	ret=max(ret,u);
	cout<<ret<<'\n';
}
signed main()
{
	cin>>T;
	time10[0]=1;
	for(int i=1;i<=18;i++)time10[i]=time10[i-1]*10;
	while(T--)
	{
		string str;
		cin>>str;
		run(str);
	}
	return 0;
}


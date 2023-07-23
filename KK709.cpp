#include<bits/stdc++.h>
using namespace std;
//const ull HASH=2654435769;
struct node
{
	int k;//第几个串
	int pos;//串中cur匹配坐标 
};
string s1,s2;
string name[101]={""};
int cnt=0,dp[10001];
int check[10001][101];
queue<node> p;
inline void newnode(int k)
{
	node x;
	x.k=k;
	x.pos=1;
	p.push(x);
}
int main()
{
	freopen("ninja3.in","r",stdin);
	freopen("ninja3.out","w",stdout);
	getline(cin,s1);
	cin>>s2;
	for(int i=0;i<s1.length();i++)
	{
		++cnt;
		while(s1[i]!=' '&&i<s1.length())name[cnt]+=s1[i],i++;
	}
	for(int i=0;i<s2.length();i++)
	{
		int siz=p.size();
		for(int j=1;j<=siz;j++)
		{
//			cout<<"k:"<<p.front().k<<" pos:"<<p.front().pos<<endl;
			if(s2[i]==name[p.front().k][p.front().pos])
			{
				if(p.front().pos==name[p.front().k].length()-1)check[i][p.front().k]=1;
				else
				{
					node x=p.front();
					x.pos++;
					p.push(x);
				}
			}
			p.pop();
		}
		for(int j=1;j<=cnt;j++)
		{
			if(s2[i]==name[j][0])
			{
				if(name[j].length()>1)newnode(j);
				else check[i][j]=1;
			}
		}
//		cout<<endl;
	}
//	for(int i=1;i<=cnt;i++)
//	{
//		for(int j=0;j<s2.length();j++)cout<<check[j][i];
//		cout<<endl;
//	}
	for(int i=0;i<s2.length();i++)
	{
		dp[i]=dp[i-1];
		for(int j=1;j<=cnt;j++)
		{
			dp[i]=max(dp[i],check[i][j]*(int)(dp[i-name[j].length()]+name[j].length()));
		}
	}
	cout<<dp[s2.length()-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

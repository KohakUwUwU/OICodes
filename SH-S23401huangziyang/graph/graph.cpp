#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=(1<<11)+5;
int q,f[N],l2[N];
vector<int>G[N];
inline void addEdge(int u,int v)
{
	G[u].push_back(v);
}
inline int lowbit(int x)
{
	return x&-x;
}
inline void print(int x)
{
	cout<<"f["<<x<<"]="<<f[x]<<'\n';
}
inline int dfs(int s,int t,int cur)
{
//	cout<<"cur="<<cur<<'\n';
	if(t!=cur&&l2[cur]==l2[t])return 0;
	if(cur==t)
	{
//		cout<<"%";
		f[t]=1;
		return 1;
	}
	if(f[cur])return f[cur];
	if(cur>t)return 0;
	int x=cur+lowbit(cur)-1;
	while(((x+1)|s)-s<=t)
	{
		x=(x+1)|s;
//		cout<<x-s<<'\n';
		int tmp=dfs(s,t,x-s);
		f[cur]+=tmp;
	}
	return f[cur];
}
signed main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>q;
	l2[1]=0;
	for(int i=2;i<=1<<11;i++)l2[i]=l2[i/2]+1;
//	cout<<l2[2]<<' '<<l2[3]<<'\n';
	for(int i=0;i<=(1<<10)+5;i++)for(int j=i+1;j<=(1<<10)+5;j++)if(i&j==0)addEdge(i,j);
	for(int i=1;i<=q;i++)
	{
		for(int j=0;j<=(1<<10)+5;j++)f[j]=0;
		int s=0,t=0;
		string s1,t1;
		cin>>s1>>t1;
		for(int j=0;j<s1.length();j++)s+=(s1[j]-'0')*(1<<(s1.length()-j-1));
		for(int j=0;j<t1.length();j++)t+=(t1[j]-'0')*(1<<(t1.length()-j-1));
//		cout<<s<<' '<<t<<"\n";
		cout<<dfs(s,t,s)<<'\n';
	}
	return 0;
}

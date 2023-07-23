//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
string s,t;
priority_queue<pair<pair<int,int>,string> >q;
inline int calc(string str)
{
	int ans=0;
	for(int i=0;i<str.length()-2;i++)
	{
		if(str[i]=='s'&&str[i+1]=='o'&&str[i+2]=='s')ans++;
	}
	return ans;
}
signed main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>t;
		int ans=calc(t);
		q.push(make_pair(make_pair(ans,n-i),s));
	}
	int bst=q.top().first.first;
	while(q.top().first.first==bst)
	{
		cout<<q.top().second<<' ';
		q.pop();
	}
	cout<<'\n'<<bst;
	return 0;
}

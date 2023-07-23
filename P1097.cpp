//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

priority_queue<int,vector<int>,greater<int> >q;
map<int,int>ma;
int n,temp;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		ma[temp]++;
		q.push(temp);
	}
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		if(ma[u])cout<<u<<' '<<ma[u]<<'\n';
		ma[u]=0;
	}
	return 0;
}


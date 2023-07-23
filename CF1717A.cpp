//Project Sekai
#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5;
int t;
int ans[N];
pair<int,int>q[N];
signed main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)cin>>q[i].first,q[i].second=i;
	sort(q+1,q+1+t);
	int n=q[t].first;
	int cur=0,id=1;
	for(int i=1;i<=n;i++)
	{
		cur++;
		if(i%2==0)cur+=2;
		if(i%3==0)cur+=2;
		while(q[id].first==i)
		{
			ans[q[id].second]=cur;
			id++;
		}
	}
	for(int i=1;i<=t;i++)cout<<ans[i]<<' ';
	return 0;
}


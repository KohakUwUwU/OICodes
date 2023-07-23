//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
int n,k,a[N];
priority_queue<int>q;
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)q.push(a[i]);
	while(q.size()-1)
	{
		int x=q.top();
		q.pop();
		int y=q.top();
		q.pop();
		q.push((x+y)/k);
	}
	cout<<q.top();
	return 0;
}


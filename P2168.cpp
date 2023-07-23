//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
	int val,dep;
	bool operator<(node a)const
	{
		return (val==a.val)?(dep>a.dep):(val>a.val);
	}
};
priority_queue<node>q;
int n,k,kagamine,rin;
int ans1,ans2;
signed main()
{
	cin>>n>>k;
	for(int i=1,tmp;i<=n;i++)cin>>tmp,q.push((node){tmp,0});
	while((n-1)%(k-1))q.push((node){0,0}),n++;
	while(q.size()!=1)
	{
		kagamine=rin=0;//Д¤Бе 
		for(int i=1;i<=k;i++)
		{
			node h=q.top();q.pop();
			kagamine+=h.val;
			rin=max(rin,(int)h.dep);
		}
		ans1+=kagamine;
		ans2=max(ans2,rin+1);
		q.push((node){kagamine,rin+1});
	}
	cout<<ans1<<'\n'<<ans2;
}

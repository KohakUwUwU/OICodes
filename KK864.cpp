#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n;
int bin[105],ans[N];
struct node
{
	int t,s,p;
}a[N];
inline bool cmp(node x,node y)
{
	if(x.s!=y.s)return x.s>y.s;
	else return x.t>y.t;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].t,a[i].p=i;
	for(int i=1;i<=n;i++)cin>>a[i].s;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int now=0;
		for(int j=0;j<a[i].t;j++)
		{
			now+=bin[j];
		}
		bin[a[i].t]++;
		ans[a[i].p]=now;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}

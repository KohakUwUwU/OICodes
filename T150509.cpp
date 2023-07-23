#include<iostream>
#include<algorithm>
using namespace std;
struct vo
{
	int t,val,time;
}ff[500001];
inline bool cmp(vo a,vo b)
{
	if(a.val!=b.val)return a.val>b.val;
	else if(a.time!=b.time)return a.time>b.time;
	else return a.t<b.t;
}
int main()
{
	int n,a,b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		ff[i].t=i;
		ff[i].time=a;
		ff[i].val=a*b;
	}
	sort(ff+1,ff+1+n,cmp);
	for(int i=1;i<=n;i++)cout<<ff[i].t<<" ";
}

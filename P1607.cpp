//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e4+5;
struct Cow
{
	int s,e,m;
}Data[N];
int k,n,c,q[3000]; 
inline bool cmp(Cow x,Cow y)
{
	return (x.e!=y.e)?(x.e<y.e):(x.s>y.s);
}
signed main()
{
	cin>>k>>n>>c;
	for(int i=1;i<=k;i++)cin>>Data[i].s>>Data[i].e>>Data[i].m;
	sort(Data+1,Data+1+k,cmp);
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		sort(q+1,q+1+c,greater<int>());
		for(int j=1;j<=c&&Data[i].m;j++)
		{
			if(q[j]<=Data[i].s)ans++,q[j]=Data[i].e,Data[i].m--;
		}
	}
	cout<<ans;
	return 0;
}


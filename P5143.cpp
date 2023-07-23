//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e4+5;
struct Node
{
	double x,y,z;
}t[N];
int n;
double ans;
inline double calc(int i)
{
	return sqrt((t[i].x-t[i-1].x)*(t[i].x-t[i-1].x)+(t[i].y-t[i-1].y)*(t[i].y-t[i-1].y)+(t[i].z-t[i-1].z)*(t[i].z-t[i-1].z));
}
inline bool cmp(Node x,Node y)
{
	return x.z<y.z;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>t[i].x>>t[i].y>>t[i].z;
	sort(t+1,t+1+n,cmp);
	for(int i=2;i<=n;i++)ans+=calc(i);
	cout<<fixed<<setprecision(3)<<ans;
	return 0;
}


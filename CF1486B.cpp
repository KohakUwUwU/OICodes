//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=1005;
int dx[N],dy[N];
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int mn=114514114514,cnt=114514;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>dx[i]>>dy[i];
		if(n%2==1)
		{
			cout<<1<<'\n';
			continue;
		}
		sort(dx+1,dx+1+n);
		sort(dy+1,dy+1+n);
		cout<<(dx[n/2+1]-dx[n/2]+1)*(dy[n/2+1]-dy[n/2]+1)<<'\n';
	}
	return 0;
}


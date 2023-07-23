//Project Sekai
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,m,p[N],cnt,last,taskUnpro,timeOverflow,a[N];
inline bool check(int allTime)
{
	for(int i=1;i<=cnt;i++)
	{
		if(p[i]>allTime)
		{
			taskUnpro+=p[i]-allTime;	
		}
		else
		{
			timeOverflow+=(allTime-p[i])/2*2;
		}
		if(taskUnpro>timeOverflow/2)
		{
			taskUnpro-=timeOverflow/2;
			timeOverflow%=2;
		}
		else
		{
			timeOverflow-=taskUnpro*2;
			taskUnpro=0;
		}
	}
	if(allTime/2*(n-cnt)<taskUnpro)return false;
	return true;
}  
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=m;i++)cin>>a[i];
		sort(a+1,a+1+m);
		memset(p,0,sizeof(p));
		taskUnpro=timeOverflow=0;
		cnt=0;
		last=-1; 
		for(int i=1;i<=m;i++)
		{
			if(last!=a[i])++cnt;
			last=a[i];
			p[cnt]++;
		}
		int l=1,r=(m/n+1)*2;
		while(l!=r)
		{
			int mid=l+r>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}	
	return 0;
}


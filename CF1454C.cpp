#include<iostream>
#include<cstring>
#define N 200005
using namespace std;
int a[N],n;
//int time[N],yes[N];
//int vis[N];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int time[N]={},yes[N]={};
		int maxn=-1;
		cin>>n;
		int nn=0,cur=-1;
		for(int i=1;i<=n;i++)
		{
			int tmp;
			cin>>tmp;
			if(cur==tmp)continue;
			cur=tmp;
			a[++nn]=tmp;
			yes[tmp]=1;
			maxn=max(maxn,tmp);
		}
		if(nn==1)
		{
			cout<<0<<endl;
			continue;
		}
		n=nn;
		for(int i=2;i<n;i++)
		{
			time[a[i]]++;
		}
		
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,time[a[i]]+1);
		}
		cout<<ans<<endl;
	}
}

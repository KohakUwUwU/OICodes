//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
//printf scanf

const int N=2e5+45;
int uni[N];
int pre[N],ans[N];
vector<int>sc[N];
signed main()
{
	int t;
	cin>>t;
	while(t --> 0)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n+4;i++)sc[i].clear();
		for(int i=1;i<=n+4;i++)uni[i]=0;
		for(int i=1;i<=n+4;i++)ans[i]=0;
		for(int i=1;i<=n+4;i++)pre[i]=0;
		for(int i=1;i<=n;i++)scanf("%lld",&uni[i]);
		for(int i=1;i<=n;i++)
		{
			int temp;
			cin>>temp;
			sc[uni[i]].push_back(temp);
		}
		for(int i=1;i<=n;i++)ans[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(!sc[i].size())continue;
			sort(sc[i].begin(),sc[i].end());
			for(int j=0;j<=sc[i].size()+5;j++)pre[j]=0;
			for(int j=sc[i].size()-1;j>=0;j--)pre[j]=pre[j+1]+sc[i][j];
			for(int k=1;k<=n;k++)
			{
				if(k>sc[i].size())break;
				int temp=sc[i].size()%k;
				ans[k]+=pre[temp];
			}
		}
		for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
		cout<<'\n';
	}
	return 0;
}


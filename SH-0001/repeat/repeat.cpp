//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=55;
int n,m;
vector<int>group[N];
vector<int>dd;
map<int,int>ma;
signed main()
{
	freopen("repeat.in","r",stdin);
	freopen("repeat.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		for(int j=1;j<=tmp;j++)
		{
			int ttmp;
			cin>>ttmp;
			group[i].push_back(ttmp);
		}
	}
	for(int i=1;i<=n;i++)
	{
		sort(group[i].begin(),group[i].end());
		dd.clear();
		dd.push_back(group[i][0]);
		for(int j=1;j<group[i].size();j++)
		{
			if(dd[dd.size()-1]!=group[i][j])dd.push_back(group[i][j]);
		}
		group[i]=dd;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		ma.clear();
		int u1,u2;
		cin>>u1>>u2;
		int allcnt=0,uucnt=0;
		for(int j=0;j<group[u1].size();j++)
		{
			int v=group[u1][j];
			if(ma[v]==0)allcnt++,ma[v]=1;
			else uucnt++;
		}
		for(int j=0;j<group[u2].size();j++)
		{
			int v=group[u2][j];
			if(ma[v]==0)allcnt++,ma[v]=1;
			else uucnt++;
		}
		cout<<fixed<<setprecision(1)<<100.0*(double)(uucnt)/(double)(allcnt);
		cout<<"%\n";
	}
	return 0;
}


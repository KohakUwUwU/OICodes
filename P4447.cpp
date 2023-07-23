//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF=0x3f3f3f3f;
map<int,int>m;
int n,ans=INF,tmp;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		m[tmp]++;
	}
	while(!m.empty())
	{
		map<int,int>::iterator i=m.begin(),j=m.begin();
		tmp=1;
		for(++j,--(*i).second;j!=m.end()&&(*j).first==(*i).first+1&&(*j).second>(*i).second;++i,++j)++tmp,--(*j).second;
		i=m.begin();
		while(i!=m.end()&&(*i).second==0)m.erase((*i++).first);
		if(tmp<ans)ans=tmp;
	}
	cout<<ans;
	return 0;
}

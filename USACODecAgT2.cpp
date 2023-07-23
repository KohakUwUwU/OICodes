//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=500005;
vector<int>item[N];
int f[N],T,n,m;

inline int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
inline int rin(int x,int y)
{
    int rin=1e9;
    for(auto it:item[y])
	{
        int pos=lower_bound(item[x].begin(),item[x].end(),it)-item[x].begin();
        if(pos!=item[x].size())rin=min(rin,item[x][pos]-it);
        if(pos!=0)rin=min(rin,it-item[x][pos-1]);
    }
    return rin;
}
inline int tjks(int x)
{
    int y=x/2,z=x-y;
    return y*y+z*z;
}
signed main()
{
	cin>>T;
    while(T--)
    {
    	cin>>n>>m;
	    iota(f+1,f+n+1,1);
	    for(int i=1;i<=n;i++)item[i].clear();
	    for(int i=1,u,v;i<=m;i++)cin>>u>>v,f[find(u)]=find(v);
	    for(int i=1;i<=n;i++)item[find(i)].push_back(i);
	    int x=find(1),y=find(n);
	    if(x==y)
	    {
	    	cout<<"0\n";
			continue;
		}
	    int ans=114514114514,dis=rin(x,y);
	    ans=min(ans,tjks(dis));
	    for(int i=1;i<=n;i++)if(i!=x&&i!=y&&item[i].size())ans=min(ans,rin(x,i)*rin(x,i)+rin(y,i)*rin(y,i));
	    cout<<ans<<'\n';
	}
    return 0;   
}

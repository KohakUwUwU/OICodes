//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=400005;
struct node
{
    int pos,val;
    friend bool operator<(const node&a,const node&b)
	{
        if(a.pos!=b.pos)return a.pos<b.pos;
        else return a.val<b.val;
    }
}a[N],b[N],c[N];
int n,m,K;
vector<int>G;
signed main()
{
	cin>>n>>m>>K;
	for(int i=1;i<=n;i++)cin>>a[i].pos>>a[i].val,a[i].pos*=2;
	for(int i=1;i<=m;i++)cin>>b[i].pos,b[i].pos*=2;
	sort(a+1,a+1+n);sort(b+1,b+1+m);
    int h=1;
    {
        int get=0;
        while(h<=n&&a[h].pos<b[1].pos)get+=a[h].val,++h; 
        G.push_back(get);
    }
	for(int i=2;i<=m;i++)
	{
        int get=0,len=0,cur=0,mx=0;
        while(h<=n&&a[h].pos<b[i].pos)
		{
            get+=a[h].val;
            int t=min(a[h].pos-b[i-1].pos,b[i].pos-a[h].pos)-1;
            c[++len]={a[h].pos-t,a[h].val},c[++len]={a[h].pos+t+1,-a[h].val},++h;
        }
        sort(c+1,c+len+1);
		for(int l=1;l<=len;l++)
		{
            int j=l;
            while(j<len&&c[j].pos==c[j+1].pos)cur+=c[j].val,++j;
            cur+=c[j].val,mx=max(mx,cur),l=j;
        } 
        G.push_back(mx),G.push_back(get-mx);
    }
    {
        int get=0;
        while(h<=n)get+=a[h].val,++h;
        G.push_back(get);
    }
    sort(G.begin(),G.end(),greater<int>());
    int ans=0;
    for(int i=1;i<=K&&i<=G.size();i++)ans+=G[i-1];
    cout<<ans;
    return 0;
}

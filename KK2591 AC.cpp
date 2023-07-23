#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node
{
	int x,y,op;
	bool operator<(const node&t)const{return(x<t.x)||(x==t.x&&op<t.op);}
}a[200003];
int n=read(),m=read();
set<int> s;
signed main()
{
	freopen("iron.in","r",stdin);
	freopen("iron.out","w",stdout); 
    for(int i=1; i<=n; ++i) a[i].x=read();
    for(int i=1; i<=n; ++i) a[i].y=read();
    for(int i=n+1; i<=n+m; ++i) a[i].x=read(),a[i].op=1;
    for(int i=n+1; i<=n+m; ++i) a[i].y=read();
    sort(a+1,a+n+m+1);
    int ans=0;
    for(int i=1; i<=n+m; ++i)
    {
    	if(a[i].op) 
    	{
    		set<int>::iterator it=s.upper_bound(a[i].y);
    		if(it!=s.begin())
    			--it,ans=max(ans,(*it)-a[i].x+1);
    	}
    	else s.insert(a[i].y);
    }
    printf("%lld\n",ans);
	return 0;
}


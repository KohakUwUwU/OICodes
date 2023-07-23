//And in that light,I find deliverance.
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
struct node{int d,t;};
deque<node> q2,q;
signed main()
{
	freopen("tablecloth.in","r",stdin);
	freopen("tablecloth.out","w",stdout);
    int n=read(),n1=read(),n2=read(),c1=read(),c2=read(),m=read();
    if(c1>c2) swap(c1,c2),swap(n1,n2);
    //前面的更便宜但是更慢
    if(n1<=n2) c2=c1,n2=n1;
    int ans=0;
    for(int i=1,D=0; i<=n; ++i)
    {
    	while(!q.empty()&&i-q.front().t>=n2) 
    		q2.push_back(q.front()),q.pop_front();
    	while(!q2.empty()&&i-q2.front().t>=n1) 
    		D+=q2.front().d,q2.pop_front();
    	int s=read();	
    	q.push_back((node){s,i});
    	if(m>=s){m-=s;continue;}
    	s-=m,m=0;
    	if(D>=s){ans+=c1*s;D-=s;continue;}
    	ans+=c1*D,s-=D,D=0;
    	while(!q2.empty())
	    {
	    	int A=q2.back().d;
	    	int t=q2.back().t;
	    	q2.pop_back();
	    	if(s<=A)
	    	{
	    		ans+=c2*s,A-=s,s=0,q2.push_back((node){A,t});
	    		break;
	    	}
	    	ans+=c2*A,s-=A;
	    }
    	if(s)
    	{
    		puts("-1");
    		return 0;
    	}
    }
    printf("%lld\n",ans);
	return 0;
}


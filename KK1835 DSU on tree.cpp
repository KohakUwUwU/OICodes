#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define in inline
namespace fast_io
{
    char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
    in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
    in ll read()
    {
        ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
        x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
    }
    in db gf() {re a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
    in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
    in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
    in void flush() {if(C>1<<22) ot();}
    template <typename T>
    in void print(T x,char t)
    {
        re y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
        if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
    }
    in void print(char *s) {re l=strlen(s);for(re i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
};
using namespace fast_io;
//instructions:
//ll long long
//re register int
//db double
//in inline
//gc() getchar
//read() read ll_type
//gf() getdouble
//gs() getchar*
//flush() flush
//print() printf int+char or char*
//remember ot(),return 0;

#define N 200005
vector<int>e[N];
int n,m,timer,clc,cnt[N],ans[N],tI[N],tO[N],clr[N],q[N],sz[N],son[N],dfn[N];
inline void init(int u,int fa)
{
	sz[u]=1,son[u]=0,dfn[tI[u]=++timer]=u;
	for(int i=0;i<e[u].size();i++)
	{
		if(e[u][i]==fa)continue;
		init(e[u][i],u);
		sz[u]+=sz[e[u][i]];
		if(sz[son[u]]<sz[e[u][i]])son[u]=e[u][i];
	}
	tO[u]=timer;
}
inline void an(int u,bool ff)
{
	ff?clc+=(++cnt[clr[u]]==1):clc-=(--cnt[clr[u]]==0);
}
inline void at(int u,bool ff)
{
	for(int i=tI[u];i<=tO[u];i++)an(dfn[i],ff);
}
inline void dfs(int u,int fa,bool hvy)
{
	for(int i=0;i<e[u].size();i++)if(e[u][i]!=son[u]&&e[u][i]!=fa)dfs(e[u][i],u,0);//回答轻儿子询问
	if(son[u])dfs(son[u],u,1);//回答重儿子询问不清
	for(int i=0;i<e[u].size();i++)if(e[u][i]!=son[u]&&e[u][i]!=fa)at(e[u][i],1);//并入轻儿子信息
	an(u,1);//并入u
	ans[u]=clc;//回答
	if(!hvy)at(u,0);//u轻清
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=read();
	for(int i=1,j,k;i<n;i++)j=read(),k=read(),e[j].push_back(k),e[k].push_back(j);
	for(int i=1;i<=n;i++)clr[i]=read();
	m=read();
	for(int i=1;i<=m;i++)q[i]=read();
	init(1,0);
	dfs(1,0,0);
	for(int i=1;i<=m;i++)print(ans[q[i]],' ');
	ot();
	fclose(stdin);
	fclose(stdout);
    return 0;
}


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

#define N 500005
#define INF 2147483647
int n,m,s;
int dis[N];
struct cmp
{
	bool operator()(int x,int y){return dis[x]>dis[y];}
};
vector<int>e[N];
priority_queue<int,vector<int>,cmp>sta;
inline void addEdge(int u,int v)
{
	e[u].push_back(v),e[v].push_back(u);
}
int main()
{
//	freopen("P3371_1.in","r",stdin);
//	freopen("","w",stdout);
	n=read(),m=read(),s=read();
	for(int i=1,j,k;i<=m;i++)j=read(),k=read(),addEdge(j,k);
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[s]=0;
	sta.push(s);
	while(!sta.empty())
	{
		int x=sta.top();
		sta.pop();
		for(int i=0;i<e[x].size();i++)
		{
			if(dis[e[x][i]]>dis[x]+e[x][i])
			{
				sta.push(x);
				dis[e[x][i]]=dis[x]+e[x][i];
			}
		}
	}
	for(int i=1;i<=n;i++)print(dis[i],' ');
	fclose(stdin);
	fclose(stdout);
	return ot(),0;
}


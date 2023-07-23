//And in that light, I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x*w;
}

const int N=3e5+1;
struct BST
{
	int ch[2],val,cnt,sz;
}t[N];
int m,n,cnt=1,curAdd;
int aQ[N];
inline void Add(int x,int p,int c)
{
	if(t[p].val==x)
	{
		t[p].cnt+=c,t[p].sz+=c;
		return ;
	}
	int d=(t[p].val<x);
	if(!t[p].ch[d])t[p].ch[d]=++cnt,t[cnt].val=x;
	Add(x,t[p].ch[d],c);
	t[p].sz=t[t[p].ch[0]].sz+t[t[p].ch[1]].sz+t[p].cnt;
}
inline int Kth(int k,int p)
{
	int chs=t[t[p].ch[0]].sz;
	if(k<=chs)return Kth(k,t[p].ch[0]);
	if(k<=chs+t[p].cnt)return t[p].val;
	return Kth(k-chs-t[p].cnt,t[p].ch[1]);
}
signed main()
{
	m=read(),n=read();
	for(int i=1;i<=m;i++)aQ[i]=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		while(curAdd<x)Add(aQ[++curAdd],1,1);
		cout<<Kth(i,1)<<'\n';
//		cout<<'%';
	}
	return 0;
}

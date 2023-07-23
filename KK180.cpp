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

const int mod=1e6;
const int N=8e4+5;
struct BST
{
	int fa,ch[2],val,sz,cnt;
}t[N];
int n,b[N],cur,ans,cnt=1;//cur动态计算set中元素种类 
inline void Insert(int x,int p)
{
	if(t[p].val==x)
	{
		t[p].cnt++,t[p].sz++;
		return ;
	}
	int ch=(t[p].val<x);
	if(!t[p].ch[ch])t[p].ch[ch]=++cnt,t[cnt].val=x,t[cnt].fa=p;
	Insert(x,t[p].ch[ch]);
	t[p].sz=t[t[p].ch[0]].sz+t[t[p].ch[1]].sz+t[p].cnt;
}
inline int Rank(int x,int p)//排名 
{
	if(!t[p].cnt)
	{
		if(t[p].val==x)return 0;
		if(t[p].val<x)return Rank(x,t[p].ch[1]);
		return Rank(x,t[p].ch[0]);
	}
	if(x<t[p].val)return Rank(x,t[p].ch[0]);
	if(x==t[p].val)return t[t[p].ch[0]].sz+1;
	return t[t[p].ch[0]].sz+t[p].cnt+Rank(x,t[p].ch[1]);
}
inline int Kth(int k,int p)//第k大坐标 
{
	if(k<=t[t[p].ch[0]].sz)return Kth(k,t[p].ch[0]);
	if(k<=t[t[p].ch[0]].sz+t[p].cnt)return p;
	return Kth(k-t[t[p].ch[0]].sz-t[p].cnt,t[p].ch[1]);
}
inline void Del(int p)//删除坐标
{
	if(t[p].cnt)t[p].cnt--;
	while(t[p].fa)
	{
		p=t[p].fa;
		t[p].sz=t[t[p].ch[0]].sz+t[t[p].ch[1]].sz+t[p].cnt;
	}
} 
signed main()
{
//	freopen("holy.in","r",stdin);
//	freopen("holy.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(cur>=0&&b[i]==1||cur<=0&&b[i]==0)Insert(x,1);
		else
		{
			Insert(x,1);
			int rk=Rank(x,1);
			Del(Kth(rk,1));
			cout<<'?';
			int pre=((rk-1)?Kth(rk-1,1):0),suc=(abs(cur)>=rk?Kth(rk,1):0);
			cout<<'?';
			int preval=t[pre].val,sucval=t[suc].val;
			if(x-preval<=sucval-x)Del(pre);
			else Del(suc);
			ans+=min(x-preval,sucval-x);
		}
		if(b[i]==0)cur--;
		else cur++;
	}
	cout<<ans;
	return 0;
}


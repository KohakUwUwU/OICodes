#include<bits/stdc++.h>
#define N (int)1e7+5
using namespace std;
int n,opt,p;
int rt,tot,fa[N],ch[N][2],val[N],cnt[N],sz[N];
//根节点，节点总数，父亲，孩子，权值，并点，子树大小 
inline void maintain(int x)//维护子树大小 
{
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+cnt[x];
}
inline bool get(int x)//获取x的孩子信息 
{
	return x==ch[fa[x]][1];
}
inline void clear(int x)//销毁节点 
{
	fa[x]=ch[x][0]=ch[x][1]=val[x]=cnt[x]=sz[x]=0;
}
inline void rotate(int x)//上抬 
{
	int y=fa[x],z=fa[y],chk=get(x);
	ch[y][chk]=ch[x][chk^1];
	fa[ch[y][chk]]=y;
	ch[x][chk^1]=y;
	fa[y]=x;
	fa[x]=z;
	if(z)ch[z][y==ch[z][1]]=x;
	maintain(y);
	maintain(x);
}
inline void splay(int x)//核心操作
{
	for(int f=fa[x];f=fa[x],f;rotate(x))
		if(fa[f])rotate(get(f)==get(x)?f:x);
	rt=x;
}//别忘了维护根！
inline void ins(int x)//插入 
{
	if(!rt)
	{
		val[++tot]=x;
		cnt[tot]++;
		rt=tot;
		maintain(tot);
		return ;
	}
	int cnr=rt,f=0;
	while(1)
	{
		if(val[cnr]==x)
		{
			cnt[tot]++;
			maintain(cnr);
			maintain(f);
			splay(cnr);
			return ;
		}
		f=cnr;
		cnr=ch[cnr][val[cnr]<x];
		if(!cnr)
		{
			val[++tot]=x;
			cnt[tot]++;
			ch[f][val[f]<x]=tot;
			fa[tot]=f;
			maintain(cnr);
			maintain(f);
			splay(tot);
			return ;
		}
	}
} 
inline int rk(int x)//x的排名 
{
	int cnr=rt,res=0;
	while(1)
	{
		
	}
}
inline int kth(int x)//第k小 
{
}
inline int pre(int x)//前驱
{
} 
inline int suc(int x)//后继
{
} 
inline int del(int x)//删除节点 
{
}
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>opt>>p;
		
	}
}

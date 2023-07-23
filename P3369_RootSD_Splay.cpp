//TEmPTaTiON
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
struct Splay
{
	int cnt,rt,fa[N],dat[N],sz[N],rpnum[N],son[N][2];
	Splay()
	{
		sz=rt=0;
		memset(fa,0,sizeof(fa));
		memset(dat,0,sizeof(dat));
		memset(sz,0,sizeof(sz));
		memset(rpnum,0,sizeof(rpnum));
		memset(son,0,sizeof(son));
	}
	inline void clear(int p)
	{
		fa[p]=val[p]=sz[p]=rpnum[p]=son[p][0]=son[p][1]=0;
	}
	inline int get(int p)
	{
		return son[fa[p]][1]==p;
	}
	inline void update(int p)
	{
		if(p)
		{
			sz[p]=rpnum[p];
			if(son[p][0])sz[p]+=sz[son[p][0]];
			if(son[p][1])sz[p]+=sz[son[p][1]];
		}
	}
	inline void connect(int s,int f,int rship)
	{
		if(s)fa[s]=f;
		if(f)son[f][rship]=s;
	}
	inline void rotate(int p)
	{
		int f=fa[p],gf=fa[f];
		int rp=get(p),rf=get(f);
		connect(son[p][rp^1],f,rp);
		connect(f,p,rp^1);
		connect(p,gf,rf);
		//自下向上更新sz
		update(f);update(p);
	}
	inline void splay(int p)
	{
		for(int f;f=fa[p];rotate(p))if(fa[f])rotate(get(p)==get(f)?f:p);
		rt=p;
	}
	inline int find(int val)
	{
		int now=rt,ret=0;
		while(1)
		{
			if(val<dat[now])
			{
				now=son[now][0];
				continue;
			}
			ret+=sz[son[now][0]];
			if(val==dat[now])
			{
				splay(now);
				return ret+1;
			}
			ret+=rpnum[now];
			now=son[now][1];
		}
	}
	inline int kth(int k)
	{
		int now=rt;
		while(1)
		{
			if(son[now][0]&&k<=sz[son[now][0]])
			{
				now=son[now][0];
				continue;
			}
			if(son[now][0])k-=sz[son[now][0]];
			if(k<=rpnum[now])
			{
				splay(now);
				return dat[now];
			}
			val-=rpnum[now];
			now=son[now][1];
		}
	}
	inline void insert(int val)
	{
		if(!root)
		{
			root=++cnt;
			dat[cnt]=val;

		}
	}
}
signed main()
{

	return 0;
}
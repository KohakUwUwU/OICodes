#include<bits/stdc++.h>
#define N (int)1e7+5
using namespace std;
int n,opt,p;
int rt,tot,fa[N],ch[N][2],val[N],cnt[N],sz[N];
//���ڵ㣬�ڵ����������ף����ӣ�Ȩֵ�����㣬������С 
inline void maintain(int x)//ά��������С 
{
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+cnt[x];
}
inline bool get(int x)//��ȡx�ĺ�����Ϣ 
{
	return x==ch[fa[x]][1];
}
inline void clear(int x)//���ٽڵ� 
{
	fa[x]=ch[x][0]=ch[x][1]=val[x]=cnt[x]=sz[x]=0;
}
inline void rotate(int x)//��̧ 
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
inline void splay(int x)//���Ĳ���
{
	for(int f=fa[x];f=fa[x],f;rotate(x))
		if(fa[f])rotate(get(f)==get(x)?f:x);
	rt=x;
}//������ά������
inline void ins(int x)//���� 
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
inline int rk(int x)//x������ 
{
	int cnr=rt,res=0;
	while(1)
	{
		
	}
}
inline int kth(int x)//��kС 
{
}
inline int pre(int x)//ǰ��
{
} 
inline int suc(int x)//���
{
} 
inline int del(int x)//ɾ���ڵ� 
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

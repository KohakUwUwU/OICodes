#include<bits/stdc++.h>
#define N (int)5e5+5
using namespace std;
struct node
{
	int n,dep,len;
	vector<int> to;
	vector<int> dis;
	vector<int> pin;
	//n   连边个数
	//to  指针
	//dis 长度
	//pin 边出现时间 
	//dep 深度 
	//len 到根长度 
}tree[N];
int n,q;
int query[N][4];//询问 
int vis[N];//建树 
int f[N][21],t[N][21];//倍增祖先/时间 
string str;
inline int getInt(int st,int ed)
{
	int s;
	for(int i=st;i<=ed;i++)s=s*10+str[i]-'0';
	return s;
}
inline void addNode(int k)
{
	int a=query[k][1],b=query[k][2],c=query[k][3];
	tree[a].n++;
	tree[b].n++;
	tree[a].to.push_back(b);tree[a].dis.push_back(c);
	tree[b].to.push_back(a);tree[b].dis.push_back(c);
	tree[a].pin.push_back(k);tree[b].pin.push_back(k);
}
inline void dfs(int k,int dep,int fa)
{
	node* p=&tree[k];
	vis[k]=1;
	p->dep=dep;
	for(int i=0;i<p->n;i++)
	{
		if(p->to[i]==fa)continue;
		f[p->to[i]][0]=k;
		t[p->to[i]][0]=p->pin[i];
		tree[p->to[i]].len=p->len+p->dis[i];
		dfs(p->to[i],dep+1,k);
	}
}
inline void init()
{
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[j][i]=f[f[j][i-1]][i-1];
			t[j][i]=max(t[j][i-1],t[f[j][i-1]][i-1]);
		}
	}
}
inline int lca(int x,int y,int k)
{
	//首先跳到同一高度
	if(tree[x].dep<tree[y].dep)swap(x,y);
	int xx=x,yy=y;
	int i=20,mxt=-1;
	while(tree[x].dep>tree[y].dep)
	{
		if(tree[x].dep-(1<<i)>=tree[y].dep)mxt=max(mxt,t[x][i]),x=f[x][i];
		i--;
	}
	//然后求LCA 
	if(x==y&&k>mxt)return tree[xx].len-tree[yy].len;
	i=20;
	while(f[x][0]!=f[y][0])
	{
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i],mxt=max(mxt,max(t[x][i],t[y][i]));
		i--;
	}
	int anc=f[x][0];
	//判断，返回 
	if(k<mxt||!anc)return -1;
	return tree[xx].len+tree[yy].len-2*tree[anc].len;
}
int main()
{
	freopen("treelink.in","r",stdin);
	freopen("treelink.out","w",stdout);
	int cncnt=0,getI=0;
	string input;
	getline(cin,input);
	input+=' ';
	for(int i=0;i<input.length();i++)
	{
		if(input[i]==' ')
		{
			if(cncnt==0)n=getI,getI=0,cncnt++;
			else q=getI;
		}
		else getI=getI*10+input[i]-'0';
	}
	for(int i=1;i<=q;i++)
	{
		int flag=0;
		getline(cin,str);
		str+=' ';
		for(int j=0;j<str.length();j++)
		{
			if(str[j]!=' ')continue;
			query[i][++query[i][0]]=getInt(flag,j-1);
			j++;
			flag=j;
		}
		if(query[i][0]==3)addNode(i);//邻接 
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0,0);
	init();
	for(int i=1;i<=q;i++)
	{
		if(query[i][0]==2)cout<<lca(query[i][1],query[i][2],i)<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
#define N (int)5e5+5
using namespace std;

//Variables
struct node
{
	int n,to[4],len[4],time[4];
	//计数器 指向 长度 时间 
}tree[N];
struct info
{
	int len,ch[2],cl[2],fa,fal,dep,time;
	//长度前缀和 子节点 子长 父长 深度 时间  
}rin[N];
string str;
int n,q;
int query[N][5];//询问 
int lca[N][22];//倍增祖先 
int lti[N][22];//倍增时间 
int Log[N];//小优化 

//Dependency&Fuction
inline void debug_tool()
{
	printf("RIN AK IOI!\n");
}
inline void opLCA()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=20;j++)cout<<lca[i][j]<<' ';
		cout<<'\n';
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=20;j++)cout<<lti[i][j]<<' ';
		cout<<'\n';
	}
}
inline int getInt(int st,int ed)
{
	int s;
	for(int i=st;i<=ed;i++)s=s*10+str[i]-'0';
	return s;
}
inline void addNode(int k)
{
	tree[query[k][1]].to[++tree[query[k][1]].n]=query[k][2];
	tree[query[k][2]].to[++tree[query[k][2]].n]=query[k][1];
	tree[query[k][1]].len[tree[query[k][1]].n]=tree[query[k][2]].len[tree[query[k][2]].n]=query[k][3];
	tree[query[k][1]].time[tree[query[k][1]].n]=tree[query[k][2]].time[tree[query[k][2]].n]=k;
	rin[query[k][1]].time=rin[query[k][2]].time=k;
}
inline void printNode()
{
	for(int i=1;i<=n;i++)
	{
		cout<<tree[i].n<<'\n';
		for(int j=1;j<=tree[i].n;j++)cout<<tree[i].len[j]<<' '<<tree[i].time[j]<<' '<<tree[i].to[j]<<'\n';
	}
}
inline void dfs(int k,int fa,int lgt)
{
	lca[k][0]=fa;
	lti[k][0]=lgt;
	rin[k].fa=fa;
	rin[k].dep=rin[fa].dep+1;
	for(int i=1,j=0;i<=tree[i].n;i++)
	{
		if(tree[k].to[i]==fa)
		{
			rin[k].len=rin[fa].len+tree[k].len[i];
			rin[k].fal=tree[k].len[i];
			continue;
		}
		rin[k].ch[j]=tree[k].to[i];
		rin[k].cl[j++]=tree[k].len[i];
		dfs(tree[k].to[i],k,tree[k].time[i]);
	}
}
inline void LCA()
{
	int sizLCA=Log[n]+1;
	for(int i=1;i<=sizLCA;i++)for(int j=1;j<=n;j++)lca[j][i]=lca[lca[j][i-1]][i-1];
	for(int i=1;i<=sizLCA;i++)for(int j=1;j<=n;j++)lti[j][i]=max(lti[j][i-1],lti[j+(1<<(i-1))+1][i-1]);
}
inline int kta(int x,int k)//x的k辈祖先（倍增）
{
	int i=21;
	while(k&&(i--))if(k>=(1<<i))x=lca[x][i],k-=(1<<i);
	return x;
} 
inline int queryLCA(int x,int y)
{
	int xx=x,yy=y;
	if(rin[x].dep<rin[y].dep)swap(x,y);
	int i=21;
	while(rin[x].dep!=rin[y].dep&&(i--))if(rin[x].dep-(1<<i)>=rin[y].dep)x=lca[x][i];
	i=21;
	while(rin[x].fa!=rin[y].fa&&(i--)&&rin[x].fa)if(lca[x][i]!=lca[y][i])x=lca[x][i],y=lca[y][i];
	x=lca[x][0];y=lca[y][0];
	if(!x)return -1;
	int delta_depx=rin[xx].dep-rin[x].dep,delta_depy=rin[yy].dep-rin[y].dep;
	int logx=Log[delta_depx],logy=Log[delta_depy];
	if(max(max(lti[xx][logx],lti[kta(xx,delta_depx-logx)][logx]),max(lti[yy][logy],lti[kta(yy,delta_depy-logy)][logy])))
	{
		return -1;
	}
	return x;
}

//Main running
inline void initN_Q()
{
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
}
inline void loging()
{
	Log[0]=-1;
	for(int i=1;i<=n;i++)Log[i]=Log[i/2]+1;
}
inline void readQuery()
{
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
}
inline void runMain()
{
	rin[0].dep=-1;
	for(int i=1;i<=n;i++)//邻接->树 
	{
		if(tree[i].n==2)dfs(i,0,0);
	}
	//
//	for(int i=1;i<=n;i++)cout<<lca[i][0]<<' '<<lti[i][0]<<' '<<rin[i].fa<<' '<<rin[i].dep<<' '<<rin[i].time<<endl;
	//
	LCA();
//	opLCA();
	for(int i=1;i<=q;i++)
	{
		if(query[i][0]==2)
		{
			int x=queryLCA(query[i][1],query[i][2]);
			if(x==-1)
			{
				cout<<-1<<'\n';
				continue;
			}
			cout<<rin[query[i][1]].len+rin[query[i][2]].len-2*rin[x].len<<'\n';
		}
	}
}

int main()
{
//	freopen("treelink.in","r",stdin);
//	freopen("treelink.out","w",stdout);
	initN_Q();
	loging();
	readQuery();
//	printNode(); //调试到这里完全正确 
	runMain();
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

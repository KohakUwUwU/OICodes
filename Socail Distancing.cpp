#include<iostream>
#define N (int)1e6+5
using namespace std;
struct node
{
	vector<int> ch,sz,link; 
	int fa,dep,sum,ans;
	//ch ���ӽڵ�
	//sz ������С��������ǰ�ڵ㣩 
	//link ������ǰ�����ӽڵ�ıߵı��
};
int n,q,fa[N],dep[N],sum[N],ans[N];
vector<node> tree;
inline void initCin()
{
	cin>>n;
	tree.resize(n);
	for(int i=1;i<n;i++)
	{
		cin>>tree[i].fa;
		tree[i].ch.push_back(tree[i].fa);
		tree[tree[i].fa].ch.push_back(i);
		tree[i]
	}
}
int main()
{
	initCin();
	dfs(0,-1,0);
	cin>>q;
	while(q--)
	{
		int opt,u,v;
		cin>>opt;
		if(opt==1)opt1();
		if(opt==2)opt2();
		if(opt==3)opt3();
	}
}

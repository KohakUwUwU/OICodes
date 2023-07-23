#include<bits/stdc++.h>
#define maxn 10001
using namespace std;
std::vector <std::vector <int> >r;//result
std::vector <std::vector <int> >* k;
int tree[maxn][maxn],f_tree;//子树
int circle[maxn], node[maxn], f_circle,circlearr[maxn][maxn];
bool vis[maxn], vis_tree[maxn];
int n;


void build(std::vector <std::vector <int> > b);

inline void dfs(int pos)
{
	for (int i = 0; i < n; i++)
	{
		if ((*k)[pos][i] == 1 && !vis[i])
		{
			tree[f_tree][++tree[f_tree][0]] = i;
			node[i] = f_tree;
			r[pos][i] = r[pos][i] = 1;
			vis[i] = true;
			dfs(i);
		}
	}
}


inline int dfsCircle(int pos)
{
	int num = 1;
	for (int i = 1; i <= f_circle; i++)
	{
		if ((*k)[tree[pos][1]][tree[i][1]] == 2 && !vis_tree[i])
		{
			circlearr[f_circle][++circlearr[f_circle][0]] = i;
			vis_tree[i] = true;
			circle[i] = f_circle;
			num+=dfsCircle(i);
		}
	}
	return num;
}


int construct(std::vector <std::vector <int> > p)
{
	k = &p;
	n = p.size();
	r.resize(n);
	for(int i = 0; i < n; i++)r[i].resize(n);
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			if(p[i][j] == 3)return 0;
	for(int i = 0; i < n; i++)//搜点
	{
		if (!vis[i])
		{
			vis[i] = true;
			++f_tree;
			tree[f_tree][++tree[f_tree][0]] = i;
			node[i] = f_tree;
			dfs(i);
		}
	}
	for (int i = 1; i <= f_tree; i++)//搜连通块
	{
		if (!vis_tree[i])
		{
			vis_tree[i] = true;
			++f_circle;
			circle[i] = f_circle;
			circlearr[f_circle][++circlearr[f_circle][0]] = i;
			if (dfsCircle(i) == 2)return 0;
			r[circlearr[f_circle][1]][circlearr[f_circle][circlearr[f_circle][0]]] = r[circlearr[f_circle][circlearr[f_circle][0]]][circlearr[f_circle][1]] = 1;
			for (int j = 1; j < circlearr[f_circle][0]; j++)
			{
				r[circlearr[f_circle][j]][circlearr[f_circle][j + 1]] = r[circlearr[f_circle][j + 1]][circlearr[f_circle][j]] = 1;
			}
		}
	}
	int tmp = 0;
	for (int i = 0; i < n; i++)//判非法
	{
		for (int j = i; j < n; j++)
		{
			tmp = max(r[i][j], r[j][i]);
			r[i][j] = r[j][i] = tmp;
			if ((node[i] == node[j] && p[i][j] != 1) || (node[i] != node[j] && circle[node[i]] == circle[node[j]] && p[i][j] != 2) || (circle[node[i]] != circle[node[j]] && p[i][j] != 0))
			{
				return 0;
			}
		}
	}
	build(r);
	return 1;
}
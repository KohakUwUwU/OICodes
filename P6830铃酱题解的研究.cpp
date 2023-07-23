#include <bits/stdc++.h>
#define N 1000
std::vector<std::vector<int>> *G, ret;//G是输入文件 ret是输出文件 
void addedge(int x, int y) {
	ret[x][y] = ret[y][x] = 1;
}
int n, mx; char vis[N];//n 是输入文件的大小 mx是最大值 
std::vector<int> cnt, all, sm;
void dfs(int x) {
	vis[x] = 1;
	cnt.push_back(x);
	for (int i = 0; i < n; i++) {
		int d = (*G)[x][i];
		mx = std::max(d, mx);
		if (!vis[i] && d) dfs(i);
	}
}
void dfsS(int x) {
	vis[x] = 2;
	sm.push_back(x);
	for (int i = 0; i < n; i++) {
		if (vis[i] == 1 && (*G)[x][i] == 1) dfsS(i);
	}
}
int construct(std::vector<std::vector<int>> p) {
	G = &p; n = p.size();
	ret.resize(n);
	for (int i = 0; i < n; i++)
		ret[i].resize(n);
	for (int i = 0; i < n; i++) if (!vis[i]) {
		mx = 1;
		cnt.clear();
		dfs(i);
		if (mx == 3) return 0;
		for (int i = 1; i < cnt.size(); i++)
			for (int j = 0; j < i; j++)
				if (p[cnt[i]][cnt[j]] == 0)
					return 0;
		if (mx == 1) {
			for (int i = 1; i < cnt.size(); i++)
				addedge(cnt[0], cnt[i]);
			continue;
		}
		all.clear();
		for (int j : cnt) if (vis[j] == 1) {
			sm.clear();
			dfsS(j);
			for (int i = 1; i < sm.size(); i++) {
				for (int j = 0; j < i; j++)
					if (p[sm[i]][sm[j]] != 1)
						return 0;
				addedge(sm[0], sm[i]);
			}
			all.push_back(sm[0]);
		}
		if (all.size() <= 2) return 0;
		for (int j = 1; j < all.size(); j++)
			addedge(all[j-1], all[j]);
		addedge(all[0], all.back());
	}
	build(ret);
	return 1;
}

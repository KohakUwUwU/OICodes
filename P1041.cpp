#include<stdio.h>
int n,p,a,b,ans,h[301],thenext[602],dsti[602],size[301],f[301],dep[301],cnt,tree[301][301],pre[301],i,j,mk[301];
inline void add(){ 
	cnt++;
	thenext[cnt]=h[a];h[a]=cnt;dsti[cnt]=b;
	cnt++;
	thenext[cnt]=h[b];h[b]=cnt;dsti[cnt]=a;
	return ;
}
int dfs1(int u,int fa,int d){
	dep[u]=d;
	if(!tree[d][0])tree[0][0]++;
	tree[d][++tree[d][0]]=u;
	size[u]++;
	for(int i=h[u];i;i=thenext[i]){
		int v=dsti[i];
		if(v==fa)continue;
		f[v]=u;
		size[u]+=dfs1(v,u,d+1);
	}
	return size[u];
}
void del(int u,int fa){
	mk[u]=1;
	for(int i=h[u];i;i=thenext[i]){
		int v=dsti[i];
		if(v==fa)continue;
		del(v,u);
	}
	return ;
}

void redel(int u,int fa){
	mk[u]=0;
	for(int i=h[u];i;i=thenext[i]){
		int v=dsti[i];
		if(v==fa)continue;
		redel(v,u);
	}
	return ;
}
void dfs(int d,int cur){
	if(d==tree[0][0]+1){
		ans=ans>cur?ans:cur;
		return ;
	}
	if(cur+pre[tree[0][0]]-pre[d-1]<ans)return ;
	for(int i=1;i<=tree[d][0];i++){
		if(!mk[tree[d][i]]){
			del(tree[d][i],f[tree[d][i]]);
			dfs(d+1,cur+size[tree[d][i]]);
			redel(tree[d][i],f[tree[d][i]]);
		}
		else ans=ans>cur?ans:cur;
	}
	return ;
}

int main(){
	scanf("%d%d",&n,&p);
	for(i=1;i<=p;i++){
		scanf("%d%d",&a,&b);
		cnt++;
		thenext[cnt]=h[a];h[a]=cnt;dsti[cnt]=b;
		cnt++;
		thenext[cnt]=h[b];h[b]=cnt;dsti[cnt]=a;
	}
	dfs1(1,0,1);
	for(i=1;i<=tree[0][0];i++){
		a=0;
		for(j=1;j<=tree[i][0];j++)a=a>size[tree[i][j]]?a:size[tree[i][j]];
		pre[i]=pre[i-1]+a;
	}
	dfs(2,0);
	printf("%d",size[1]-ans);
	return 0;
}

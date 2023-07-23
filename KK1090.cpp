#include<bits/stdc++.h>
using namespace std;
const int dreamerp=1000007;
int n,m,x,y,z,vis[20001],dis[20001],i,_,p,q,l,cnt[20001],k,t;
vector<int>v[20001],u[20001];
struct node{
	int x,y;
	node(int x0=0,int y0=0){x=x0;y=y0;}
	int operator <(node u)const{return y>u.y;}
};
priority_queue<node>pq;
int main(){
	freopen("count2.in","r",stdin);
	freopen("count2.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(y),v[y].push_back(x);
		u[x].push_back(z),u[y].push_back(z);
	}
	for(i=2;i<=n;i++)dis[i]=1e9;
	cnt[1]=1;pq.push(node(1,0));
	while(!pq.empty()){
		p=pq.top().x;q=pq.top().y;pq.pop();
		if(q>dis[p])continue;
		for(i=0;i<v[p].size();i++){
			k=v[p][i];t=u[p][i];
			if(dis[k]==q+t)cnt[k]=(cnt[k]+cnt[p])%dreamerp;
			if(dis[k]>q+t)dis[k]=q+t,cnt[k]=cnt[p],pq.push(node(k,q+t));
		}
	}
	for(i=1;i<=n;i++)printf("%d ",cnt[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


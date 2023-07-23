#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
#define pii pair<int,int>
#define ll long long
#define mid ((l+r)>>1)
#define il inline
#define fst first
#define scd second
#define reg register
int T,n,m;
const int N=101;
int num[N],a[N][N];
int appear[N][N][N];
int l[N],r[N],top[N][N],bot[N][N],dis[N][N];
int times(int time,int st,int ed,int k){
	return appear[time][k][ed]-appear[time][k][st-1];
}
pii pos[N][N];
signed main(){
	ios::sync_with_stdio(false);
	scanf("%d",&T);
	#define fin(ss) {puts(ss);goto end;}
	while(T--){
		memset(appear,0,sizeof(appear));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d",num+i);
			for(int j=1;j<=num[i];j++)scanf("%d",&a[i][j]),appear[i][a[i][j]][j]=1;
			for(int j=1;j<=num[i];j++){
				for(int k=1;k<=n;k++){
					appear[i][k][j]+=appear[i][k][j-1];
				}
			}
		}
		for(int i=1;i<=n;i++){
			l[i]=1,r[i]=m;
			while(l[i]<m&&!appear[l[i]][i][num[l[i]]])l[i]++;
			while(r[i]>1&&!appear[r[i]][i][num[r[i]]])r[i]--;
			for(int j=l[i]+1;j<r[i];j++)
				if(!appear[j][i][num[j]])
					fin("NO");
			for(int j=l[i];j<=r[i];j++){
				top[j][i]=1,bot[j][i]=num[j];
				while(top[j][i]<num[j]&&a[j][top[j][i]]!=i)top[j][i]++;
				while(bot[j][i]>1&&a[j][bot[j][i]]!=i)bot[j][i]--;
				dis[j][i]=bot[j][i]-top[j][i]-1;
			}
			for(int j=l[i]+1;j<r[i];j++){
				if(dis[j][i]&1)fin("NO");
			}
		}
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				if(k==i)continue;
				int st=l[i],ed=r[i];
				while(st<r[i]&&times(st,top[st][i],bot[st][i],k)==0)st++;
				while(ed>l[i]&&times(ed,top[ed][i],bot[ed][i],k)==0)ed--;
				for(int j=st+1;j<ed;j++){
					if(!times(j,top[j][i],bot[j][i],k))fin("NO");
				}
			}
			for(int j=l[i];j<=r[i];j++){
				for(int k=1;k<=n;k++){
					if(k==i)continue;
					if(times(j,top[j][i],bot[j][i],k)==1)fin("NO");
					if(times(j,top[j][i],bot[j][i],k)<2
					 &&times(j-1,top[j-1][i],bot[j-1][i],k)>0
				   	 &&times(j+1,top[j+1][i],bot[j+1][i],k)>0)
						fin("NO");
					if(times(j,top[j][i],bot[j][i],k)>0&&(l[k]<l[i]||r[k]>r[i])){
						fin("NO");
					}
				}
			}
			for(int j=l[i];j<=r[i];j++)pos[j][i]=make_pair(top[j][i],bot[j][i]);
		}
		for(int a=1;a<=n;a++){
			for(int b=a+1;b<=n;b++){
				bool ainb=0,bina=0,aupb=0,bupa=0;
				int x=0;
				for(int i=max(l[a],l[b]);i<=min(r[a],r[b]);i++){
					if(pos[i][a].scd>pos[i][b].fst)aupb=1;
					else if(pos[i][a].fst<pos[i][b].scd)bupa=1;
					else if(pos[i][a].fst>pos[i][b].fst&&pos[i][a].scd<pos[i][b].scd)ainb=1;
					else if(pos[i][a].fst<pos[i][b].fst&&pos[i][a].scd>pos[i][b].scd)bina=1;
					else fin("NO");
				}
				if(ainb)x++;
				if(bina)x++;
				if(aupb)x++;
				if(bupa)x++;
				if(max(l[a],l[b])<=min(r[a],r[b])&&x!=1){
					fin("NO");
				}
			}
		}
		fin("YES");
		end:;
	}
}

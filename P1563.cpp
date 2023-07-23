#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
int n,m,ans=1,s,a,out[MAXN];
char name[MAXN][75];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%s",&out[i],name[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&s);
		ans=(ans+(a^out[ans]?s:n-s))%n,ans=(!ans?n:ans);
	}
	printf("%s\n",name[ans]);
	return 0;
}

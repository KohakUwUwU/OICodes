#include<stdio.h>
int n,k,ans;
inline void dfs(int sum){
	if(sum<=k||(sum-k)&1){
		ans++;
		return;
	}
	dfs((sum+k)>>1);
	dfs((sum-k)>>1);
}
int main()
{
	scanf("%d%d",&n,&k);
	dfs(n);
	printf("%d\n",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int ans[53][2003],a[53],b[53];
char s[53];
signed main()
{
    int n=read(),sdt=read(),k=read(),Ans=7872754;
    memset(ans,0x3f,sizeof(ans));
    for(int i=1; i<=n; i++) a[i]=read(),b[i]=i;
    scanf("%s",s+1),sort(b+1,b+n+1);
    for(int i=1; i<=n; i++) 
	{
		for(int j=0,x=b[i]; j<=a[x]; j++) ans[x][j]=abs(x-sdt);
		for(int j=1,x=b[i]; j<=n; j++) 
		if(a[j]<a[x]&&s[j]!=s[x]) for(int dis=abs(x-j),g=k; g>=a[x]; g--) ans[x][g]=min(ans[x][g],ans[j][g-a[x]]+dis);
	}
    for(int i=1; i<=n; i++) Ans=min(Ans,ans[i][k]);
    if(Ans==7872754) Ans=-1;
    printf("%d\n",Ans);
    return 0;
}

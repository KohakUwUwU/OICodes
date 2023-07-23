#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<int,map<int,bool> >m;
int n,k,i,x,y,ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(;i<k;i++)
	{
		scanf("%d%d",&x,&y);m[x][y]=true;
		if(m[x+1][y])ans++;if(m[x-1][y])ans++;if(m[x][y+1])ans++;if(m[x][y-1])ans++;
	}
	printf("%d",ans);
}

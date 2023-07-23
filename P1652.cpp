#include<bits/stdc++.h>
using namespace std;
int x[60],y[60],r[60];//读入的三个数组
double dist(int x1,int y1,int x2,int y2){//求距离的函数
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));//公式
}
int main(){
	int n,x1,y1,x2,y2,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=n;i++) scanf("%d",&y[i]);
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	for(int i=1;i<=n;i++)//每个圆都搜一遍
		if((dist(x1,y1,x[i],y[i])<r[i])^(dist(x2,y2,x[i],y[i]))<r[i]) ans++;//如果两个点恰有一个在圆内，就累加上
	printf("%d",ans);
}

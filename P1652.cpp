#include<bits/stdc++.h>
using namespace std;
int x[60],y[60],r[60];//�������������
double dist(int x1,int y1,int x2,int y2){//�����ĺ���
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));//��ʽ
}
int main(){
	int n,x1,y1,x2,y2,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=n;i++) scanf("%d",&y[i]);
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	for(int i=1;i<=n;i++)//ÿ��Բ����һ��
		if((dist(x1,y1,x[i],y[i])<r[i])^(dist(x2,y2,x[i],y[i]))<r[i]) ans++;//���������ǡ��һ����Բ�ڣ����ۼ���
	printf("%d",ans);
}

#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10000000;//n�����ֵ
int a[MAXN];
int main(){
	int n,d,ans=0;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);//����
	for(int i=1;i<=n;i++){//����ÿֻ��ţ
		int k=upper_bound(a+i+1,a+n+1,a[i]+d)-a;//����
		ans+=(k-i-1);//��¼
	}
	printf("%d",ans);
	return 0;//��������
}

/* 
���֣�ֻ�����ھ����
��֣�d[i]=t[i]=t[i-1],  i=2,3,..n
��t[0]=-INF,d[i]=INF,ʹ�úϷ����i=1,2,..,n

ԭ����Լ�����⣬��d[1..n]������
min �ھӲ����������к�
s.t. ѡ����Ԫ�ظ���Ϊk

h(x)��ʾ ǿԼ�� Ϊxʱ�����Ž�
h(x)������������͹ 

�°���Լ�����⣬����ĳ��cpuʱ ��compensation per unit)
min �ھӲ����������к�-cpu*Ԫ�ظ��� 

�������ճ���/��λ����cpuԽ��������Ԫ�ظ���Խ�� 
�������ճ���/��λ����cpuԽС��������Ԫ�ظ���Խ�� 
cpu��Χ[0,Ԫ�ظ���]

����cpuʱ��Ӧ���Ż����⣺
ʹ �°���Լ������ ȡ���Ž�ʱ �ؼ����� >= k �� ��Сcpu 
���Ž���ͬʱ���ȶ�ѡԪ�� 
*/



//LizPlum
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
const int INF=114514114514;
struct Optimal
{
	int val,cnt;
};
int n,k,t[N],d[N];
Optimal f[N];
Optimal calc(int cpu)
{
	f[1]=f[0];
	for(int i=2;i<=n;i++)
	{
		if(d[i]+f[i-2].val-cpu<=f[i-1].val)f[i]=(Optimal){d[i]+f[i-2].val-cpu,f[i-2].cnt+1};
		else f[i]=f[i-1];
	}
	return f[n];
}
signed main()
{
	freopen("fighter.in","r",stdin);
	freopen("fighter.out","w",stdout);
	cin>>n>>k;
	t[0]=-INF;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		d[i]=t[i]-t[i-1];
	}
	int low=0;
	int high=1e9+9;
	int bstCPU=high;
	while(low<=high)
	{
		int mid=(low+high)/2;
		Optimal opt=calc(mid);
		if(opt.cnt>=k)bstCPU=mid,high=mid-1;
		else low=mid+1;
	}
	Optimal opt=calc(bstCPU);
	int ans=opt.val+k*bstCPU;
	cout<<ans;
	return 0;
}

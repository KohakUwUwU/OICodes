/* 
发现：只可能邻居配对
差分：d[i]=t[i]=t[i-1],  i=2,3,..n
另t[0]=-INF,d[i]=INF,使得合法编号i=1,2,..,n

原版有约束问题，对d[1..n]序列求
min 邻居不相连子序列和
s.t. 选出的元素个数为k

h(x)表示 强约束 为x时的最优解
h(x)单调递增，下凸 

新版无约束问题，给定某个cpu时 （compensation per unit)
min 邻居不相连子序列和-cpu*元素个数 

拉格朗日乘子/单位补偿cpu越大，子序列元素个数越多 
拉格朗日乘子/单位补偿cpu越小，子序列元素个数越少 
cpu范围[0,元素个数]

二分cpu时对应最优化问题：
使 新版无约束问题 取最优解时 关键数量 >= k 的 最小cpu 
最优解相同时优先多选元素 
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

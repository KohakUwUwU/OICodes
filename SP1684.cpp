#include<bits/stdc++.h>

using namespace std;

const int N=1e5+1,A=2e5+2; 

struct Que//记录询问
{
	int id;
	int l,r;
}que[N];
int n,q;
int a[N];

int len;//块长
int p[N];//记录每个位置在哪个块

int l,r;
int res;
int cnt1[A];
int cnt2[N]; 

int ans[N];//答案

bool cmp(Que x,Que y)//排序
{
	if(p[x.l]!=p[y.l])
		return p[x.l]<p[y.l];
	return x.r<y.r;
}

void add(int x)//add操作
{
	cnt2[cnt1[a[x]]]--;//先减去以前的
	cnt1[a[x]]++;//更新
	cnt2[cnt1[a[x]]]++;//更新
	res=max(res,cnt1[a[x]]);//更新
	return;
}

void del(int x)
{
	cnt2[cnt1[a[x]]]--;
	cnt1[a[x]]--;
	cnt2[cnt1[a[x]]]++;//同上
	if(cnt2[res]==0)//判断是否对答案有影响
		res--;
	return;
}

int main()
{
	len=350;
	while(true)//多组数据
	{
		scanf("%d",&n);//读入
		if(!n)
			break;
		scanf("%d",&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]+=N;//整体右移
			p[i]=(i-1)/len+1;//分配块
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&que[i].l,&que[i].r);
			que[i].id=i;//读入询问
		}
		sort(que+1,que+1+q,cmp);//排序
		l=0,r=0;//一堆初始化
		res=0;
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));

		for(int i=1;i<=q;i++)//主要部分
		{
			while(que[i].l<l)
				add(--l);
			while(que[i].r>r)
				add(++r);
			while(que[i].l>l)
				del(l++);
			while(que[i].r<r)
				del(r--);
			ans[que[i].id]=res;//记录答案
		}
		
		for(int i=1;i<=q;i++)//输出
			printf("%d\n",ans[i]);
	}
	return 0;
} 

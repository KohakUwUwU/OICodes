#include<bits/stdc++.h>

using namespace std;

const int N=1e5+1,A=2e5+2; 

struct Que//��¼ѯ��
{
	int id;
	int l,r;
}que[N];
int n,q;
int a[N];

int len;//�鳤
int p[N];//��¼ÿ��λ�����ĸ���

int l,r;
int res;
int cnt1[A];
int cnt2[N]; 

int ans[N];//��

bool cmp(Que x,Que y)//����
{
	if(p[x.l]!=p[y.l])
		return p[x.l]<p[y.l];
	return x.r<y.r;
}

void add(int x)//add����
{
	cnt2[cnt1[a[x]]]--;//�ȼ�ȥ��ǰ��
	cnt1[a[x]]++;//����
	cnt2[cnt1[a[x]]]++;//����
	res=max(res,cnt1[a[x]]);//����
	return;
}

void del(int x)
{
	cnt2[cnt1[a[x]]]--;
	cnt1[a[x]]--;
	cnt2[cnt1[a[x]]]++;//ͬ��
	if(cnt2[res]==0)//�ж��Ƿ�Դ���Ӱ��
		res--;
	return;
}

int main()
{
	len=350;
	while(true)//��������
	{
		scanf("%d",&n);//����
		if(!n)
			break;
		scanf("%d",&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]+=N;//��������
			p[i]=(i-1)/len+1;//�����
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&que[i].l,&que[i].r);
			que[i].id=i;//����ѯ��
		}
		sort(que+1,que+1+q,cmp);//����
		l=0,r=0;//һ�ѳ�ʼ��
		res=0;
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));

		for(int i=1;i<=q;i++)//��Ҫ����
		{
			while(que[i].l<l)
				add(--l);
			while(que[i].r>r)
				add(++r);
			while(que[i].l>l)
				del(l++);
			while(que[i].r<r)
				del(r--);
			ans[que[i].id]=res;//��¼��
		}
		
		for(int i=1;i<=q;i++)//���
			printf("%d\n",ans[i]);
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define maxn 1000119
int num[maxn],tree[maxn],booll[maxn],nnn[maxn],N,ww;;
//num���鱣��ԭ���У�tree��״���飬nnn������
struct tt
{
    int l,r;//���ұ߽�
    int pos;//ԭλ�ã���Ϊ����Ҫ�����������
};
tt ask[maxn];
inline bool cmp(tt x,tt y)
{ 
    return x.r<y.r;
    //���Ŵ󷨺ã�û��ʲô�ǿ��Ž������Ŷ
    //ʵ�ڲ��оͼ���һ��cmp
}
inline int lowbit(int n) 
{
    return n&(-n);
    //��״������Ĳ�����1
}
inline void add(int n,int now)
{
    while(n<=N)
    {
        tree[n]+=now;
        n+=lowbit(n);
    }
    //��״������Ĳ�����2-->���²���
}
inline int sum(int n)
{
    int ans=0;
    while(n!=0)
    {
        ans+=tree[n];
        n-=lowbit(n);
    }
    return ans;
    //��״������Ĳ�����3������>��ѯ����
}
int main()
{
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
            scanf("%d",&num[i]);
        scanf("%d",&ww);
        for(int i=1;i<=ww;i++)
        {
            scanf("%d%d",&ask[i].l,&ask[i].r);
            ask[i].pos=i; //�洢��ʼλ��
        }
        sort(ask+1,ask+1+ww,cmp);//��r����
        int next=1;
        for(int i=1;i<=ww;i++)
        {
            for(int j=next;j<=ask[i].r;j++)
            {
                if(booll[num[j]]) 
                    add(booll[num[j]],-1);
                 //֮ǰ�����ǣ���֮ǰ��λ�ü���-1����֤���ظ�
                add(j,1);
                booll[num[j]]=j;
            }
            next=ask[i].r+1;
            //������һ�β�ѯ��λ��
            nnn[ask[i].pos]=sum(ask[i].r)-sum(ask[i].l-1);
            //��ѯ�ʱ�Ŵ洢ÿ��ѯ�ʵĽ��
        }
    for(int i=1;i<=ww;i++)
      cout<<nnn[i]<<endl;
    return  0;
}

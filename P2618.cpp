#include<iostream>
#include<cstring>
using namespace std;
int n,head=0,tail=1,q[100001];
int factor[100001];
bool Prime(int b)
{
	for(int i=2;i*i<=b;i++)if(b%i==0)return false;
	return true;
}
void getPrime(int dd)
{
	memset(factor,0,sizeof(factor));
	int k=dd;
	while(k!=1)
	{
		for(int i=2;i*i<=k;i++)
		{
			if(Prime(i)&&k%i==0&&i!=factor[factor[0]-1])
			{
				factor[++factor[0]]=i;
				k/=i;
				break;
			}
		}
		if(Prime(k))
		{
			factor[++factor[0]]=k;
			break;
		}
	}
}
int main()
{
	while(1)
	{
		cin>>n;
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		head=0;tail=1;
		memset(q,0,sizeof(q));
		memset(factor,0,sizeof(factor));
		q[head]=n;
		int time=0;
		getPrime(q[head]);
		while(head<tail)
		{
			//减去1
			time++;
			q[tail]=q[head]-1;
			if(q[tail]==1)
			{
				cout<<time<<endl;
				break;
			}
			tail++;
			//除以它的任意一个素因子
			int tmp=0; 
//			for(int i=time;i<=factor[0];i++)
//			{
//				q[tail]=q[head]/factor[i];
//				if(q[tail]==1)
//				{
//					tmp=1;
//					break;
//				}
//				tail++;
//			}
			q[tail]=q[head]/factor[time];
			if(q[tail]==1)
			{
				cout<<time<<endl;
				break;
			}
			tail++;
			head++;
		}
	}
}

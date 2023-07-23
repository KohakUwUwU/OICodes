#include<iostream>
#include<cstring>
using namespace std;
int factor[10001];
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
	int n;
	cin>>n;
	getPrime(n);
	for(int i=1;i<=factor[0];i++)cout<<factor[i]<<" ";
}

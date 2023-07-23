#include<iostream>
#define N 10005
using namespace std;
int l,m;
int lb,rb,sum;
bool trees[N];
int main()
{
	cin>>l>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>lb>>rb;
		for(int j=lb;j<=rb;j++)trees[j]=true;
	}
	for(int i=0;i<=l;i++)if(trees[i]==false)sum++;
	cout<<sum;
}

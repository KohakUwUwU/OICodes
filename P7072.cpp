#include<iostream>
#include<cstdio>
#define N 100005
#define R register
using namespace std;
int n;
double m;
int arr[N];
int main()
{
	cin>>n>>m;
	for(R int i=1;i<=n;i++)
	{
		int cc;
		scanf("%d",&cc);
		int j=1;
		while(arr[j]>cc)j++;
		for(R int k=i;k>=j;k--)arr[k+1]=arr[k];
		arr[j]=cc;
		cout<<arr[max(1,int(i*1.0*m*0.01))]<<" ";
	}
}

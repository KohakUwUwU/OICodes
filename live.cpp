#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100005
using namespace std;
int n,player;
int arr[N];
double w;
int main()
{
//	freopen("live.in","r",stdin);
//	freopen("live.out","w",stdout);
	scanf("%d%llf",&n,&w);
	w*=0.01;
	for(int i=1;i<=n;i++)
	{
		int in;
		scanf("%d",&in);
		int tmp=max(1,int(i*w));
//		cout<<tmp<<" ";
		int j=1;
		while(arr[j]>in)j++;
		for(int k=i;k>=j;k--)arr[k+1]=arr[k];
		arr[j]=in;
//		sort(arr+1,arr+1+i,greater<int>() );
		cout<<arr[tmp]<<" ";
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

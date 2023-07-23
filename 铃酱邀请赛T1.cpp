#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,cnt,gg,mm;
int arr[1001];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		for(gg=1;gg<=c;gg*=a)
		{
			for(mm=1;gg*mm<=c;gg*=b)
			{
				cout<<"%";
				arr[++cnt]=gg*mm;
			}
		}
		for(int i=1;i<=cnt;i++)printf("%d ",arr[i]);
		printf("\n");
		sort(arr+1,arr+1+cnt, greater<int>());
		for(int i=1;i<=cnt;i++)printf("%d ",arr[i]);
		//init
		memset(arr,0,sizeof(arr));
	}
}

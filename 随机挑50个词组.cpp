#include<bits/stdc++.h>
using namespace std;
int arr[342];
int main()
{
	srand((int)time(0));
	for(int i=0;i<50;i++)
	{
		int m=rand()%341;
		if(arr[m]==1)i--;
		else arr[m]=1;
	}
	for(int i=1;i<=341;i++)if(arr[i]==1)cout<<i<<" ";
}

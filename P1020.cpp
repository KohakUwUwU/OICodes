#include<bits/stdc++.h>
using namespace std;
int Data[100001],div1[100001],div2[100001],n=0;
int main()
{
	while(cin>>Data[++n]);
	n--;
	register int l1=1,l2=1;
	div1[1]=div2[1]=Data[1];
	for(register int i=2;i<=n;i++)
	{
		if(div1[l1]>=Data[i])div1[++l1]=Data[i];
		else div1[upper_bound(div1+1,div1+l1+1,Data[i],greater<int>())-div1]=Data[i];
		if(div2[l2]< Data[i])div2[++l2]=Data[i];
		else div2[lower_bound(div2+1,div2+l2+1,Data[i]               )-div2]=Data[i];
	}
	cout<<l1<<endl<<l2;
}

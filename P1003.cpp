#include<iostream>
using namespace std;
int n;
struct input
{
	int a,b,c,d;
}Data[10001];
int output1,output2;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>Data[i].a>>Data[i].b>>Data[i].c>>Data[i].d;
	cin>>output1>>output2;
	for(int i=n;i>=1;i--)if(Data[i].a<=output1&&Data[i].a+Data[i].c>=output1&&Data[i].b<=output2&&Data[i].b+Data[i].d>=output2){
		cout<<i;
		return 0;
	}
}

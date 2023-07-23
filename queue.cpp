#include<iostream>
using namespace std;
int input1,input2,front=0,rear=0,queue[100001];
int main()
{
	while(1)
	{
		cin>>input1>>input2;
		if(input1==1)queue[rear++]=input2;
		else cout<<queue[front++];
	}
}

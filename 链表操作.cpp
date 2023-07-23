#include<iostream>
#include<queue>
using namespace std;
struct list
{
	list* p;
	int value;
	list()
	{
		p=NULL;
		value=0;
	}
}arr1,arr2;
priority_queue<int,vector<int>,greater<int> >pq;
int main()
{
	int in1,in2,in3;
	while(cin>>in1>>in2)
	{
		if(in1==0&&in2==0)return 0;
		list* pointer=&arr1;
		for(int i=1;i<=in1;i++)
		{
			cin>>in3;
			pointer->p=new list;
			pointer=pointer->p;
			pointer->value=in3;
		}
		list* pointer1=&arr2;
		for(int i=1;i<=in2;i++)
		{
			cin>>in3;
			pointer1->p=new list;
			pointer1=pointer1->p;
			pointer1->value=in3;
		}
		pointer=&arr1;
		pointer1=&arr2;
		for(int i=1;i<=in1;i++)
		{
			pointer=pointer->p;
			pq.push(pointer->value);
		}
		for(int i=1;i<=in2;i++)
		{
			pointer1=pointer1->p;
			pq.push(pointer1->value);
		}
		int lastnum=-0x3f3f3f3f;
		while(!pq.empty())
		{
			if(lastnum!=pq.top())cout<<pq.top()<<" ",lastnum=pq.top();
			pq.pop();
		}
		cout<<endl; 
	}
}

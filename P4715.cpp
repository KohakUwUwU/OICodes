#include<iostream>
using namespace std;
int n,p;
struct node{
	int value;
	int pos;
}q[1<<9];
inline void search(int le)
{
	for(int i=0;i<le>>1;i++)swap(q[i],q[i*2].value>q[i*2+1].value?q[i*2]:q[i*2+1]);
	if(le!=2)search(le>>1);
}
int main()
{
	cin>>n;
	p=1<<n;
	for(int i=0;i<p;i++)
	{
		cin>>q[i].value;
		q[i].pos=i+1;
	}
	search(p);
	cout<<(q[0].value<q[1].value?q[0].pos:q[1].pos);
}

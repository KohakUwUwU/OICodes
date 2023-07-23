#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
queue<int>c;
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		q.push(tmp);
	}
	int tmp=-0x3f3f3f3f,cnt=0;
	while(!q.empty())
	{
		if(tmp!=q.top())c.push(q.top()),++cnt;
		tmp=q.top();
		q.pop();
	}
	cout<<cnt<<endl;
	while(!c.empty())
	{
		cout<<c.front()<<" ";
		c.pop();
	}
}

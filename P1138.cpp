#include<iostream>
#include<queue>
using namespace std;
int n,k;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		q.push(tmp);
	}
	int cnt=0,cur=-1;
	while(!q.empty())
	{
		if(cur!=q.top())cnt++;
		cur=q.top();
		if(cnt==k)
		{
			cout<<q.top();
			return 0;
		}
		q.pop();
	}
	cout<<"NO RESULT";
}

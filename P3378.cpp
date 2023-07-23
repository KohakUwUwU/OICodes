#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >stack;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		register int in;
		cin>>in;
		if(in==1){
			register int a;
			cin>>a;
			stack.push(a);
		}
		else if(in==2)cout<<stack.top()<<endl;
		else stack.pop();
	}
}

#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int main()
{
	register int tmp;
	while(cin>>tmp)
	{
		if(tmp==0)
		{
			while(!s.empty())
			{
				cout<<s.top()<<" ";
				s.pop();
			}
			return 0;
		}
		s.push(tmp);
	}
}

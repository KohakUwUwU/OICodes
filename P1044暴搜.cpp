#include<bits/stdc++.h>
using namespace std;
short n;
inline int f(short push,short pop)
{
//	cout<<push<<" "<<pop<<endl;
	if(push==0)return 1;
	if(push>pop)return 0;
	return f(push-1,pop)+f(push,pop-1);
}
int main()
{
	scanf("%hd",&n);
	cout<<f(n,n);
}//TLE最后一个点 

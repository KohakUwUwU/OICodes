#include<iostream>
using namespace std;
inline char output(char a)
{
	if(a>='0'&&a<=6)return a-'0'+'A';
	else if(a>='A'&&a<='F') return 15-(a-'A'+10)+'0';
	else return '0'+15-(a-'0');
}
int main()
{
	char i;
	cin>>i;
	cout<<output(i);
}

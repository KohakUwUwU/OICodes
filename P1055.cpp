#include<iostream>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int tmp=-45*'0'+str[0]+str[2]*2+str[3]*3+str[4]*4+str[6]*5+str[7]*6+str[8]*7+str[9]*8+str[10]*9;
	if(tmp%11==str[12]-'0'||str[12]=='X'&&tmp%11==10)cout<<"Right";
	else
	{
		for(int i=0;i<12;i++)cout<<str[i];
		if(tmp%11==10)cout<<'X';
		else cout<<tmp%11;
	}
}

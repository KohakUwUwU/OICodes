#include<iostream>
using namespace std;
int main()
{
	int bgx=0,bgxhour=-1;
	for(int i=1;i<=7;i++)
	{
		int in1,in2;
		cin>>in1>>in2;
		if(in1+in2>8&&bgxhour<in1+in2)bgx=i,bgxhour=in1+in2;
	}
	cout<<bgx;
}

#include<iostream>
using namespace std;
inline char output(char a)
{
	if(a=='0')return 'F';
	if(a=='1')return 'E';
	if(a=='2')return 'D';
	if(a=='3')return 'C';
	if(a=='4')return 'B';
	if(a=='5')return 'A';
	if(a=='A')return '5';
	if(a=='B')return '4';
	if(a=='C')return '3';
	if(a=='D')return '2';
	if(a=='E')return '1';
	else return '0'+15-a+'0';
}
int main()
{
//	cout<<output('A'); 
	char a,b,c,d,e,f,g;
	string arr;
	cin>>arr;
	a=arr[0];b=arr[1];c=arr[2];d=arr[3];e=arr[4];f=arr[5];g=arr[6];
	cout<<'#'<<output(b)<<output(c)<<output(d)<<output(e)<<output(f)<<output(g);
}

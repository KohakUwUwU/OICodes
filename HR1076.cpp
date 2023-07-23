#include<iostream>
using namespace std;
int main()
{
	string a;
	getline(cin,a);
	int c=0,s=0,n=0,o=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z')c++;
		else if(a[i]==' ')s++;
		else if(a[i]>='0'&&a[i]<='9')n++;
		else o++;
	}
	cout<<"characters="<<c<<"\nspaces="<<s<<"\nnumbers="<<n<<"\nothers="<<o;
}

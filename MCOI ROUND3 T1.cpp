#include<iostream>
using namespace std;
int main()
{
	long long n,a,b,c,d,f;
	cin>>n;
	while(n--)
	{
		f=0;
		cin>>a>>b>>c>>d;
		if(a==b&&c==d)f++;if(a==c&&b==d)f++;if(a==d&&b==c)f++;
		switch(f)
		{
			case 3:
				cout<<1<<endl;
				break;
			case 1:
				cout<<4<<endl;
				break;
			case 0:
				if(a+b==c+d||a+c==b+d||a+d==b+c)cout<<8<<endl;
				else cout<<0<<endl;
				break;
		}
	}
}

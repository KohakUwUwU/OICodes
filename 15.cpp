#include<iostream>
#include<queue>
using namespace std;
queue <int> subway;
int main()
{
	int n,a,b,c,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		if(a==0)
		{
			sum+=b;
			subway.push(c);
		}
		else{
				while(subway.front()<subway.back())
				{
					if(b-subway.front()<45){
						goto : flag;
					}
				}
			}
			flag:
	}
	cout<<sum;
}

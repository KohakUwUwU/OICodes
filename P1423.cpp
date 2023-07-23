#include<iostream>
using namespace std;
int main()
{
	double len=2,distance;
	int step=0;
	cin>>distance;
	while(distance>0)
	{
		step++;
		distance-=len;
		len*=0.98;
	}
	cout<<step;
}

#include<stdio.h>
//#include<iostream>
//using namespace std;
int main()
{
	double sum=1;
	for(int i=3;i<=100;i+=2)
	{
		double tmp=1/(i*1.0)*(i%4==3?-1:1);
//		cout<<tmp<<" "<<sum*4.0<<endl;
		if(tmp<0.000001&&tmp>-0.000001)
		{
			break;
		}
		sum+=tmp;
	}
	printf("%.8lf",sum*4.0);
}

#include<iostream>
using namespace std;
int main()
{
	int j,k,a[10]={};
	for(int i=192;i<=327;i++)
	{
		calc:
		for(int m=0;m<=9;m++)a[m]=0;
		j=2*i;k=3*i;
		a[i/100]++;a[i/10%10]++;a[i%10]++;
		a[j/100]++;a[j/10%10]++;a[j%10]++;
		a[k/100]++;a[k/10%10]++;a[k%10]++;
		if(a[0]!=0)
		{
			i++;
			goto calc;
		}
		for(int m=1;m<=9;m++)if(a[m]!=1){
			i++;
			goto calc;
		}
		cout<<i<<" "<<j<<" "<<k<<endl;
	}
}

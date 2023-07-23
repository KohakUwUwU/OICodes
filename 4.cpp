#include<iostream>
using namespace std;
int a[101],b[101],a1[101],b1[101];
int main()
{
	int n,na,nb,suma=0,sumb=0;
	cin>>n>>na>>nb;
	for(int i=0;i<na;i++)cin>>a1[i];
	for(int i=0;i<nb;i++)cin>>b1[i];
	int i=0,j=0,k=0;
	while(i<n)
	{
		a[i]=a1[j];
		b[i]=b1[k];
		j++;
		j=j%na;
		k++;
		k%=nb;
		i++;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==0&&b[i]==2||a[i]==2&&b[i]==5||a[i]==5&&b[i]==0)suma++;
		if(b[i]==0&&a[i]==2||b[i]==2&&a[i]==5||b[i]==5&&a[i]==0)sumb++;
	}
	if(suma>sumb)cout<<"A";
	else if(suma<sumb)cout<<"B";
	else cout<<"draw";
}

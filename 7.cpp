#include<iostream>
using namespace std;
int a[101],b[101];
int main()
{
	int n,time=0;
	cin>>n;
	for(int i=1;i<=2*n;i++)a[i]=i;
	while(1)
	{
		for(int i=1;i<=n;i++){
			b[i*2-1]=a[n+i];
			b[i*2]=a[i];
		}
		int tmp=0;
		for(int i=1;i<=2*n;i++)if(b[i]!=i){
			tmp++;
			break;
		}
		time++;
		if(tmp==0){
			cout<<time<<endl;
			for(int i=1;i<=2*n;i++)cout<<i<<" ";
			return 0;
		}
		for(int i=1;i<=2*n;i++)a[i]=b[i];
	}
}

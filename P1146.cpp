#include<iostream>
using namespace std;
int n;
int main(){
	cin>>n;
	cout<<n<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++) putchar(48|~i&1);
		for (int j=i+1;j<=n;j++) putchar(48|i&1);
		putchar(10);
	}
}

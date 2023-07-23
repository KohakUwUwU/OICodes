#include<iostream>
using namespace std;
int a,b,c;
int main()
{
    cin>>a>>b>>c;
    a=b-a;
    b=b-a;
    a=b+a;
    c=b;
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}

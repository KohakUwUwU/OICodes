#include<iostream>
using namespace std;
int main()
{
	for(int i=1;i<=7;i++)
        {
            for (int j = 1; j <= 7 - i; j++) cout<<" ";
            for (int j = i; j >= 1; j--) cout<<j;
            for (int j = 2; j <= i; j++) cout<<j;
            cout<<endl;
        }
}

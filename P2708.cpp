#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    string s;int n=0;
    cin>>s;
    for(int i=s.length()-1;i>=0;i--)//����ö��
    {
        if(n%2==0)//�жϵ�ǰ�ǳ�����һ��
        {
            if(s[i]=='0')++n;
        }
        else
        {
            if(s[i]=='1')++n;
        }
    }
    cout<<n;
}

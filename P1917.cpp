#include<iostream>
using namespace std;
char ma[4][4];
int mx[4]={1,2,2,3};
int my[4]={2,1,3,2};
int ans=0;
int main()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>ma[i][j];
            if(ma[i][j]!='-') ans++;
        }
    }
    if(ma[1][2]!='-'&&ma[3][2]!='-')//�������˵������
    {
        cout<<"Dont know."<<endl<<3;
        return 0;
    }
    if(ma[2][1]!='-'&&ma[2][3]!='-')//��Ҳ����˵������
    {
        cout<<"Dont know."<<endl<<3;
        return 0;
    }
    bool pd=0;
    for(int i=0;i<4;i++)//������д���鷳��һ�㣬������Բο�¥�´���
    {
        if(ma[mx[i]][my[i]]=='X') pd=1;
    }
    if(pd==1)
    {
        cout<<"xiaoa will win.";
    }
    else
    {
        cout<<"Dont know.";
    }
    cout<<endl<<ans;
    return 0;
}

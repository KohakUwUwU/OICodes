#include<bits/stdc++.h>
using namespace std;
int n;
string ch;
string str[1000001],output[1000001];//str ���� output �洢��chΪǰ׺���ַ��� 
int cnt=0;//output��flag 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>str[i];
	cin>>ch;
	for(int i=1;i<=n;i++)if(str[i].find(ch)==0)output[++cnt]=str[i];//find�����������Ļ����аٶ�qwq�˴����ٽ������� 
	sort(output+1,output+1+cnt);
	for(int i=1;i<=cnt;i++)cout<<output[i]<<endl;
}

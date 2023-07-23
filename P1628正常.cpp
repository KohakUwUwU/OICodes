#include<bits/stdc++.h>
using namespace std;
int n;
string ch;
string str[1000001],output[1000001];//str 输入 output 存储以ch为前缀的字符串 
int cnt=0;//output的flag 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>str[i];
	cin>>ch;
	for(int i=1;i<=n;i++)if(str[i].find(ch)==0)output[++cnt]=str[i];//find函数如果不会的话自行百度qwq此处不再解释啦！ 
	sort(output+1,output+1+cnt);
	for(int i=1;i<=cnt;i++)cout<<output[i]<<endl;
}

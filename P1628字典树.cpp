#include<iostream>
#include<cstring>
#include<map>
using namespace std;
int n;
string str;
struct node
{
	int value;
	node* pointer[26];
	int end;
	node()
	{
		value=0;
		memset(pointer,int(NULL),sizeof(pointer));
		//NULL在内存初始化的时候要转为int qwq
		end=false;
	}
};
map <int,node> Data;
int flag=0;
void search(node* f,string op)
{
	if(f->end>0)
	{
		for(int i=1;i<=f->end;i++)cout<<op<<endl;
	}
	for(int i=0;i<26;i++)
	{
		if(f->pointer[i]!=NULL)
		{
			search(f->pointer[i],op+char(i+'a'));	
		}
	}
}
int main()
{
	Data[0].value=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string tmp;
		cin>>tmp;
		node* tail=&Data[0];//head的指针 
		int len=tmp.length();
		for(int j=0;j<len;j++)
		{
			if(tail->pointer[tmp[j]-'a']==NULL)
			{
				Data[++flag].value=tmp[j]-'a';
				tail->pointer[tmp[j]-'a']=&Data[flag];
			}
			tail=tail->pointer[tmp[j]-'a'];
			if(j==len-1)tail->end++;
		}
	}
	cin>>str;
	node* findRoot=&Data[0];
	int strl=str.length();
	for(int i=0;i<strl;i++)
	{
		findRoot=findRoot->pointer[str[i]-'a'];
	}
	search(findRoot,str);
}

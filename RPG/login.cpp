#include<iostream>
#include<conio.h>
using namespace std;
char usn[32],password[32];
void LoginLobby()
{
	cout<<"Input your username:";
	cin>>usn;
	int i=0;
	while(true)
	{
		password[i]=getch();
		if(password[i++]=='\n')break;
		cout<<"*";
	}
}

#include <bits/stdc++.h>
using namespace std;
char text[16],result[5][62];
int main(){
	cin>>text;
	result[0][0]='.';result[1][0]='.';result[2][0]='#';result[3][0]='.';result[4][0]='.';
	for(int i=0;i<strlen(text);i++){
		char x=text[i];
		int xPos=4*i+2;
		result[0][xPos-1]='.';	result[0][xPos]='#';	result[0][xPos+1]='.';	result[0][xPos+2]='.';
		result[1][xPos-1]='#';	result[1][xPos]='.';	result[1][xPos+1]='#';	result[1][xPos+2]='.';
		result[2][xPos-1]='.';	result[2][xPos]=x;		result[2][xPos+1]='.';	result[2][xPos+2]='#';
		result[3][xPos-1]='#';	result[3][xPos]='.';	result[3][xPos+1]='#';	result[3][xPos+2]='.';
		result[4][xPos-1]='.';	result[4][xPos]='#';	result[4][xPos+1]='.';	result[4][xPos+2]='.';
	}
	for(int i=2;i<strlen(text);i+=3){
		char x=text[i];
		int xPos=4*i+2;
		result[0][xPos-2]='.';	result[0][xPos-1]='.';	result[0][xPos]='*';	result[0][xPos+1]='.';	result[0][xPos+2]='.';
		result[1][xPos-2]='.';	result[1][xPos-1]='*';	result[1][xPos]='.';	result[1][xPos+1]='*';	result[1][xPos+2]='.';
		result[2][xPos-2]='*';	result[2][xPos-1]='.';	result[2][xPos]=x;		result[2][xPos+1]='.';	result[2][xPos+2]='*';
		result[3][xPos-2]='.';	result[3][xPos-1]='*';	result[3][xPos]='.';	result[3][xPos+1]='*';	result[3][xPos+2]='.';
		result[4][xPos-2]='.';	result[4][xPos-1]='.';	result[4][xPos]='*';	result[4][xPos+1]='.';	result[4][xPos+2]='.';
	}
	for(int i=0;i<5;i++)
		cout<<result[i]<<endl;
}

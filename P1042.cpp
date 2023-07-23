#include<bits/stdc++.h>
using namespace std;
char ch,s[62510];
int a,b,emm;
int main(){
	while(cin>>ch){
		if(ch=='E')break;
		else s[++emm]=ch;
	}
	for(int i=1;i<=emm;i++){
		if(s[i]=='W')a++;
		else if(s[i]=='L')b++;
		if(a==11&&a>b&&a-b>=2||b==11&&b>a&&b-a>=2){
			cout<<a<<":"<<b<<'\n';
			a=0;
			b=0;
		}
		else if(a>=11&&a>b&&a-b>=2||b>=11&&b>a&&b-a>=2){
			cout<<a<<":"<<b<<'\n';
			a=0;
			b=0;
		}
	}
	cout<<a<<":"<<b<<'\n'<<'\n';
	a=0;
	b=0;
	for(int i=1;i<=emm;i++){
		if(s[i]=='W')a++;
		else if(s[i]=='L')b++;
		if(a==21&&a>b&&a-b>=2||b==21&&b>a&&b-a>2){
			cout<<a<<":"<<b<<'\n';
			a=0;
			b=0;
		}
		else if(a>=21&&a>b&&a-b>=2||b>=21&&b>a&&b-a>=2){
			cout<<a<<":"<<b<<'\n';
			a=0;
			b=0;
		}
	}
	cout<<a<<":"<<b<<'\n';
	return 0;
} 

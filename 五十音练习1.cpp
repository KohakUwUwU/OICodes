//LizPlum
#include<bits/stdc++.h>
#include "sys/timeb.h"
#define int long long
using namespace std;

string ping[51]={" ","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"};
string pian[51]={" ","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��"};
string engl[51]={" ","a","i","u","e","o","ka","ki","ku","ke","ko","sa","shi","su","se","so","ta","chi","tsu","te","to","na","ni","nu","ne","no","ha","hi","fu","he","ho","ma","mi","mu","me","mo","ya","yu","yo","ra","ri","ru","re","ro","wa","wo","nn"};
inline void run()
{
	clock_t start,end;
	start = clock();
	srand(time(NULL));
	struct timeb timeSeed;
	ftime(&timeSeed);
	srand(timeSeed.time * 1000 + timeSeed.millitm);  // milli time
    const int MAX = 46;
    const int MIN = 1;
    const int max1 = 2;
    const int min1 = 1;
 	int True=0;
	for(int i=1;i<=100;i++)
	{
		srand(time(NULL));
		struct timeb timeSeed;
		ftime(&timeSeed);
		srand(timeSeed.time * 1000 + timeSeed.millitm);
   		int word = rand() % (MAX - MIN + 1) + MIN;
   		int pp = rand() % (max1-min1+1)+min1;
   		string targ;
		if(pp==1)targ=ping[word];
   		else targ=pian[word];
   		cout<<targ<<' ';
   		string str;
   		cin>>str;
   		if(str==engl[word])cout<<"T\n",True++;
   		else cout<<"F "<<engl[word]<<'\n';
 	}
	end = clock();
 	cout<<"score:"<<True<<'\n';
 	cout<<"time:"<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
 	cout<<"Enter any letter to continue...\n";
}
signed main()
{
 	while(1)
 	{
 		run();	
	}
	return 0;
}


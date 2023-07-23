//TEmPTaTiON.
#include<bits/stdc++.h>
#define int long long
using namespace std;

string str="|董老师，虽然我们刚与您认识两|\n|个礼拜不到，但是您早已收获了|\n|我们每一位同学的喜爱。您的幽|\n|默和温柔，让信息课成了我们一|\n|个礼拜最快乐的两节课，更是我|\n|们最盼望的课程之一。我们坚信|\n|，茫茫人海，相逢便是缘，今年|\n|夏天，我们相遇在了控江，虽然|\n|我们的缘分可能只有一年，但是|\n|我们会珍惜与您在一起的每一分|\n|每一秒。最后，董老师，您笑起|\n|来真好看，提前祝教师节快乐！|\n";
signed main()
{
	for(int i=1;i<=30;i++)cout<<'-';
	cout<<'\n';
	for(int i=0;i<str.length();i++)
	{
		cout<<str[i];
		_sleep(20);
	}
	for(int i=1;i<=30;i++)cout<<'-';
	_sleep(1000);
	cout<<"\n                      by 黄子洋";
	while(1);
	return 0;
}


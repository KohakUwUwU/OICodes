#include<iostream>
using namespace std;
int n;
string mod[1000001],text;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>mod[i];
	cin>>text;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(mod[i]==text)
		{
			sum++;
			continue;
		}
		for(int j=0;j<text.length();j++)
		{
			if(mod[i][0]==text[j])
			{
				int k=0;
				while(mod[i][k++]==text[j++]);
				if(k==mod[i].length()+1)
				{
					sum++;
					break;
				}
			}
		}
	}
	cout<<sum;
}

//Don't Fight The Music
#include<bits/stdc++.h>
#define int long long
using namespace std;

class book
{
	private:
		int price,cnt;
	public:
		void getPrice();
		void getCnt();
		void cPrice(int p);
		void cCnt(int c);
		int money();
		book();
		~book();
};
void book::getPrice()
{
	cout<<price<<'\n';
}
void book::getCnt()
{
	cout<<cnt<<'\n';
}
void book::cPrice(int p)
{
	price=p;
}
void book::cCnt(int c)
{
	cnt=c;
}
int book::money()
{
	return price*cnt;
}
book::book()
{
	cout<<"Object is created.\n";
}
book::~book()
{
	cout<<"Object is deleted.\n";
}
signed main()
{
	book* a=new book;
	a->cCnt(2);
	a->cPrice(9);
	cout<<a->money();
	free(a);
	return 0;
}


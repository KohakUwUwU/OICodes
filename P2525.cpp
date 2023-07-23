#include<bits/stdc++.h>
using namespace std;

int n,m,f[11],a[11];
char ka[11];
vector<int>v;

inline int cantor()
{
	int ret=0,x;
	for(int i=0; i<n; ++i) {
		x=0;
		for(int j=i+1; j<n; ++j)
		if( (ka[i]-ka[j])>0 ) x++;
		ret+=x*f[n-i-1];
	}
	return ret;
}

inline void incantor(int k)
{
	int x;
	while( !v.empty() ) v.erase(v.end());
	for(int i=1; i<=n; ++i) v.push_back(i);
	for(int i=1; i<n; ++i) {
		a[i]=v[(x=k/f[n-i])];
		v.erase(v.begin()+x);
		k%=f[n-i];
	}
	a[n]=v[0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; ++i) cin>>ka[i];
	f[1]=1;
	for(int i=2; i<=10; ++i) f[i]=f[i-1]*i;
	incantor(cantor()-1);
	for(int i=1; i<=n; ++i) printf("%d ",a[i]);
	return 0;
}

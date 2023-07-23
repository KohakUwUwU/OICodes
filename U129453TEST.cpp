#include <bits/stdc++.h>
using namespace std;
long long k,n;
long long ans;
long long seat(long long x,long long y){
	if(y - x + 1 < 3 + 2 * k){
		return 0;
	}
	if((y - x + 1) % 2 != 0){
		return 2 * seat(x,(y + x) / 2) + 1;
	}
	else {
		return seat(x,(y + x) / 2) + seat((y + x) / 2,y) + 1;
	}
}
int main(){
	scanf("%lld%lld",&n,&k);
	ans = 1;
	ans += seat(1,n + 1);
	printf("%lld",ans);
	return 0;
}


//Lovelive
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

inline const LL Get_Int() {
	LL num=0,bj=1;
	char x=getchar();
	while(x<'0'||x>'9') {
		if(x=='-')bj=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9') {
		num=num*10+x-'0';
		x=getchar();
	}
	return num*bj;
}

LL max(LL a,LL b) {
	return a>b?a:b;
}

const int maxn=100005,maxq=600005;

struct Segment {
	LL k,b;
	Segment(LL _k=0,LL _b=0):k(_k),b(_b) {}
	LL f(LL x) {
		return k*x+b;
	}
} a[maxn],b[maxn];

LL t[maxq];
int n,m,q[maxq],last[maxn];

struct Tree {
	int left,right;
	Segment s;
	Tree(int l=0,int r=0):left(l),right(r),s(Segment()) {}
};

struct Segment_Tree {
	Tree tree[maxq*4];
#define ls index<<1
#define rs index<<1|1
	void build(int index,int Left,int Right) {
		tree[index]=Tree(Left,Right);
		if(Left==Right)return;
		int mid=(Left+Right)>>1;
		build(ls,Left,mid);
		build(rs,mid+1,Right);
	}
	void insert(int index,Segment s) {
		Segment &now=tree[index].s;
		if(now.k==0&&now.b==0)now=s;
		if(now.f(t[tree[index].left])<s.f(t[tree[index].left]))swap(now,s); //保证左端点较大
		if(tree[index].left==tree[index].right||now.k==s.k)return;
		int mid=(tree[index].left+tree[index].right)>>1;
		double x=(double)(now.b-s.b)/(s.k-now.k);
		if(x<t[tree[index].left]||x>t[tree[index].right])return;
		if(x<=t[mid])insert(ls,now),now=s;
		else insert(rs,s);
	}
	void insert(int index,int Left,int Right,Segment s) {
		if(Right<tree[index].left||Left>tree[index].right)return;
		if(Left<=tree[index].left&&Right>=tree[index].right) {
			insert(index,s);
			return;
		}
		insert(ls,Left,Right,s);
		insert(rs,Left,Right,s);
	}
	LL query(int index,int target) {
		if(target<tree[index].left||target>tree[index].right)return -LLONG_MAX;
		if(tree[index].left==tree[index].right)return tree[index].s.f(t[target]);
		return max(max(query(ls,target),query(rs,target)),tree[index].s.f(t[target]));
	}
} st;

int main() {
	freopen("remote.in","r",stdin);
	freopen("remote.out","w",stdout);
	n=Get_Int();
	m=Get_Int();
	for(int i=1; i<=n; i++) {
		a[i]=Segment(0,Get_Int());
		b[i]=Segment(0,-a[i].b);
	}
	st.build(1,0,m);
	for(int i=1; i<=m; i++) {
		t[i]=Get_Int();
		char opt=' ';
		while(!isalpha(opt))opt=getchar();
		if(opt=='q')q[i]=1;
		else {
			LL x=Get_Int(),y=Get_Int();
			st.insert(1,last[x],i,a[x]);
			st.insert(1,last[x],i,b[x]);
			last[x]=i;
			a[x]=Segment(y,a[x].k*t[i]+a[x].b-t[i]*y);
			b[x]=Segment(-a[x].k,-a[x].b);
		}
	}
	for(int i=1; i<=n; i++) {
		st.insert(1,last[i],m,a[i]);
		st.insert(1,last[i],m,b[i]);
	}
	for(int i=1; i<=m; i++)
		if(q[i])printf("%lld\n",st.query(1,i));
	return 0;
}

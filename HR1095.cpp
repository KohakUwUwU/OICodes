#include<stdio.h>
int a[11],n;
int binarysearch(int l,int r)
{
	if(l>r)return -1;
	int mid=(l+r)/2;
	if(a[mid]<n)binarysearch(mid+1,r);
	else if(a[mid]>n)binarysearch(l,mid-1);
	else return mid;
}
int main()
{
	for(int i=1;i<=10;i++)scanf("%d",&a[i]);
	scanf("%d",&n);
	int tmp=binarysearch(0,11);
	if(tmp==-1)printf("Not exist!");
	else printf("%d",tmp-1);
}

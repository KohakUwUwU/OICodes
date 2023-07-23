#include<stdio.h>
int main()
{
	char c;
	scanf("%c",&c);
	switch(c)
	{
		case 'A' : printf("85~100");break;
		case 'B' : printf("70~84");break;
		case 'C' : printf("60~69");break;
		case 'D' : printf("0~60");break;
	}
}

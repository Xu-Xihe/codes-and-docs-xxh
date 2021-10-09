#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	char a[1000000];
	int b[1],c=0,d;
	scanf("%[^\n]",a);
	while (true)
	{
		d = 97;
		while (true)
		{
			if (a[c] == d) b[d]++;
			d++;
			if (d>122)break;
		}
		c++;
		if (c>strlen(a))break;
	}
	d = 97;
	while (true)
	{
		if (b[d] == 1)break;
		d++;
		if(d>122)
		{
			cout<<"no";
			return 0;
			break;
		}
	}
	a[0]=d;
	printf("%c", a[0]);
	return 0;
	}

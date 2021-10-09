#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[256];
	int i=0,b=0;
	scanf("%[^\n]",a);
	while(true)
	{
		if(a[i]>=48&&a[i]<=57) b++;
		i++;
		if(i==strlen(a))break;
	}
	printf("%d",b);
	return 0;
}

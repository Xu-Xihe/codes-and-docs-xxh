#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[120],b[120];
	int c,d;
	scanf("%[^\n]",a);
	d=strlen(a);
	a[d]=a[0];
	while(true)
	{
		b[c]=a[c]+a[c+1];
		c++;
		if(c==d)break;
	}
	printf("%s",b);
	return 0;
}

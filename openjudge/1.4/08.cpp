#include<stdio.h>
using namespace std;
int main()
{
	int a,b;
	scanf("%d",&a);
	b=a%15;
	if(b==0) printf("YES");
	else printf("NO");
}

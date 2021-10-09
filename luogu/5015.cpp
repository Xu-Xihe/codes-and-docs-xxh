#include <stdio.h>
#include <string.h>
using namespace std;
char a[9];
int ax;
int main()
{
	scanf("%[^\n]", a);
	int len = strlen(a);
	while (len--)
	{
		if (a[len] == '\n' || a[len] == ' ')
			;
		else
			ax++;
	}
	printf("%d", ax);
	return 0;
}

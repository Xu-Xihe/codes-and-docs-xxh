#include <stdio.h>
#include <string.h>
using namespace std;
char in[260];
int a,b=0;
int main()
{
	scanf("%s",in);
	a=strlen(in);
	while(true){
		if(in[b]=='A')in[b]='T';
		else if(in[b]=='T')in[b]='A';
			else if(in[b]=='G')in[b]='C';
				else if(in[b]=='C')in[b]='G';
		b++;
		if(b==a)break;
	}
	printf("%s",in);
    return 0;
}

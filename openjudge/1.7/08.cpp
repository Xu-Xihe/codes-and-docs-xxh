#include<string.h>
#include<stdio.h>
using namespace std;
char i[35],inb,ina;
int len,d=0,a,b;
int main()
{
	scanf("%s %c %c",i,&ina,&inb);
	len=strlen(i);
	a=ina;
	b=inb;
	while(true){
		if(i[d]==a) i[d]=b;
		d++;
		if(d==len)break;
	}
	printf("%s",i);
	return 0;
}

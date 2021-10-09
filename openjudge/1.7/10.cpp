#include<stdio.h>
#include<string.h>
using namespace std;
char in[203];
int main(){
	scanf("%[^\n]",in);
	int len=strlen(in),a=0;
	while(true){
		if(in[a]>='A'&&in[a]<='Z'){
			if(in[a]=='A')in[a]='V';
			else if(in[a]=='B') in[a]='W';
				else if(in[a]=='C')in[a]='X';
					else if(in[a]=='D')in[a]='Y';
						else if(in[a]=='E')in[a]='Z';
							else in[a]=in[a]-5;
			a++;
		}
		else a++;
		if(a==len)break;
	}
	printf("%s",in);
	return 0; 
}

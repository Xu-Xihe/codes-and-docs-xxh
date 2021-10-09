#include<stdio.h>
using namespace std;
char in[1000][1000];
int i;
int main(){
	//freopen("out.txt","w",stdout);
	for(i=0;~scanf("%s",in[i]);i++);
	for(i-=1;i>0;i--)
		printf("%s ",in[i]);
	printf("%s",in[0]);
	return 0;
}

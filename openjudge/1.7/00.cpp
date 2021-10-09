#include<stdio.h>
using namespace std;
int main(){
	freopen("shuju.txt","w",stdout);
	char a='A';
	for(int i=0;i<26;i++)printf("%c",a+i);
	return 0;
}


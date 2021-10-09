#include<stdio.h>
#include<string.h>
using namespace std;
char in[1050],b[106],lin[1000];
int len;
bool huiwen(char a[105]){
	int len=strlen(a);
	for(int i=0;i<len;i++){
		b[len-1-i]=a[i];
	}
	if(strcmp(a,b)==0)return true;
	else return false;
}
int main(){
	scanf("%s",in);
	len=strlen(in);
	for(int i=2;i<=len;i++){
		for(int j=0;j<len;j++){
			int zhong=j+i;
			if(zhong>len)break;
			else{
				for(int g=j,z=0;g<zhong;g++){
					lin[z]=in[g];
					z++;
				}
				//printf("len=%d\n",strlen(lin));
				if(huiwen(lin))printf("%s\n",lin);
			}
		}
	}
}

#include<stdio.h>
using namespace std;
int len,in[1005],big=1;
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++)
		scanf("%d",&in[i]);
	in[len]=-1;
	for(int i=0;i<len;i++){
		int lin=in[i],a=0;
		for(int j=0;;j++){
			int nx=i+j;
			if(nx>=len){
				if(a>big)
					big=a;
				printf("%d",big);
				return 0;
			}
			if(in[nx]==lin)a++;
			else break;
		}
		if(a>big)
			big=a;
	}
	return 0;
}

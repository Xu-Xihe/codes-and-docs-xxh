#include<bits/stdc++.h>
using namespace std;
char in[1005][1005],out[1005][1005];
int len=0;
int main(){
	for(;~scanf("%s",in[len]);len++);
	for(int i=0;i<len;i++){
		for(int j=1;j<len;j++){
			if(strcmp(in[j-1],in[j])>0){
				char a[250];
				strcpy(a,in[j]);
				strcpy(in[j],in[j-1]);
				strcpy(in[j-1],a);
			}
		}
	}
	for(int i=0;i<len;i++){
		int z=0;
		for(int j=i-1;j>=0;j--){
			if(strcmp(in[i],in[j])==0)z=888;
		}
		if(z==0)printf("%s\n",in[i]);
	}
	return 0;
}

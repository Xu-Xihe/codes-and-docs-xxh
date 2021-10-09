#include<bits/stdc++.h>
using namespace std;
int len,in[200020];
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		scanf("%d",&in[i]);
	}
	sort(in,in+len);
	in[len]=-56;
	for(int i=0;i<len;){
		int out=0;
		for(int j=i;;j++){
			if(in[j]!=in[i])break;
			else out++;
		}
		printf("%d %d\n",in[i],out);
		i+=out;
	}
	return 0;
}

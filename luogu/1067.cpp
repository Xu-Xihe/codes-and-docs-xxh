#include<bits/stdc++.h>
using namespace std;
int len,in[105];
int main(){
	scanf("%d",&len);
	for(int i=0;i<=len;i++){
		scanf("%d",&in[i]);
	}
	if(in[0]<0)printf("-");
	if(abs(in[0])>1)printf("%d",abs(in[0]));
	if(in[0]!=0)printf("x^%d",len);
	for(int i=1;i<=len;i++){
		if(in[i]<0)printf("-");
		else if(in[i]>0)printf("+");
		if(abs(in[i])>1||(i==len&&in[i]!=0))printf("%d",abs(in[i]));
		if(in[i]!=0&&len-i==1)printf("x");
		else if(in[i]!=0&&len-i!=0)printf("x^%d",len-i);
	}
	return 0;
}

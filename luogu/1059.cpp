#include<bits/stdc++.h>
using namespace std;
int len,in[105],out=1;
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++)
		scanf("%d",&in[i]);
	sort(in,in+len);
	for(int i=1;i<len;i++){
		if(in[i]!=in[i-1])out++;
	}
	printf("%d\n%d ",out,in[0]);
	for(int i=1;i<len;i++){
		if(in[i]!=in[i-1])printf("%d ",in[i]);
	}
	return 0;
}

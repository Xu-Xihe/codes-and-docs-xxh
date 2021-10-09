#include<bits/stdc++.h>
using namespace std;
int len,in[100005];
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++)
		scanf("%d",&in[i]);
	sort(in,in+len);
	for(int i=0;i<len;i++)
		printf("%d\n",in[i]);
	return 0;
}

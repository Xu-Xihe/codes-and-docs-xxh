#include<bits/stdc++.h>
using namespace std;
int len,m,num[5005],fen[5005];
int main(){
	scanf("%d%d",&len,&m);
	for(int i=0;i<len;i++)
		scanf("%d%d",&num[i],&fen[i]);
	for(int lng=0;lng<len;lng++){
		for(int i=1;i<len;i++){
			if(fen[i-1]<fen[i]){
				int lin=fen[i];
				fen[i]=fen[i-1];
				fen[i-1]=lin;
				lin=num[i];
				num[i]=num[i-1];
				num[i-1]=lin;
			}
			if(fen[i-1]==fen[i]&&num[i-1]>num[i]){
				int lin=num[i];
				num[i]=num[i-1];
				num[i-1]=lin;
			}
		}
	}
	m*=1.5;
	int a=m-1;
	for(;a<len;a++){
		int aa=fen[m-1];
		if(fen[a]!=aa)break;
	}
	printf("%d %d\n",fen[m-1],a);
	for(int i=0;i<a;i++)
		printf("%d %d\n",num[i],fen[i]);
	return 0;
}

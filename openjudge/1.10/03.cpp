#include<bits/stdc++.h>
using namespace std;
int len,fen[21];
char ming[21][21];
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++)
		scanf("%s%d",ming[i],&fen[i]);
	for(int i=0;i<len;i++){
		for(int j=1;j<len;j++){
			if(fen[j-1]<fen[j]){
				int lin=fen[j];
				fen[j]=fen[j-1];
				fen[j-1]=lin;
				char a[25];
				strcpy(a,ming[j]);
				strcpy(ming[j],ming[j-1]);
				strcpy(ming[j-1],a);
			}
			if(fen[j-1]==fen[j]){
				if(strcmp(ming[j-1],ming[j])>0){
					char a[25];
					strcpy(a,ming[j]);
					strcpy(ming[j],ming[j-1]);
					strcpy(ming[j-1],a);
				}
			}
		}
	}
	for(int i=0;i<len;i++)
		printf("%s %d\n",ming[i],fen[i]);
	return 0;
}

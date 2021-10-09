#include<bits/stdc++.h>
#define maxe 250208
using namespace std;
int f[maxe];
char in[maxe];
void getf (char P[],int f[]){
  int m=strlen(P);
  f[0]=f[1]=0;
  for (int i=1;i<m;i++){
    int j=f[i];
    while (j&&P[i]!=P[j]) j=f[j];
    f[i+1] = P[i]==P [j] ? j+1:0;
  }
}
int main(){
	while(1){
		int len;
		scanf("%d",&len);
		if(len==0)return 0;
		
	}
}

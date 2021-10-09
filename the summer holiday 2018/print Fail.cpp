#include<bits/stdc++.h>
using namespace std;
char in[80293];
int out[85029];
void getFail (char P[],int f[]){
  int m=strlen(P);
  f[0]=f[1]=0;
  for (int i=1;i<m;i++){
    int j=f[i];
    while (j&&P[i]!=P[j]) j=f[j];
    f[i+1] = P[i]==P [j] ? j+1:0;
  }
}
int main(){
	scanf("%s",in);
	getFail(in,out);
	for(int i=0;i<strlen(in);i++){
		printf("%d ",out[i]);
	}
	return 0;
}

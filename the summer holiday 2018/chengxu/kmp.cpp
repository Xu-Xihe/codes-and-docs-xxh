#include<string.h>
#include<stdio.h>
using namespace std;
int in,Fail[1432545];
void getFail (char P[],int f[]){
  int m=strlen(P);
  f[0]=f[1]=0;
  for (int i=1;i<m;i++){
    int j=f[i];
    while (j&&P[i]!=P[j]) j=f[j];
    f[i+1] = P[i]==P [j] ? j+1:0;
  }
}
int find(char T[],char P[],int f[]) {
	memset(f,0,sizeof(f));
	int ans=0;
	int m=strlen(P);
	int n=strlen(T);
	getFail(P,f);
	int j=0;
	for (int i=0;i<n;i++){
		while (j&&P[j]!=T[i]) j=f[j]; 
		if (P[j]==T[i]) j++;
		if (j==m) ans++; 
	}
	return ans;
}
char a[1080008],b[1000928];
int main(){
	scanf("%d",&in);
	while(in--){
		scanf("%s%s",a,b);
		printf("%d\n",find(b,a,Fail));
	}
	return 0;
}

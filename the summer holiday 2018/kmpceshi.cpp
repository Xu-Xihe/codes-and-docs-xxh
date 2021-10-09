#include<cstring>
#include<cstdio>
#define maxe 400033
using namespace std;
char in[maxe];
int f[maxe],out[maxe];
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
	while(scanf("%s",in)!=EOF){
		int len=strlen(in);
		getf(in,f);
		memset(out,0,sizeof(out));
		out[0]=len;
		int j=1;
		for(int i=len;i>0;j++){
			out[j]=f[i];
			i=out[j];
		}
		for(int i=j-2;i>=0;i--){
			printf("%d ",out[i]);
		}
		printf("\n");
	}
	return 0;
}

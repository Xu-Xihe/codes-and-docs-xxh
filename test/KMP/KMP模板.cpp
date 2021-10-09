#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1100000;
char s1[maxn],s2[maxn];
int next[maxn];
void getnext (char P[],int f[]){
	int m=strlen(P);
	f[0]=f[1]=0;
	for (int i=1;i<m;i++){
		int j=f[i];
		while (j&&P[i]!=P[j]) j=f[j];
		f[i+1]=P[i]==P[j]?j+1:0;
	}
}
int find(char T[],char P[],int f[]) {
	int n=strlen(T);
	int m=strlen(P);
	int ans = 0;
	getnext(P,f);
	int j=0;
	for (int i=0;i<n;i++){
		while (j&&P[j]!=T[i]) j=f[j];
		if (P[j]==T[i]) j++;
		if (j==m){ 
			ans++;
			printf("%d\n",i-j+2);
		}
	}
	return ans;
}
int main (){
	scanf("%s%s",s1,s2);//s1为主串，s2为模式串。
	find(s1,s2,next);
	int lens2 = strlen(s2);
	for (int i = 1 ;i<= lens2 ;i++)
		printf("%d ",next[i]);
	printf("\n");
	return 0;
}

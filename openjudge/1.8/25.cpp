#include<stdio.h>
#include<string.h>
using namespace std;
int a[1000][1000],ins[1000][1000],h,l,len,z=1,ax,bx,y;
int _[]={0,0,0,0,0},A[]={0,0,0,0,1},B[]={0,0,0,1,0},C[]={0,0,0,1,1},D[]={0,0,1,0,0},E[]={0,0,1,0,1};
int F[]={0,0,1,1,0},G[]={0,0,1,1,1},H[]={0,1,0,0,0},I[]={0,1,0,0,1},J[]={0,1,0,1,0},K[]={0,1,0,1,1};
int L[]={0,1,1,0,0},M[]={0,1,1,0,1},N[]={0,1,1,1,0},O[]={0,1,1,1,1},P[]={1,0,0,0,0};
int Q[]={1,0,0,0,1},R[]={1,0,0,1,0},S[]={1,0,0,1,1},T[]={1,0,1,0,0},U[]={1,0,1,0,1},V[]={1,0,1,1,0};
int W[]={1,0,1,1,1},X[]={1,1,0,0,0},Y[]={1,1,0,0,1},Z[]={1,1,0,1,0};
char in[1000];
void pd(int back){
	a[ax][bx]=back;
	ins[ax][bx]=888;
	if(z==1)if((bx+1)==l||ins[ax][bx+1]==888)z=2;
	if(z==2)if((ax+1)==h||ins[ax+1][bx]==888)z=3;
	if(z==3)if(bx==0||ins[ax][bx-1]==888)z=4;
	if(z==4)if(ax==0||ins[ax-1][bx]==888)z=1;
	if(z==1)bx++;
	if(z==2)ax++;
	if(z==3)bx--;
	if(z==4)ax--;
}
int main(){
	scanf("%d%d ",&h,&l);
	while(~scanf("%c",&in[y]))y++;
	len=strlen(in);
	for(int i=0;i<len;i++){
		if(in[i]==' ')for(int j=0;j<5;j++)pd(_[j]);
		if(in[i]=='A')for(int j=0;j<5;j++)pd(A[j]);
		if(in[i]=='B')for(int j=0;j<5;j++)pd(B[j]);
		if(in[i]=='C')for(int j=0;j<5;j++)pd(C[j]);
		if(in[i]=='D')for(int j=0;j<5;j++)pd(D[j]);
		if(in[i]=='E')for(int j=0;j<5;j++)pd(E[j]);
		if(in[i]=='F')for(int j=0;j<5;j++)pd(F[j]);
		if(in[i]=='G')for(int j=0;j<5;j++)pd(G[j]);
		if(in[i]=='H')for(int j=0;j<5;j++)pd(H[j]);
		if(in[i]=='I')for(int j=0;j<5;j++)pd(I[j]);
		if(in[i]=='J')for(int j=0;j<5;j++)pd(J[j]);
		if(in[i]=='K')for(int j=0;j<5;j++)pd(K[j]);
		if(in[i]=='L')for(int j=0;j<5;j++)pd(L[j]);
		if(in[i]=='M')for(int j=0;j<5;j++)pd(M[j]);
		if(in[i]=='N')for(int j=0;j<5;j++)pd(N[j]);
		if(in[i]=='O')for(int j=0;j<5;j++)pd(O[j]);
		if(in[i]=='P')for(int j=0;j<5;j++)pd(P[j]);
		if(in[i]=='Q')for(int j=0;j<5;j++)pd(Q[j]);
		if(in[i]=='R')for(int j=0;j<5;j++)pd(R[j]);
		if(in[i]=='S')for(int j=0;j<5;j++)pd(S[j]);
		if(in[i]=='T')for(int j=0;j<5;j++)pd(T[j]);
		if(in[i]=='U')for(int j=0;j<5;j++)pd(U[j]);
		if(in[i]=='V')for(int j=0;j<5;j++)pd(V[j]);
		if(in[i]=='W')for(int j=0;j<5;j++)pd(W[j]);
		if(in[i]=='X')for(int j=0;j<5;j++)pd(X[j]);
		if(in[i]=='Y')for(int j=0;j<5;j++)pd(Y[j]);
		if(in[i]=='Z')for(int j=0;j<5;j++)pd(Z[j]);
	}
	for(int i=0;i<h;i++)
		for(int j=0;j<l;j++)
		printf("%d",a[i][j]);
	return 0;
}

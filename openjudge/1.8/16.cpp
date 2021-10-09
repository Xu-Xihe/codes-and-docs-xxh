#include<stdio.h>
#define shuru 1000
using namespace std;
int ax[4]={1,-1,0,0};
int ay[4]={0,0,-1,1};
int r,c,n; 
char a[shuru][shuru],b[shuru][shuru];
bool panduan(char a,char b){
	if(a=='P'&&b=='R')return true;
	if(a=='R'&&b=='S')return true;
	if(a=='S'&&b=='P')return true;
	else return false;
}
void is(int r,int c,char a[shuru][shuru]){
	for(int i=0;i<=r;i++)
		for(int j=0;j<=c;j++)
		b[i][j]=a[i][j];
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			for(int h=0;h<=3;h++){
				int nx=i+ax[h];
				int ny=j+ay[h];
				if(nx>=0&&ny>=0&&nx<r&&ny<c){
					if(panduan(a[nx][ny],a[i][j])){b[i][j]=a[nx][ny];break;}
					else b[i][j]=a[i][j];
				}
			}
	for(int i=0;i<=r;i++)
		for(int j=0;j<=c;j++)
		a[i][j]=b[i][j];
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&r,&c,&n);
	for(int i=0;i<r;i++)
		scanf("%s",a[i]);
	while(n--)is(r,c,a);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
		printf("%c",a[i][j]);
		if(i<(r-1))printf("\n");
	}
}

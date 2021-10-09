#include<bits/stdc++.h>
using namespace std;
int len,hao[105],qiu;
double fen[105];
int ming(int qiu){
	for(int i=0;;i++){
		double big=0;
		int ji=0;
		for(int j=0;j<len;j++){
			if(fen[j]>big){
				big=fen[j];
				ji=j;
			}
		}
		if(i=qiu-1)return ji;
		else fen[ji]=0;
	}
}
int main(){
	scanf("%d%d",&len,&qiu);
	qiu-=1;
	for(int i=0;i<len;i++){
		scanf("%d",&hao[i]);
		cin>>fen[i];
	}
	for(int i=0;i<qiu;i++){
		double big=0;
		int ji=0;
		for(int i=0;i<len;i++){
			if(fen[i]>big){
				big=fen[i];
				ji=i;
			}
		}
		fen[ji]=0;
	}
	int ji=ming(qiu);
	printf("%d ",hao[ji]);
	cout<<fen[ji];
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
char in[105][105],lin[105][105];
int len,m,out;
int x[]={1,-1,0,0};
int y[]={0,0,1,-1};
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++){
			scanf("%c",&in[i][j]);
			if(in[i][j]=='\n')j--;
			lin[i][j]=in[i][j];
		}
	scanf("%d",&m);
	m--;
	while(m--){
		for(int i=0;i<len;i++){
			for(int j=0;j<len;j++){
				if(in[i][j]=='.'){
					for(int z=0;z<4;z++){
						int nx=i+x[z];
						int ny=j+y[z];
						if(nx>=0&&ny>=0&&ny<len&&nx<len&&in[nx][ny]=='@'){
							lin[i][j]='@';
							break; 
						}
					}
				}
			}
		}
		for(int i=0;i<len;i++){
			for(int j=0;j<len;j++){
				in[i][j]=lin[i][j];
			}
		}
	}
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(in[i][j]=='@')out++;
		}
	}
	printf("%d",out);
	return 0;
}

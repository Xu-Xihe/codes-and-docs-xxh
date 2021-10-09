#include<stdio.h>
#include<string.h>
#define maxe 100000
using namespace std;
int pa,pb,pc;
char in[maxe],tc[maxe];
void pca(int in){
	if(in==2){
		char lin[maxe];
		memset(lin,0,sizeof(lin));
		int len=strlen(tc);
		for(int j=0;j<len;j++){
			lin[len-1-j]=tc[j];
		}
		len=strlen(lin);
		for(int i=0;i<len;i++){
			tc[i]=lin[i];
		}
	}
	return ;
}
void pba(int ina,int a){
	char lin[maxe];
	memset(lin,0,sizeof(lin));
	int z=0;
	for(int i=0;i<a*ina;i++){
		for(int j=0;j<ina;j++){
			lin[z]=tc[i];
			z++;
		}
	}
	for(int i=0;i<a*ina;i++){
		tc[i]=lin[i];
	}
	pca(pc);
	return ;
}
void paa(int in,char qian,char hou){
	memset(tc,0,sizeof(tc));
	if(in==1){
		for(int i=qian+1,j=0;i<hou;i++){
			tc[j]=i;
			j++;
		}
	}
	if(in==2){
		for(int i=qian+1,j=0;i<hou;i++){
			tc[j]=i;
			if(tc[j]>='a'&&tc[j]<='z')tc[j]-=32;
			j++;
		}
	}
	if(in==3){
		for(int i=0;i<(hou-qian-1);i++){
			tc[i]='*';
		}
	}
	pba(pb,hou-qian-1);
	return ;
}
int main(){
	scanf("%d%d%d%s",&pa,&pb,&pc,in);
	for(int i=0;i<strlen(in);i++){
		if(in[i]=='-'){
			if(in[i-1]==in[i+1]||in[i-1]>in[i+1]){
				printf("-");
			}
			else if((in[i-1]>='a'&&in[i+1]<='z'&&in[i-1]<='z'&&in[i+1]>='a')||(in[i-1]>='0'&&in[i+1]<='9'&&in[i-1]<='9'&&in[i+1]>='0')){
				paa(pa,in[i-1],in[i+1]);
				printf("%s",tc);
			}
				else printf("-");
		}
		else printf("%c",in[i]);
	}
	return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ji[4],in[4];
bool if_m(int in,int bi[4],int len,int without[],int without_len){
	int a[4];
	for (int i = 0; i < 4; i++)
	{
		a[i]=bi[i];
	}
	for (int i = 0; i < without_len; i++)
	{
		a[without[i]]=-1;
	}
	for (int i = 0; i < len; i++)
	{
		if (in==a[i])
		{
			return false;
		}
	}
	return true ;
}
bool first(int in[]){
	for (int i = 2; i < 4; i++)
	{
		if (in[i]<in[i-1])
		{
			return false;
		}
	}
	return true;
}
void dfs(int line){
	if(line==4)return ;
	for(int i = 0; i < 4; i++)
	{
		if (!if_m(in[i],in,i,ji,line))
			continue;
		if (line==0&&in[i]==0) {
			continue;
		}
		if(if_m(i,ji,line,ji,0)){
			ji[line]=i;
			dfs(line+1);
			if (line==3){
				if(!first(ji))printf(" ");
				for(int z = 0; z < 4; z++){
					printf("%d",in[ji[z]]);
				}
			}
		}
		if(line==0){
			printf("\n");
		}
	}
}
int main(){
	for(int num=1;;num++){
		int l=0;
		for(int i = 0; i < 4; i++)
		{
			scanf("%d",&in[i]);
			if(in[i]==0)l++;
		}
		if (l==4) {
			return 0;
		}
		if(num>1)printf("\n");
		sort(in,in+4);
		dfs(0);
	}
}
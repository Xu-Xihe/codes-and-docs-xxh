#include<stdio.h>
using namespace std;
int ren,wf,r[506],all,ax,bx,xiao,i;
void is(int ren,int wf){
	xiao=2e10;
	ax=bx=0;
	for(int j=0;j<ren;j++)
		if(r[j]<xiao&&r[j]!=-8)xiao=r[j];
	for(;;i++){
		if(r[i]!=-8)ax+=r[i]-xiao;
		if(ax>=wf){
			all+=bx;
			break;
		}
		else bx=ax;
	}
	for(int j=0;j<i;j++)
		f[j]=-8;
}
int main(){
	scanf("%d%d",&ren,&wf);
	for(int i=0;i<ren;i++)
		scanf("%d",&r[i]);
	
} 

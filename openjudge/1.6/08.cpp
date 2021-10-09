#include<stdio.h>
using namespace std;
int chang,ac,bc,ansa,ansb,acj[150],bcj[150];
int biao[3][3]={//0石头，1剪刀，2布
{0,2,1},
{1,0,2},
{2,1,0},};
void in(int len,int a[]){
	for (int i = 0; i < len; i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==2)a[i]=1;
		else if(a[i]==5)a[i]=2;
	}
}
int main(){
	scanf("%d%d%d",&chang,&ac,&bc);
	in(ac,acj);
	in(bc,bcj);
	for(int i=0;i<chang;i++){
		int na=i%ac,nb=i%bc;
		if(biao[acj[na]][bcj[nb]]==1)ansb++;
		if(biao[acj[na]][bcj[nb]]==2)ansa++;
	}
	if(ansa==ansb)printf("draw");
	else if(ansa>ansb)printf("A");
	else if(ansa<ansb)printf("B");
	printf("\n");
	return 0;
}
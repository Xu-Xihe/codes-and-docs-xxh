#include<stdio.h>
#include<string.h> 
#define maxe 100000
using namespace std;
int in,out[maxe];
int chang(int out[maxe]){
	int z=0;
	for(int i=maxe-2;i>=0;i--){
		if(out[i]!=0){
			z=88;
			return i+1;
		}
	}
	if(z!=88)return 0;
}
void jiafa(int ina[maxe],int inb[maxe],int out[maxe]){
	int lena=chang(ina);
	int outa[maxe];
	memset(outa,0,sizeof(outa));
	int lenb=chang(inb);
	int len;
	if(lena>lenb)len=lena;
	else len=lenb;
	for(int i=0;i<len;i++){
		outa[i]=ina[i]+inb[i];
	}
	for(int i=0;i<len;i++){
		int lin=outa[i]/10;
		outa[i]%=10;
		outa[i+1]+=lin;
	}
	for(int i=0;i<chang(outa);i++){
		out[i]=outa[i];
	}
	return ;
}
void jie(int a[maxe],int in){
	a[0]=1;
	int big=0;
	for(int i=1;i<=in;i++){
		for(int j=0;j<=big;j++){
			a[j]*=i;
		}
		for(int j=0;j<=big;j++){
			int jin=a[j]/10;
			a[j]%=10;
			a[j+1]+=jin;
		}
		if(a[big+1])big++;
		while(a[big]/10>0){
			a[big+1]=a[big]/10;
			a[big]%=10;
			big++;
		}
	}
	return ;
}
int main(){
	scanf("%d",&in);
	for(int i=1;i<=in;i++){
		int lin[maxe];
		memset(lin,0,sizeof(lin));
		jie(lin,i);
		jiafa(out,lin,out);	
	}
	int i;
	i=chang(out);
	for(i-=1;i>=0;i--){
		printf("%d",out[i]);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
char idy[105][105],ido[105][105];
int old[105],numo[105],len,leny,leno;
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		int lin;
		char a[15];
		scanf("%s%d",a,&lin);
		if(lin<60){
			strcpy(idy[i],a);
			leny++;
		}
		else{
			old[leno]=lin;
			strcpy(ido[i],a);
			num[leno]=leno+1;
			leno++;
		}
	}
	for(int al=0;al<leno;al++){
		for(int i=1;i<leno;i++){
			if(old[i-1]<old[i]){
				int a=old[i];
				old[i]=old[i-1];
				old[i-1]=a;
				a=numo[i];
				numo[i]=numo[i-1];
				numo[i-1]=a;
				a=ido[i];
				ido[i]=ido[i-1];
				ido[i-1]=a;
			}
			if(old[i-1]==old[i]&&numo[i-1]>numo[i]){
				int b=numo[i];
				numo[i]=numo[i-1];
				numo[i-1]=b;
				b=ido[i];
				ido[i]=ido[i-1];
				ido[i-1]=b;
			}
		}
	}
	for(int i=0;i<leno;i++){
		printf("%d\n",id)
	}
}

#include<bits/stdc++.h>
using namespace std;
double ina,inb,z=200,mm;
int out=-1;
int main(){
	cin>>ina>>inb;
	inb/=100;
	inb++;
	mm=ina;
	for(int i=1;i<=20;i++){
		if(mm>=z){
			out=i;
			break;
		}
		mm+=ina;
		z*=inb;
	}
	if(out>0)printf("%d",out);
	else printf("Impossible");
	return 0;
} 

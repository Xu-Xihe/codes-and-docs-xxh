#include<stdio.h>
int a; 
int main(){
	FILE*fin,*fout;
	fin=fopen("in.in","rd");
	fout=fopen("out.out","wd");
	fscanf(fin,"%d",&a);
	printf("%d",a);
	a++;
	fprintf(fout,"%d",a);
	fclose(fin);
	fclose(fout);
	return 0;
}

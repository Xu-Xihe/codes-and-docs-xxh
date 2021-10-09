#include<stdio.h>
#include<string.h>
using namespace std;
int maxe=-1,minn=1e9,len,ji[26];
char in[10005];
bool zhishu(int in){
	if(in==1||in==0)return false;
	for(int i=1;i<in;i++){
		if(in%i==0&&i!=1)return false;
	}
	return true;
}
int main(){
	scanf("%s",in);
	len=strlen(in);
	for(int i=0;i<len;i++)
		ji[in[i]-'a']+=1;
	for(int i=0;i<26;i++){
		if(ji[i]<minn&&ji[i]!=0)
			minn=ji[i];
		if(ji[i]>maxe)
			maxe=ji[i];
	}
	int lin=maxe-minn;
	if(zhishu(lin)){
		printf("Lucky Word\n%d",lin);
	}
	else printf("No Answer\n0");
	return 0;
}

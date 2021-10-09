#include<bits/stdc++.h>
using namespace std;
int chinese[305],all[305],num[305],len;
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		int math,english;
		scanf("%d%d%d",&chinese[i],&math,&english);
		all[i]=chinese[i]+math+english;
		num[i]=i+1;
	}
	for(int az=0;az<len;az++){
		for(int i=1;i<len;i++){
			if(all[i-1]<all[i]){
				int lin=all[i];
				all[i]=all[i-1];
				all[i-1]=lin;
				lin=num[i];
				num[i]=num[i-1];
				num[i-1]=lin;
				lin=chinese[i];
				chinese[i]=chinese[i-1];
				chinese[i-1]=lin;
			}
			if(all[i-1]==all[i]){
				if(chinese[i-1]<chinese[i]){
					int lin=num[i];
					num[i]=num[i-1];
					num[i-1]=lin;
					lin=chinese[i];
					chinese[i]=chinese[i-1];
					chinese[i-1]=lin;
				}
				if(chinese[i-1]==chinese[i]&&num[i-1]>num[i]){
					int lin=num[i];
					num[i]=num[i-1];
					num[i-1]=lin;
				}
			}
		}
	}
	for(int i=0;i<5;i++){
		printf("%d %d\n",num[i],all[i]);
	}
	return 0;
}

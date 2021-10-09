#include<bits/stdc++.h>
using namespace std;
int len,in[1005],m,out;
queue<int> nie;
bool find(int in){
	for(int i=0;i<nie.size();i++){
		if(in==nie(i)return true;
	}
	return false;
}
int main(){
	scanf("%d%d",&m,&len);
	for(int i=0;i<len;i++){
		scanf("%d",&in[i]);
	}
	for(int i=0;i<len;i++){
		if(find(in[i])==false){
			if(nie.size()==m)nie.pop();
			nie.push(in[i]);
			out++;
		}
	}
	printf("%d",out);
	return 0;
}

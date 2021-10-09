#include<bits/stdc++.h>
using namespace std;
int m,n,ji[305];
int bu(int m,int n,int start,int ji[305]){
	for(int i=start,shu=0;shu<m;shu++){
		i%=m;
		if(ji[i]==0){
			m++;
		}
		i++;
	}
	printf("c c=%d\n",m);
	return m;
}
int main(){
	while(true){
		scanf("%d%d",&n,&m);
		if(m==0)return 0;
		memset(ji,0,sizeof(ji));
		for(int i=0;i<n;i++){
			ji[i]=i+1;
		}
		int now=0;
		for(int z=0;z<n-1;z++){
			now+=bu(m,n,now,ji);
			now%=m;
			ji[now]=0;
			now++;
		}
		for(int i=0;;i++){
			if(ji[i]!=0){
				printf("%d\n",ji[i]);
				break;
			}
		}
	}
}

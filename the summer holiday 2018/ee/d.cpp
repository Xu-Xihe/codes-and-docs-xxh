#include<bits/stdc++.h>
using namespace std;
int aa[25],len;
int fen(int m,int n)
{
    if(m==0||m==1||n==1){
    	return 1;
	}	
    if(m<n){
    	return fen(m,m);
	}	
    if(m>=n){
    	return fen(m-n,n)+fen(m,n-1);
	}
}
int main(){
    scanf("%d",&len);
    for(int i=1;i<=len;i++){
		int n,m;
        scanf("%d%d",&m,&n);
        aa[i]=fen(m,n);
    }
    for(int i=1;i<=len;i++)
    	printf("%d\n",aa[i]);
    return 0;
}

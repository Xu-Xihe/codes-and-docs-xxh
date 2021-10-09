#include<bits/stdc++.h>
#define MAXN 500002
//求最长上升子序列 
using namespace std;
int f[MAXN];
struct pos{
	int south;
	int num;
};
int cmp(pos a,pos b){
	if(a.south<b.south) return 1;
	else return 0;
}
pos a[MAXN];
int main(){
	int n;
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>a[j].south>>a[j].num;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)//i代表第i个城市 
    {
    	f[i] = 1; 
		for(int j=i;j>=1;j--)//j用来循环第i个城市之前的城市 
            if(a[i].num>a[j].num)//如果i对应的友好城市大于循环到的城市 
                f[i]=max(f[j]+1,f[i]);//求以第i个城市作为最后批准的城市所能达到的最大批准数
    } 
    int mx=f[1];
	for(int i=1;i<=n;i++){
		mx=max(mx,f[i]);
	}
	cout<<mx<<endl;
	return 0;	
}

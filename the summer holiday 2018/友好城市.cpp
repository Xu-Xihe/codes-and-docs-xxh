#include<bits/stdc++.h>
#define MAXN 500002
//������������� 
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
	for(int i=1;i<=n;i++)//i�����i������ 
    {
    	f[i] = 1; 
		for(int j=i;j>=1;j--)//j����ѭ����i������֮ǰ�ĳ��� 
            if(a[i].num>a[j].num)//���i��Ӧ���Ѻó��д���ѭ�����ĳ��� 
                f[i]=max(f[j]+1,f[i]);//���Ե�i��������Ϊ�����׼�ĳ������ܴﵽ�������׼��
    } 
    int mx=f[1];
	for(int i=1;i<=n;i++){
		mx=max(mx,f[i]);
	}
	cout<<mx<<endl;
	return 0;	
}

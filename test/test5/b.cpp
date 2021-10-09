#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int maxe = 1000;
int in_1[maxe],in_2[maxe],len;
void lisanhua(int len ,int in[]){
	map <int,int> first;
	first.clear();
	int lin[maxe];
	for (int i = 0; i < len; i++)
	{
		first[in[i]]=i;
		lin[i]=in[i];
	}
	sort(lin,lin+len);
	for (int i = 0; i < len; i++)
	{
		in[first[lin[i]]]=i;
	}
	return ;
}
int main(){
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&in_1[i]);
    }
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&in_2[i]);
    }
	lisanhua(len,in_1);
	lisanhua(len,in_2);
	map<int,int>fis;
	for (int i = 0; i < len; i++)
	{
		fis[in_1[i]]=i;
	}
	for (int i = 0; i < len; i++)
	{
		in_2[i]=fis[in_2[i]];
	}
	int ans=0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j < len; j++)
		{
			if(in_2[i]<in_2[i-1]){
				int a=in_2[i];
				in_2[i]=in_2[i-1];
				in_2[i-1]=a;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
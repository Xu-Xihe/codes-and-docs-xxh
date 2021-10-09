#include<bits/stdc++.h>
using namespace std;
const int n=10;
const int m=15;
const int W=100;
int cnt=0;
struct edge
{
    int u,v,w;	
}e[m];
inline unsigned int Rand()
{
	static unsigned int seed=2333;
	seed^=seed<<17,seed^=seed>>5,seed^=seed<<23;
	return seed;	
}
int a[100];
int main()
{
	srand(time(NULL));
	for(int i=1;i<=n;++i)a[i]=i;
	random_shuffle(a+1,a+1+n);
	for(int i=1;i<=n;++i)printf("%d ",a[i]);printf("\n");
	//freopen("1.in","w",stdout);
	printf("%d\n",n);
	for(int i=2;i<=n;++i)
	{
		e[cnt++]=(edge){Rand()%(i-1)+1,i,Rand()%W+1};
	}
	for(int i=n;i<=m;++i)
	{
        int u,v;
		do
		{
		    u=Rand()%n+1;
		    v=Rand()%n+1;			
		}while(u==v);
		
		if(u>v)swap(u,v);
		e[cnt++]=(edge){u,v,Rand()%W+1};
	}
	random_shuffle(e,e+m);
	for(int i=0;i<m;++i)printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
}

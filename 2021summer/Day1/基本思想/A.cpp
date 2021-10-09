#include<cstdio>
struct roof
{
	int a,b,x,y;
}ins[10009];
int len,x,y;
bool if_in(int a,int b,int x,int y,int x_check,int y_check)
{
	return x_check>=a&&x_check<=a+x&&y_check>=b&&y_check<=b+y?true:false;
}
int main()
{
	scanf("%d",&len);
	for(int i=0;i<len;i++)
	{
		scanf("%d%d%d%d",&ins[i].a,&ins[i].b,&ins[i].x,&ins[i].y);
	}
	scanf("%d%d",&x,&y);
	for(int i=len-1;i>=0;i--)
	{
		if(if_in(ins[i].a,ins[i].b,ins[i].x,ins[i].y,x,y))
		{
			printf("%d",i+1);
			return 0;
		}
	}
	printf("-1");
	return 0;
}

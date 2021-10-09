#include<cstdio>
#include<vector>
int max,ans,L,in[100006],len;
std::vector<int>ji;
int main()
{
	freopen("sim.in","r",stdin);
	freopen("sim.out","w",stdout);
	scanf("%d",&len);
	ji.push_back(0);
	for(int i=0;i<len;i++)
	{
		scanf("%d",&in[i]);
		if(in[i]<(i==0?1e9:in[i-1]))
		{
			ji.push_back(i);
			if(i-ji[ji.size()-2]>max)max=i-ji[ji.size()-2];
		}
	}
	ji.push_back(len);
	if(len-ji[ji.size()-2]>max)max=len-ji[ji.size()-2];
	//printf("%d\n\n",ji.size()-2);
	L=max/2;
	L+=L==0?1:0;
	printf("%d ",max);
	for(int i=1;i<ji.size();i++)
	{
		int a=ji[i]-ji[i-1];
		for (int j = L; j <= a; j++)
		{
			ans+=a-j+1;
		}
		//printf("\ni-->%d ji[i]-->%d ji[i-1]--%d ans-->%d\n",i,ji[i],ji[i-1],ans);
	}
	printf("%d",ans);
	return 0;
}

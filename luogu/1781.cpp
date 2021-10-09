#include<cstdio>
#include<iostream>
using std::string;
string in, max;
int ans, len;
int main()
{
	scanf("%d", &len);
	for (int i = 1; i <= len;i++)
	{
		std::cin >> in;
		if(in.length()>max.length()||(in>max&&in.length()==max.length())||max=="")
		{
			ans = i;
			max = in;
		}
		//std::cout << in <<"   " << max << "\n";
	}
	std::cout << ans << "\n"<< max;
	return 0;
}
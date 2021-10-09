#include<iostream>
#include<math.h>
using namespace std;
unsigned long long p = 0;
unsigned long long in,w;
int main()
{
	unsigned long long s;
	cout << "???????????????  ";
	cin >> s;
	unsigned long long shuru = s;
	cout << endl << s << " = " ;
	while (1)
	{
		w=sqrt(s)+1;
		for(unsigned long long a = 2;a<=w;a++)
		{
			if(s%a==0)
			{
				cout << a << "x";
				p++;
				s = s/a;
				in = 0;
				break;
			}
			else 
			{
				in = 1;
			}
		}
		if (in==1) 
		{
			cout << s;
			break;
		}
	}
	return 0;
}

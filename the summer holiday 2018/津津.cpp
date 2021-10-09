#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int deposit = 0;
	int sum = 0;
	for(int i = 1; i <= 12; ++i)
	{
		sum += 300;
		int t;
		cin >> t;
		sum -= t;
		if(sum < 0)
		{
			cout << -i;
			return 0;
		}
		deposit += sum / 100 * 100;
		sum %= 100;
	}
	cout << deposit + sum + deposit / 5;
	return 0;
}




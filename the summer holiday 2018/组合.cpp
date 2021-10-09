#include<iostream>
#include<cstdio>
using namespace std;
int n, r, a[30], used[30];
void permutation(int i)
{
    if (i == r + 1)
    {
        for (int j = 1; j <= r; ++j)
            printf("%3d", a[j]); 
        cout << endl;
        return;
    }
    for(int j = a[i - 1] + 1; j <= n; ++j)
        if (used[j] == 0)
        {
            used[j] = 1;
            a[i] = j;
            permutation(i + 1);
            used[j] = 0;
        }
}
int main()
{
    cin >> n >> r;
    for (int i = 1; i <= n; ++i)
        used[i] = 0;
    permutation(1);
    return 0;
}

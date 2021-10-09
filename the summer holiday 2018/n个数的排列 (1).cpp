#include<iostream>
using namespace std;
int n, a[20], used[20];
void permutation(int i)
{
    if (i == n + 1)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[j] << " ";
        cout << endl;
        return;
    }
    for(int j = 1; j <= n; ++j)
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
    cin >> n;
    for (int i = 1; i <= n; ++i)
        used[i] = 0;
    permutation(1);
    return 0;
}

#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxe = 105;
int t, l, w;
string o;
string code[maxe];
int get(int &x, string c)
{
    int ans = 0;
    int len = c.size();
    while (c[x] < '0' || c[x] > '9' && x < c.size())
    {
        if (c[x] == 'n')
        {
            ++x;
            return 1000000;
        }
        ++x;
    }
    while (c[x] >= '0' && c[x] <= '9')
    {
        ans *= 10;
        ans += c[x] - '0';
        ++x;
    }
    return ans;
}
int xxh()
{
    int ans = 0, x = 3;
    int len = o.size();
    if (o[2] == 'n')
        ans = get(x, o);
    else
        ans = 0;
    return ans;
}
int check()
{
    int ans = 0, nowid = 0;
    int a, b, x;
    stack<int> s;
    int ji = -1;
    bool lin[26] = {0};
    bool ef[26] = {0};
    for (int i = 1; i <= l; i++)
    {
        if (code[i][0] == 'F')
        {
            int k = code[i][2] - 'a';
            if (lin[k])
                return -1;
            s.push(k);
            lin[k] = true;
            x = 4;
            a = get(x, code[i]);
            b = get(x, code[i]);
            if (b - a > 1000)
            {
                if (ji == -1)
                {
                    nowid++;
                    ans = max(ans, nowid);
                    ef[k] = true;
                }
            }
            if (a > b)
            {
                if (ji == -1)
                    ji = k;
            }
        }
        if (code[i][0] == 'E')
        {
            if (s.empty())
                return -1;
            int k = s.top();
            s.pop();
            lin[k] = false;
            if (ji == k)
                ji = -1;
            if (ef[k])
            {
                ef[k] = false;
                nowid--;
            }
        }
    }
    if (s.size())
        return -1;
    return ans;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int ww;
        scanf("%d ", &l);
        getline(cin, o);
        w = xxh();
        for (int i = 1; i <= l; i++)
            getline(cin, code[i]);
        ww = check();
        if (ww == -1)
            puts("ERR");
        else
        {
            if (ww == w)
                puts("Yes");
            else
                puts("No");
        }
    }
}
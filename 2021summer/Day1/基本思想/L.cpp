#include <cstdio>
#include <bitset>
const int maxe = 1e5 + 9;
struct dd
{
    int num, type;
} door[maxe];
int n, m;
char in[10];
std::bitset<40> cmp;
std::bitset<40> big;
std::bitset<40> ans;
inline void find()
{
    
}
int main()
{
    scanf("%d%d", &n, &m);
    cmp = m;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", in, &door[i].num);
        door[i].type = in[0] == 'O' ? 1 : in[0] == 'X' ? 2 : 3;
    }
}
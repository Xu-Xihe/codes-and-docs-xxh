#include <cstdio>
#include <cstring>
const int maxe = 1e6 + 9;
char a[maxe], b[maxe];
int nxt[maxe], na, nb,ans;
inline void get_next(char *in, int *next)
{
	int len = strlen(in);
	next[0] = next[1] = 0;
	for (int i = 2; i <= len; i++)
	{
		int now = next[i - 1];
		while (now && in[now] != in[i - 1])
			now = next[now];
		next[i] = in[i - 1] == in[now] ? now + 1 : 0;
	}
}
int main()
{
	scanf("%s%s", a, b);
	na = strlen(a);
	nb = strlen(b);
	get_next(b, nxt);
	for (int i = 0, j = 0; i < na; i++)
	{
		while (j && b[j] != a[i])
		{
			j = nxt[j];
		}
		if (b[j] == a[i])
			j++;
		if (j == nb)
		{
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
#include <cstdio>
#include <algorithm>
const int maxe = 1e5;
int root, tot, son[maxe][2], size[maxe], val[maxe], rnd[maxe], ll, rr, LL, RR;
#define Ls son[pos][0]
#define Rs son[pos][1]
inline int nnd(int x)
{
	size[++tot] = 1;
	val[tot] = x;
	rnd[tot] = rand();
	return tot;
}
inline void upd(int pos)
{
	size[pos] = size[Rs] + size[Ls] + 1;
}
inline void spv(int pos, int key, int &l, int &r)
{
	if (pos == 0)
	{
		l = r = 0;
		return;
	}
	if (val[pos] <= key)
	{
		l = pos;
		spv(Rs, key, Rs, r);
	}
	else
	{
		r = pos;
		spv(Ls, key, l, Ls);
	}
	upd(pos);
}
inline void spn(int pos, int key, int &l, int &r)
{
	if (pos == 0)
	{
		l = r = 0;
		return;
	}
	if (size[Ls] + 1 <= key)
	{
		l = pos;
		spn(Rs, key - size[Ls] - 1, Rs, r);
	}
	else
	{
		r = pos;
		spn(Ls, key, l, Ls);
	}
	upd(pos);
}
inline int tog(int l, int r)
{
	if (l == 0 || r == 0)
		return l + r;
	if (rnd[l] < rnd[r])
	{
		son[l][1] = tog(son[l][1], r);
		upd(l);
		return l;
	}
	son[r][0] = tog(l, son[r][0]);
	upd(r);
	return r;
}
inline void ins(int v)
{
	spv(root, v, ll, rr);
	root = tog(tog(ll, nnd(v)), rr);
}
inline void del(int v)
{
	spv(root, v, ll, rr);
	spv(ll, v - 1, ll, RR);
	RR = tog(son[RR][0], son[RR][1]);
	root = tog(tog(ll, RR), rr);
}
inline int ordv(int v)
{
	spv(root, v - 1, ll, rr);
	int r = size[ll];
	root = tog(ll, rr);
	return r + 1;
}
inline int ordn(int k)
{
	spn(root, k, ll, rr);
	spn(ll, k - 1, ll, RR);
	int ans = val[RR];
	root = tog(tog(ll, RR), rr);
	return ans;
}
inline int fit(int v)
{
	spv(root, v - 1, ll, rr);
	spn(ll, size[ll] - 1, ll, RR);
	int ans = val[RR];
	root = tog(tog(ll, RR), rr);
	return ans;
}
inline int back(int v)
{
	spv(root, v, ll, rr);
	spn(rr, 1, LL, rr);
	int ans = val[LL];
	root = tog(tog(ll, LL), rr);
	return ans;
}
int main()
{
	int len, a, b;
	scanf("%d", &len);
	while (len--)
	{
		scanf("%d%d", &a, &b);
		if (a == 1)
			ins(b);
		if (a == 2)
			del(b);
		if (a == 3)
			printf("%d\n", ordv(b));
		if (a == 4)
			printf("%d\n", ordn(b));
		if (a == 5)
			printf("%d\n", fit(b));
		if (a == 6)
			printf("%d\n", back(b));
	}
	return 0;
}
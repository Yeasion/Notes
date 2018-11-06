#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = (int)1e5;
typedef int arrv[N + 10];
typedef int arre[2 * N + 10];

int n, tot, j, k;
arrv g;
arre pt, nt;

void Link(int x, int y) {
	pt[++tot] = y, nt[tot] = g[x], g[x] = tot;
	pt[++tot] = x, nt[tot] = g[y], g[y] = tot;
}

void Dfs(int x, int fa, int dis) {
	if (dis > k) k = dis, j = x;
	for (int i = g[x]; i; i = nt[i])
		if (pt[i] != fa) Dfs(pt[i], x, dis + 1);
}

int main() {
	freopen("distance.in", "r", stdin);
	freopen("distance.out", "w", stdout);

	scanf("%d%d\n", &n, &k);
	for (int i = 1; i < n; ++i) scanf("%d%d\n", &j, &k), Link(j, k);

	j = k = 0;
	Dfs(1, 0, 1);
	Dfs(j, 0, 1);
	if (~k & 1) printf("%d\n", k / 2 + 1);
	else printf("%d\n", (k + 1) / 2);
	
	return 0;
}

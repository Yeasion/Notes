#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = (int)1e4;
typedef int arr[N + 10];
typedef int arrq[100 * N + 10];

int n, m, j, k, p, S, T, tot;
arr g, pt, nt, w;
bool dp[102][102][102];
arrq qx, qy, qz;
int f, r;

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

void link(int x, int y, int z) {
	pt[++tot] = y, nt[tot] = g[x], g[x] = tot, w[tot] = z;
	pt[++tot] = x, nt[tot] = g[y], g[y] = tot, w[tot] = z;
}

int main() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d %d %d", &j, &k, &p), link(j, k, p);
	scanf("%d %d", &S, &T);

	dp[S][0][101] = 1;
	qx[f = r = 1] = S, qy[r] = 0, qz[r] = 101;

	for ( ; f <= r; ) {
		int x = qx[f], y = qy[f], z = qz[f++];
		for (int i = g[x]; i; i = nt[i]) {
			if (!dp[pt[i]][max(y, w[i])][min(z, w[i])]) {
				dp[pt[i]][max(y, w[i])][min(z, w[i])] = 1;
				qx[++r] = pt[i], qy[r] = max(y, w[i]), qz[r] = min(z, w[i]);
			}
		}
	}
	
	int bestnum = 101, bestdenom = 1;
	for (int i = 1; i <= 100; ++i)
		for (int j = 1; j <= i; ++j)
			if (dp[T][i][j]) {
				if (i * bestdenom < j * bestnum)
					bestnum = i, bestdenom = j;
			}
	
	if (bestnum == 101) printf("IMPOSSIBLE\n");
	else {
		int g = gcd(bestnum, bestdenom);
		bestnum /= g, bestdenom /= g;
		if (bestdenom == 1) printf("%d\n", bestnum);
		else printf("%d/%d\n", bestnum, bestdenom);
	}
	
	return 0;
}

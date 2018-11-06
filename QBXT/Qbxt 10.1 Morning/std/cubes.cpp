#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e4;
typedef int arr[N + 10];
typedef long long ll;

int m, j, k;
arr ufs, below, sz;
char ope[3];

int find(int x) {
	if (x == ufs[x]) return x;
	int f = find(ufs[x]);
	below[x] += below[ufs[x]];
	return ufs[x] = f;
}

void move(int x, int y) {
	int fx = find(x), fy = find(y);
	ufs[fx] = fy;
	below[fx] += sz[fy];
	sz[fy] += sz[fx];
}

int main() {
	freopen("cubes.in", "r", stdin);
	freopen("cubes.out", "w", stdout);

	for (int i = 1; i <= N; ++i) ufs[i] = i, sz[i] = 1, below[i] = 0;

	for (scanf("%d", &m); m--; ) {
		scanf("%s", ope + 1);
		if (ope[1] == 'M') {
			scanf("%d %d", &j, &k), move(j, k);
		}
		else {
			scanf("%d", &k);
			ufs[k] = find(k);
			printf("%d\n", below[k]);
		}
	}
	
	return 0;
}

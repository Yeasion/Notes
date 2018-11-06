#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = (int)1e5;
typedef long long ll;
typedef int arr[N + 10];

int n, K, f, r;
arr q;
ll e[N + 10], dp[N + 10];

int main() {
	freopen("work.in", "r", stdin);
	freopen("work.out", "w", stdout);

	scanf("%d %d", &n, &K);
	for (int i = 1; i <= n; ++i) scanf("%lld", e + i), e[i] += e[i - 1];
	
	q[f = r = 1] = 0, dp[0] = 0;

	for (int i = 1; i <= n + 1; ++i) {
		if (q[f] < i - K - 1) ++f;
		dp[i] = dp[q[f]] + e[i - 1] - e[q[f]];
		for ( ; r >= f && dp[q[r]] - e[q[r]] <= dp[i] - e[i]; --r);
		q[++r] = i;
	}

	cout << dp[n + 1] << endl;
	return 0;
}

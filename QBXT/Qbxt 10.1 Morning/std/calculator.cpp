#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = (int)2e5, mod = (int)1e9 + 7;
typedef long long ll;

int S, T, K;
int fac[N + 10], ifac[N + 10];

int pow(int x, int y) {
	ll t = x, r = 1;
	for ( ; y; y >>= 1, t = t * t % mod)
		if (y & 1) r = r * t % mod;
	return r;
}

void preprocessing() {
	fac[0] = 1;
	for (int i = 1; i <= N; ++i) fac[i] = (ll)fac[i - 1] * (ll)i % mod;
	ifac[N] = pow(fac[N], mod - 2);
	for (int i = N - 1; i >= 0; --i) ifac[i] = (ll)ifac[i + 1] * (ll)(i + 1) % mod;
}

int c(int n, int r) {
	return (ll)fac[n] * (ll)ifac[r] % mod * (ll)ifac[n - r] % mod;
}

int main() {
	freopen("calculator.in", "r", stdin);
	freopen("calculator.out", "w", stdout);
	
	preprocessing();
	scanf("%d %d %d", &S, &T, &K);
	if (S > T) swap(S, T);

	int ans = 0;
	for (int i = 0; i <= K; ++i) {
		if ((i + T - S) & 1) continue;
		int x = (i - T + S) >> 1, y = (i + T - S) >> 1;
		if (x < 0) continue;
		(ans += c(x + y, x)) %= mod;
		if (x > S) (ans += (mod - c(x + y, x - S - 1))) %= mod;
	}

	printf("%d\n", ans);
	return 0;
}

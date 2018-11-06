#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#define R "%d"
#define RL "%lld"
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define FOR(x, l, r) for (ll x = (l), end = (r); x <= end; ++x)
#define ROF(x, l, r) for (ll x = (l), end = (r); x >= end; --x)
using namespace std;

typedef int LL;
typedef long long ll;

const LL oo = (LL)2e9;
const ll INF = (ll)1e17;

const LL N = (LL)6e5;
typedef ll arr[N + 10];

struct node {
	ll x, y, z;
}a[N + 10], b[N + 10];

ll i, j, k, p, n, ma, mb, w, ans = INF, cal, mx, mxn, s, prv, prls, prmxn;
arr pr, mi, mip, sa;

bool cmp_a(const node &a, const node &b) { return a.x < b.x; }

bool cmp_b(const node &a, const node &b) { return a.x + a.y < b.x + b.y; }

LL main() {
	freopen("sweet.in", "r", stdin);
	freopen("sweet.out", "w", stdout);
	scanf(RL RL "\n", &n, &w);
	FOR (i, 1, n) {
		scanf(RL RL "\n", &j, &k);
		if (k > 2 * j) a[++ma] = (node){j, i, 1}, a[++ma] = (node){k - j, i, 2};
		else b[++mb] = (node){j, k - j, i};
	}
	sort(a + 1, a + ma + 1, cmp_a), sort(b + 1, b + mb + 1, cmp_b);
	
	mi[mb + 1] = oo;
	ROF (i, mb, 1)
		if (mi[i + 1] < b[i].x) mi[i] = mi[i + 1], mip[i] = mip[i + 1];
		else mi[i] = b[i].x, mip[i] = i;
	
	FOR (i, 1, ma) sa[i] = sa[i - 1] + a[i].x;
	
	FOR (ls, 0, Min(w, mb << 1)) {
		if (ls & 1) {
			p = (ls + 1) >> 1, s += b[p].x + b[p].y;
			if (b[p].y > mx) mx = b[p].y, mxn = p;
			if (w - ls > ma) continue;
			ll go = -1, ck = 0;;
			if (s - mx < s - b[p].x - b[p].y + mi[p + 1]) go = 0, ck = s - mx + sa[w - ls];
			else go = 1, ck = s - b[p].x - b[p].y + mi[p + 1] + sa[w - ls];
			if (ck < ans) {
				ans = ck;
				if (go == 0) {
					prv = 0, prls = ls, prmxn = mxn;
				}
				else {
					prv = 1, prls = ls;
				}
			}
		}
		else {
			p = ls >> 1;
			if (w - ls > ma) continue;
			ll ck = s + sa[w - ls];
			if (ck < ans) {
				ans = ck;
				prv = 2, prls = ls;			
			}
		}
	}

	printf(RL "\n", ans);
	
	p = ((prls & 1) ? (prls + 1) >> 1 : prls >> 1);
	if (prv == 0) {
		FOR (i, 1, p)
			if (i != prmxn) pr[b[i].z] = 2;
			else pr[b[i].z] = 1;
		FOR (i, 1, w - prls) pr[a[i].y] = Max(pr[a[i].y], a[i].z);
	}
	else if (prv == 1) {
		FOR (i, 1, p - 1) pr[b[i].z] = 2;
		pr[b[mip[p + 1]].z] = 1;
		FOR (i, 1, w - prls) pr[a[i].y] = Max(pr[a[i].y], a[i].z);
	}
	else {
		FOR (i, 1, p) pr[b[i].z] = 2;
		FOR (i, 1, w - prls) pr[a[i].y] = Max(pr[a[i].y], a[i].z);
	}

	FOR (i, 1, n) printf(RL "\n", pr[i]);
	
	return 0;
}

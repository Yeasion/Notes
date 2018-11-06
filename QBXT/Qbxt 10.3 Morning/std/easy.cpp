#include <bits/stdc++.h>

#define MOD 991127

using namespace std ;

int n ; 

const int MAXN = 200010 ;

int a[MAXN];

int f[30] ;

int dp[MAXN] ; 

inline void update(int &a, int b) {
		a += b ;
		if (a >= MOD) a -= MOD ; 
}
int main() { 

		scanf("%d", &n) ; 
		for (int i = 1; i <= n; i ++) { 
				scanf("%d", &a[i]) ; 
		}

		memset(f, 0, sizeof f); 

		for (int i = 0; i < 30; i ++) { 
				if ((a[1] >> i) & 1) f[i] = 1;  
		}
		dp[1] = 1 ; 
		for (int i = 2; i <= n; i ++) { 
				for (int j = 0; j < 30; j ++) { 
						if ((a[i] >> j) & 1) update(dp[i], f[j]) ; 
				}
				for (int j = 0; j < 30; j ++) { 
						if ((a[i] >> j) & 1) update(f[j], dp[i]) ; 
				}
		}

		printf("%d\n", dp[n]) ; 

}

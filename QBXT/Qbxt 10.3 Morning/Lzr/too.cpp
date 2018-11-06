#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100010
#define Inf 0x7fffffff
#define LL long long
#define Mod 12345
using namespace std ;
int Read(){
	int X = 0 ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
}
int N, M, Ans = 1 ;
int main(){
	freopen("too.in", "r", stdin) ;
	freopen("too.out", "w", stdout) ;
	N = Read() ; M = Read() ;
	for(int i = 1; i <= M; i ++){
		char Opt ; int X ;
		cin >> Opt >> X ;
		Ans = Ans * X % Mod ;
	}
	printf("%d", 2 *Ans * 2 * Ans % Mod) ;
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}

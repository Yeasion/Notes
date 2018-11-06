#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define Inf 0x7fffffff
#define LL long long
#define Mod 10000007
using namespace std ;
int Read(){
	int X = 0 ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
}
int N, Ans ;
int Times(int A, int B){
	int Ans = 1 ;
	while(B){
		if(B % 2 == 1) Ans = Ans * A % Mod ;
		A = A * A % Mod ;
		B >>= 1 ;
	}
	return Ans ;
}
int main(){
	N = Read() ;
	if(N == 1){
		puts("0") ; return 0 ;
	}
	int Erh = 1, Cnh = 1, Nh2 = 1 ;
	for(int i = 1; i <= 2 * N - 1; i ++)
		Nh2 *= i ;
	for(int i = 1; i <= N; i ++){
		int A = Erh * Cnh % Mod * Nh2 % Mod ;
		if(A % 2 == 1) Ans -= A ;
		else Ans += A ; Ans %= Mod ;
		if(i == N) break ; Erh <<= 1 ;
		if(Erh >= Mod) Erh -= Mod ;
		Cnh = Cnh * (N - i) % Mod * Times(i + 1, Mod - 2) % Mod ;
		Nh2 = Nh2 * Times(2 * N - i - 1, Mod - 2) % Mod ;		
	}
	printf("%d\n", Ans) ; return 0 ;
}

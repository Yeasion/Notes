#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define Inf 0x7ffffff
#define LL long long
#define Mod 100000007
using namespace std ;
int Read(){
	int X = 0 ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
}
int S, T, K, Ans ;
void Search(int Now, int Sum, int Step){
	if(Step > K) return ; 
	Sum += Now ;
	if(Sum < 0) return ;
	if(Sum == T) Ans = (Ans + 1) % Mod ;
	Search(1, Sum, Step + 1) ;
	Search(- 1, Sum, Step + 1) ;
}
int main(){
	freopen("calculator.in", "r", stdin) ;
	freopen("calculator.out", "w", stdout) ;
	S = Read(), T = Read(), K = Read() ;
	if(S == T) Ans ++ ;
	Search(1, S, 1) ;
	Search(-1, S, 1) ;
	printf("%d", Ans % Mod) ;
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}

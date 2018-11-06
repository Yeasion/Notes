#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define LL long long
#define Inf 0x7fffffff
using namespace std ;
int Read(){
	int X = 0 ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
}
LL N, Data[MAXN], K, Ans ;
int main(){
//	freopen("work.in", "r", stdin) ;
//	freopen("work.out", "w", stdout) ;
	N = Read(), K = Read() ;
	for(int i = 1; i <= N; i ++)
		Data[i] = Read() , Ans += Data[i] ;
	printf("%lld", Ans * 2 / 3) ;
//	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}

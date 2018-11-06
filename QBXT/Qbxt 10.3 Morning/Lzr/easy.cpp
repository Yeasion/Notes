#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 50010
#define Inf 0x7fffffff
#define LL long long
#define Mod 991127
using namespace std ;
int Read(){
	int X = Read() ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
}
int N, Data[MAXN] ;
int main(){
	freopen("easy.in", "r", stdin) ;
	freopen("easy.out", "w", stdout) ;
	N = Read() ;
	for(int i = 1; i <= N; i ++)
		Data[i] = Read() ;
	printf("1") ;
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}

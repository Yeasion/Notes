#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100010
#define Inf 0x7fffffff
#define LL long long
using namespace std ;
LL Read()
{	
	LL X = 0, F =1 ; char ch = getchar() ;
	while(ch < '0' || ch > '9'){
		if(ch = '-') F = - 1 ;
		ch = getchar() ;
	}
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X * F ;
}
LL N, C, A[MAXN], B[MAXN] ;
bool Flag[MAXN] ;
LL Ans, V[MAXN], Next[MAXN] ;
bool Ken = 0 ;
bool Search(LL Start, LL Now, LL Cost){
	if(Now == Start && Ken) return 1 ;
	if(Now == Start && ! Ken) Ken = 1 ;
	Cost += V[Now] ;
	if(Cost < 0) return 0 ;
	return Search(Start, Next[Now], Cost) ;
}
int main(){
	freopen("travel.in", "r", stdin) ;
	freopen("travel.out", "w", stdout) ;
	N = Read(), C = Read() ;
	LL TePan = C ; 
	for(LL i = 1; i <= N; i ++){
		A[i] = Read() ;
		Next[i] = i + 1 ;
	}
	for(LL i = 1; i <= N; i ++){
		B[i] = Read() ;
		V[i] = A[i] - B[i] ;
	}
	Next[N] = 1 ; int Tepan = 0 ;
	for(LL i = 1; i <= N; i ++)
		TePan += V[i] ;
	if(Tepan < 0 || C < 0){puts("0") ; return 0 ; }
	for(int i = 1; i <= N; i ++){
		int Now = C ; Ken = 0 ;
		int k = Search(i, i, Now) ;
		Ans += k ;
		if(k) Flag[i] = 1 ;
	}
	printf("%d\n", Ans) ;
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}

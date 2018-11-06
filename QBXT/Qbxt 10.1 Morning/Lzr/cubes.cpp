#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define Inf 0x7fffffff
#define LL long long
using namespace std ;
static int Read(){
	int X = 0 ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
} 
int N, M, F[MAXN], Num[MAXN] ;
int Up[MAXN], Down[MAXN] ;
static int Find(int Now){
	if(Now == F[Now]) return Now ;
	else return F[Now] = Find(F[Now]) ;
}
inline void Union(int X, int Y){
	int R1 = Find(X) ;
	int R2 = Find(Y) ;
	if(R1 != R2) F[R2] = R1 ;
}
int main(){
	M = Read() ;
	for(int i = 1; i <= 30000; i ++){
		F[i] = i, Num[i] = 0 ;
		Up[i] = Down[i] = i ;
	}
	for(int i = 1; i <= M; i ++){
		char Opt ; cin >> Opt ;
		if(Opt == 'M'){
			int X = Read(), Y = Read() ;
			if(Find(X) == Find(Y)) continue ;
			Union(X, Y) ;
			Num[Down[X]] += Num[Up[X]] + 1 ;
			Down[X] = Down[Y] ;
			Up[Y] = Up[X] ;
			
		}	else{
			int X = Read() ;
			printf("%d\n", Num[X]) ;
		}
	}
}

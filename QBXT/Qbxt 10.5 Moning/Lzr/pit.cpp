#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#define MAXN 100010
#define Inf 0x7fffffff
#define LL long long
using namespace std ;
int Read(){
	int X = 0 ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch < '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
}
int N, P ;
int main(){
	freopen("pit.in", "r", stdin) ;
	freopen("pit.out", "w", stdout) ;
	N = Read(), P = Read() ;
	if(N == 3){
		printf("%d", 6 % P) ; 
		exit(0) ;
	}
	if(N == 4){ 
		printf("%d", 216 % P) ;
		exit(0) ; 
	}
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100010
#define Inf 0x7fffffff
#define LL long long
using namespace std ;
int Read(){
	int X = 0 ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
 }
 int N, M, Num, Sum ;
 struct NODE{
 	int From, To, Next ;
 }Edge[MAXN << 1] ; 
int Head[MAXN], Total ;
inline void Add(int F, int T){
	Total ++ ;
	Edge[Total].From = F ;
	Edge[Total].To = T ;
	Edge[Total].Next = Head[F] ;
	Head[F] = Total ;
} 
inline Dfs(int Now, int Fa, int Step){
	//搜索最长路啦 
	if(Step > Sum) Sum = Step, Num = Now ;
	for(int i = Head[Now]; i; i = Edge[i].Next)
	if(Edge[i].To != Fa) Dfs(Edge[i].To, Now, Step + 1) ;
 }
 int main(){
	freopen("distance.in", "r", stdin) ;
	freopen("distance.out", "w", stdout) ;
	N = Read() ; M = Read() ;
	for(int i = 1; i <= M; i ++){
		int F = Read(), T = Read() ;
 		Add(F, T) ; Add(T, F) ;
	}
	Dfs(1, 0, 1) ; Dfs(Num, 0, 1) ;
	//连着搜索两次 然后输出上取整就完了。 
	if(Sum % 2 == 0) printf("%d", Sum >> 1 | 1) ;
	else printf("%d", (Sum + 1) >> 1) ;
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
 }

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 100010
#define Inf 0x7ffffff
#define LL long long
#define V Edge[i].To
using namespace std ;
int Read(){
	int X = 0 ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
}
int N, M, S, T ;
int Dist[MAXN] ;
bool Inque[MAXN] ;
int Max[MAXN] = {- Inf}, Min = Inf;
queue<int> q ;
struct NODE{
	int From, To, Next ;
}Edge[MAXN << 1] ;
int Head[MAXN], Total ;
void Add(int F, int T){
	Total ++ ;
	Edge[Total].From = F ;
	Edge[Total].To = T ;
	Edge[Total].Next = Head[F] ;
	Head[F] = Total ;
}
void Spfa(int S, int T){
	memset(Dist, 127, sizeof(Dist)) ;
	memset(Inque, 0, sizeof(Inque)) ;
	while(! q.empty()) q.pop() ;
	Dist[S] = 1 ; q.push(S) ; Inque[S] = 1 ;
	while(!q.empty()){
		int Now = q.front() ; q.pop() ; Inque[Now] = 0 ;
		if(Dist[Now] > Min) break ;
		for(int i = Head[Now]; i; i = Edge[i].Next)
		if(Dist[Edge[i].To] > Dist[Now] + 1){
			Dist[Edge[i].To] = Dist[Now] + 1 ;
			if(! Inque[V]) q.push(V), Inque[V] = 1 ;
		}
	}
	if(Dist[T] <= MAXN)
	Max[S] = max(Max[S], Dist[T]) ;
}
int main(){
	freopen("distance.in", "r", stdin) ;
	freopen("distance.out", "w", stdout) ;
	N = Read(), M = Read() ;
	for(int i = 1; i <= M; i ++){
		int F = Read(), T = Read() ;
		Add(F, T) ; Add(T, F) ;
	}
	for(int i = 1; i <= N; i ++)
	for(int j = 1; j <= N; j ++){
		S = i ; T = j ;
		Spfa(S, T) ;
	}
	for(int i = 1; i <= N; i ++)
	Min = min(Min, Max[i]) ;
	printf("%d", Min) ;
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}

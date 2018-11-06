#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
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
int N, M, S, T, F[MAXN], j ;
int Son, Mot ;
struct Node{
	int From, To, Len, Next ;
}Edge[MAXN << 1] ;
bool CMP(Node A, Node B){
	return A.Len < B.Len ;
}
int Find(int Now){    //寻找父亲 
	if(F[Now] == Now) return F[Now] ;
	else return F[Now] = Find(F[Now]) ;
}
void Union(int X, int Y){    //合并（习惯） 
	int R1 = Find(X) ; int R2 = Find(Y) ;
	if(R1 != R2) F[R1] = R2 ;
}
int GCD(int X, int Y){    //化简分子分母用
	if(Y > X) return GCD(Y, X) ;
	if(! Y) return X ;
	return GCD(Y, X % Y) ;
}
int main(){
	N = Read(), M = Read() ;
	for(int i = 1; i <= M; i ++){
		int F = Read(), T = Read(), L = Read() ;
		Edge[i].From = F ;
		Edge[i].To = T ;
		Edge[i].Len = L ;
	}
	S = Read() ; T = Read() ;
	sort(Edge + 1, Edge + M + 1, CMP) ;
	for(int i = 1; i <= M; i ++){
		for(j = 1; j <= N; j ++) F[j] = j ;
		for(j = i; j <= M; j ++){
			Union(Edge[j].From, Edge[j].To) ;
			if(Find(S) == Find(T)) break ;
		}
		if((i == 1) && (Find(S) != Find(T))){
				printf("IMPOSSIBLE") ; return 0 ;
			}	
		if(Find(S) != Find(T)) break ;
		if(Son * Edge[i].Len <= Mot * Edge[j].Len){
			Son = Edge[j].Len ;
			Mot = Edge[i].Len ;
		}
	}
	int T = GCD(Son, Mot) ;
	if(T == Mot)
		printf("%d", Son / Mot) ;
	else printf("%d/%d\n", Son / T, Mot / T) ;
	cout << Son << " " << Mot << " " << T << endl ;
	return 0 ;
}

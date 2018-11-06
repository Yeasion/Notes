#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define MAXN 110
#define MAXK 1010
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
int N, M, K, T ;
struct Node{
	int X, Y, D, F ;
}Edge[MAXK] ;
// 20% O(T(K+ N))
bool Flag[MAXN] ;
pair<int, int> Ans[MAXN] ;
int Map[MAXN][MAXN] ;
int main(){
	freopen("problem.in", "r", stdin) ;
	freopen("problem.out", "w", stdout) ;
	N = Read(), M = Read(), K = Read() ;
	for(int i = 1; i <= K; i ++){
		Edge[i].X = Read() ; Edge[i].Y = Read() ;
		Edge[i].D = Read() ; Edge[i].F = Read() ;
		Map[Edge[i].X][Edge[i].Y] = i ;
		Ans[i].first = Edge[i].X ;
		Ans[i].second = Edge[i].Y ;
	}
	T = Read() ;
	memset(Flag, 1, sizeof(Flag)) ;
	while(T --){
		for(int i = 1; i <= K; i ++){
			// Turn around
			if(Flag[i] && Edge[i].X == 1 && Edge[i].D == 2){
				Edge[i].D = 3 ; continue ;
			}
			else if(Flag[i] && Edge[i].X == N && Edge[i].D == 3){
				Edge[i].D = 2 ; continue ;
			}
			else if(Flag[i] && Edge[i].Y == 1 && Edge[i].D == 0){
				Edge[i].D = 1 ; continue ;
			}
			else if(Flag[i] && Edge[i].Y == N && Edge[i].D == 1){
				Edge[i].D = 0 ; continue ;
			}
			//walk
			else if(Flag[i] && Edge[i].D == 0){
				Map[Edge[i].X][Edge[i].Y] = 0 ;
				Edge[i].Y -- ; 
				Ans[i].first = Edge[i].X ;
				Ans[i].second = Edge[i].Y ;
				if(Map[Edge[i].X][Edge[i].Y]){
					if(Edge[Map[Edge[i].X][Edge[i].Y]].F < Edge[i].F){
						Flag[Map[Edge[i].X][Edge[i].Y]] = 0 ;
						Ans[Map[Edge[i].X][Edge[i].Y]].first = Edge[i].X ;
						Ans[Map[Edge[i].X][Edge[i].Y]].second = Edge[i].Y ;
						Map[Edge[i].X][Edge[i].Y] = i ;
					}	else Flag[i] = 0 ;
				}
				else Map[Edge[i].X][Edge[i].Y] = i ;
				continue ;
			}
			else if(Flag[i] && Edge[i].D == 1){
				Map[Edge[i].X][Edge[i].Y] = 0 ;
				Edge[i].Y ++ ;
				Ans[i].first = Edge[i].X ;
				Ans[i].second = Edge[i].Y ;
				if(Map[Edge[i].X][Edge[i].Y]){
					if(Edge[Map[Edge[i].X][Edge[i].Y]].F < Edge[i].F){
						Flag[Map[Edge[i].X][Edge[i].Y]] = 0 ;
						Ans[Map[Edge[i].X][Edge[i].Y]].first = Edge[i].X ;
						Ans[Map[Edge[i].X][Edge[i].Y]].second = Edge[i].Y ;
						Map[Edge[i].X][Edge[i].Y] = i ;
						
					}	else Flag[i] = 0 ;
				}
				else Map[Edge[i].X][Edge[i].Y] = i ;
				continue ;
			}
			else if(Flag[i] && Edge[i].D == 2){
				Map[Edge[i].X][Edge[i].Y] = 0 ;
				Edge[i].X -- ;
				Ans[i].first = Edge[i].X ;
				Ans[i].second = Edge[i].Y ;
				if(Map[Edge[i].X][Edge[i].Y]){
					if(Edge[Map[Edge[i].X][Edge[i].Y]].F < Edge[i].F){
						Flag[Map[Edge[i].X][Edge[i].Y]] = 0 ;
						Ans[Map[Edge[i].X][Edge[i].Y]].first = Edge[i].X ;
						Ans[Map[Edge[i].X][Edge[i].Y]].second = Edge[i].Y ;
						Map[Edge[i].X][Edge[i].Y] = i ;
						
					}	else Flag[i] = 0 ;
				}
				else Map[Edge[i].X][Edge[i].Y] = i ;
				continue ;
			}
			else if(Flag[i] && Edge[i].D == 3){
				Map[Edge[i].X][Edge[i].Y] = 0 ;
				Edge[i].X ++ ; 
				Ans[i].first = Edge[i].X ;
				Ans[i].second = Edge[i].Y ;
				if(Map[Edge[i].X][Edge[i].Y]){
					if(Edge[Map[Edge[i].X][Edge[i].Y]].F < Edge[i].F){
						Flag[Map[Edge[i].X][Edge[i].Y]] = 0 ;
						Ans[Map[Edge[i].X][Edge[i].Y]].first = Edge[i].X ;
						Ans[Map[Edge[i].X][Edge[i].Y]].second = Edge[i].Y ;
						Map[Edge[i].X][Edge[i].Y] = i ;
						
					}	else Flag[i] = 0 ;
				}
				else Map[Edge[i].X][Edge[i].Y] = i ;
				continue ;
			}
		}
	}
	for(int i = 1; i <= K; i ++)
	printf("%d %d\n", Ans[i].second, Ans[i].first) ;
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}

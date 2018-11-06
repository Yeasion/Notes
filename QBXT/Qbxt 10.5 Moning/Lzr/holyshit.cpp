#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
#define Inf 0x7fffffff
#define Len1 (R - L + 1)
#define Len2 (R2 - L2 + 1) 
#define LL long long
using namespace std ;
int Read(){
	int X = 0 ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
}
int N, Data[MAXN], Many[MAXN], Ans = -Inf ;
void Doit(int L, int R){
	bool Can = 1 ;
		memset(Many, 0, sizeof(Many)) ;
		int Ken[MAXN] ;
		for(int i = L; i <= R; i ++){
			Many[Data[i]] ++ ;
			Ken[Data[i]] = Many[Data[i]] ;
			if(Many[Data[i]] > 1){
				Can = 0 ;
				break ;
				}
			}
			if(! Can) return ;
			for(int L2 = 1; L2 <= L - 1; L2 ++){
				Can = 1 ;
				for(int i = 1; i <= N; i ++)
					Many[Data[i]] = Ken[Data[i]] ;
				for(int R2 = L2; R2 <= L - 1; L2 ++){
					Can = 1 ;
					for(int i = 1; i <= N; i ++)
						Many[Data[i]] = Ken[Data[i]] ;
					for(int i = L2; i <= R2; i ++){
						Many[Data[i]] ++ ;
						if(Many[Data[i]] > 1){
							Can = 0 ;
							break ;
						}
					}
					if(Can) Ans = max(Ans, Len1 + Len2) ;
				}
			}
			for(int i = L; i <= R; i ++)
			Many[Data[i]] = Ken[Data[i]] ;
			Can = 1;
			for(int L2 = R + 1; L2 <= N; L2 ++){
				Can = 1 ;
				for(int i = 1; i <= N; i ++)
					Many[Data[i]] = Ken[Data[i]] ;
				for(int R2 = L2; R2 <= N; R2 ++){
					Can = 1 ;
					for(int i = 1; i <= N; i ++)
						Many[Data[i]] = Ken[Data[i]] ;
					for(int i = L2; i <= R2; i ++){
						Many[Data[i]] ++ ;
						if(Many[Data[i]] > 1){
							Can = 0 ;
							break ;
						}
					}
					if(Can) Ans = max(Ans, Len1 + Len2) ;
				}
			}		
}

int main(){
	freopen("holyshit.in", "r", stdin) ;
	freopen("holyshit.out", "w", stdout) ;
	N = Read() ;
	for(int L = 1; L <= N; L ++)
		for(int R = L; R <= N; R ++)
			Doit(L, R) ;
	printf("%d", Ans) ; return 0 ;
}

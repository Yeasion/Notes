# 10.2 Morning 题解报告

标签（空格分隔）： Test

---
### $Problme$ $A$ : $distance$
>给你一个有n个点，m条边的无向图$G = (V, E)$，满足此图中不存在长度大于等于$3$的环，且没有重边自环。给定两个点$u,v$的距离$d(u, v)$为两点之间最短路的点数。求
$min_{u\in{V}}max_{v\in{V}}d(u, v)$。

嗯，我们首先可以很显然地从没有大于等于三的环看出这确实是一个树。然后我们去理解$min_{u\in{V}}max_{v\in{V}}d(u, v)$的意思。其实也就是说我们现在有一个最短路的函数为$d(u,v)$表示$u$到$v$之间的最短路。然后对于一个给定的$u$节点，我们要找到一个$v$使得这个$d(u, v)$最大，那么我们假定上面这个函数为F[u]，然后再把固定的u变成变量，然后求最小值，就是这个玩意。而我们发现这实际上也就是要我们求关于这个树的直径的一些东西。然后我们画几个图稍加证明便可以得到答案就是数的直径$*2$的上取整。那么求树的直径就比较简单了，也就是随便选一个点，跑两遍最长路就完了。在树上也就是两个$BFS$，比较懒的写$SPFA$就好了。
```cpp
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
```

### $Problem$ $B$ : sweet（[Link](https://www.luogu.org/problemnew/show/P2502)）
>求一个$n$点$m$边的带权无向图上的一个由$S$到$T$的路径使该路径上的最大权值边上的权值与最小权值边的权值的比值最小。

这个题的边数m还是比较少的，只有5000左右。所以我们考虑将所有的边$V$按照权值$w$排序。到$V_{1}$、$V_{2}$、$V_{3}$、$V_{4}$，然后我们从小到大枚举$S$到$T$上面的$V_{k}$，然后我们要从$V_{k}$、$V_{k + 1}$...$V_{m}$中找到一条从S到T的最大值最小的路径。
我们现在要在一个加权无向图中求一棵最大值最小的生成树，那么我们想到最小瓶颈路，那么我们已经排完了序，那么我们就直接$Kruskal$就行了。当我们加入某条权值为$V_{Now}$的边的时候发现S和T第一次在一个并查集里面了，那么这个最大值最小的边就是$V_{Now}$。
用$\frac{w(V_{Now})}{w(V_{k})}$。

```cpp

```

### $Problem$ $C$
天天爱跑步（[Link](https://www.luogu.org/problemnew/show/P1600)）

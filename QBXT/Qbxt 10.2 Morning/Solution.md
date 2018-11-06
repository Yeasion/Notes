# 10.2 Morning ��ⱨ��

��ǩ���ո�ָ����� Test

---
### $Problme$ $A$ : $distance$
>����һ����n���㣬m���ߵ�����ͼ$G = (V, E)$�������ͼ�в����ڳ��ȴ��ڵ���$3$�Ļ�����û���ر��Ի�������������$u,v$�ľ���$d(u, v)$Ϊ����֮�����·�ĵ�������
$min_{u\in{V}}max_{v\in{V}}d(u, v)$��

�ţ��������ȿ��Ժ���Ȼ�ش�û�д��ڵ������Ļ�������ȷʵ��һ������Ȼ������ȥ���$min_{u\in{V}}max_{v\in{V}}d(u, v)$����˼����ʵҲ����˵����������һ�����·�ĺ���Ϊ$d(u,v)$��ʾ$u$��$v$֮������·��Ȼ�����һ��������$u$�ڵ㣬����Ҫ�ҵ�һ��$v$ʹ�����$d(u, v)$�����ô���Ǽٶ������������ΪF[u]��Ȼ���ٰѹ̶���u��ɱ�����Ȼ������Сֵ������������⡣�����Ƿ�����ʵ����Ҳ����Ҫ����������������ֱ����һЩ������Ȼ�����ǻ�����ͼ�Լ�֤������Եõ��𰸾�������ֱ��$*2$����ȡ������ô������ֱ���ͱȽϼ��ˣ�Ҳ�������ѡһ���㣬�������·�����ˡ�������Ҳ��������$BFS$���Ƚ�����д$SPFA$�ͺ��ˡ�
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
	//�����·�� 
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
	//������������ Ȼ�������ȡ�������ˡ� 
	if(Sum % 2 == 0) printf("%d", Sum >> 1 | 1) ;
	else printf("%d", (Sum + 1) >> 1) ;
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
 }
```

### $Problem$ $B$ : sweet��[Link](https://www.luogu.org/problemnew/show/P2502)��
>��һ��$n$��$m$�ߵĴ�Ȩ����ͼ�ϵ�һ����$S$��$T$��·��ʹ��·���ϵ����Ȩֵ���ϵ�Ȩֵ����СȨֵ�ߵ�Ȩֵ�ı�ֵ��С��

�����ı���m���ǱȽ��ٵģ�ֻ��5000���ҡ��������ǿ��ǽ����еı�$V$����Ȩֵ$w$���򡣵�$V_{1}$��$V_{2}$��$V_{3}$��$V_{4}$��Ȼ�����Ǵ�С����ö��$S$��$T$�����$V_{k}$��Ȼ������Ҫ��$V_{k}$��$V_{k + 1}$...$V_{m}$���ҵ�һ����S��T�����ֵ��С��·����
��������Ҫ��һ����Ȩ����ͼ����һ�����ֵ��С������������ô�����뵽��Сƿ��·����ô�����Ѿ�����������ô���Ǿ�ֱ��$Kruskal$�����ˡ������Ǽ���ĳ��ȨֵΪ$V_{Now}$�ıߵ�ʱ����S��T��һ����һ�����鼯�����ˣ���ô������ֵ��С�ı߾���$V_{Now}$��
��$\frac{w(V_{Now})}{w(V_{k})}$��

```cpp

```

### $Problem$ $C$
���찮�ܲ���[Link](https://www.luogu.org/problemnew/show/P1600)��

# 10.4 Morning

标签（空格分隔）： Test

---
### $T1$ $:$ $r$
>给一个数据组数T以及T组形如1926-08-17的日期，如果这个日期和1926-08-17的差值为质数或者0，输出"Niubi"，否则输出"Haixing"。

（这个题一看就不可做） 模拟。完了。
总之呢，方法其一就是将两个日期中比较小的置为操作日期。然后就把较小的日期一步一步加到大的日期上面去。
```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100010
#define Inf 0x7fffff
#define LL long long
using namespace std ;
int Read(){
	int X = 0 ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
}
int Is_Prime(int Now){
	if(Now == 0) return true ;
	if(Now == 1) return false ;
	if(Now == 2) return true ;
	for(int i = 2; i * i <= Now; i ++)
		if(Now % i == 0) return false ;
	return true ;
}
int Get_Day(int Now, int Y){
	if(Now == 1) return 31 ;
	if(Now == 3) return 31 ; if(Now == 4) return 30 ;
	if(Now == 5) return 31 ; if(Now == 6) return 30 ;
	if(Now == 7) return 31 ; if(Now == 8) return 31 ;
	if(Now == 9) return 30 ; if(Now == 10) return 31 ;
	if(Now == 11) return 30 ; if(Now == 12) return 31 ;
	if(Y % 4 != 0) return 28 ;
	if(Y % 100 == 0 && Y % 400 != 0)
		return 28 ;
	return 29 ;
}
int T, Year, Month, Day ;
char Opt ; int Cnt ;
int main(){
	T = Read() ;
	while(T --){
		Cnt = 0 ;
		scanf("%d-%d-%d", & Year, & Month, & Day) ;
		int GreatY = 1926 ;
		int GreatM = 8 ;
		int GreatD = 17 ;
		if(Year > GreatY || (Year == GreatY && Month > GreatM) || (Year == GreatY && Month == GreatM && Day > GreatD))
			swap(Year, GreatY), swap(Month, GreatM), swap(Day, GreatD) ;
		while(Year < GreatY || Month < GreatM || Day < GreatD){
			Cnt ++ ; Day ++ ;
			if(Day > Get_Day(Month, Year))
				Day = 1, Month ++ ;
			if(Month > 12)
				Month = 1; Year ++ ;
		}
		cout << Cnt << " " ;
		if(Is_Prime(Cnt)) puts("Niubi") ;
		else puts("Haixing") ;
	}
	return 0 ;
}
```

### $T2$ $:$ $q$
> 给定一个大小为2N的圈子，其中有N对人是基佬，要求任意两个基佬的位置不相邻，求方案数。

我们可以很快知道对于一个有N个人的圈子可以有的排列顺序为$N!$，然后现在还有一些是可以经过令挖一些排序转转圈得来的，那么我们推算可以得到有重复的圈子种数是$2N!$，然后没有重复段圈子总类数就是$(2N - 1) !$。那么我们想要从总的圈子种数里面减去一些不合法的种类。那么我们首先考虑至少有一对基佬坐在一起的情况。那么我们可以将这一对基佬看成一个，那么就剩下了$(2N - 1)$个人，那么情况就有$(2N - 2)!$种，然后这两个基佬可以互换位置，那么就是$2 * (2 * N - 2)!$种。
那么我们现在初步考虑的总方程好像是这样的：
$\sum_{i = 0} ^ {N} C_{N}^{i} 2 ^ {i}\times(2 * N -  i - 1)!$种。但是我们要明白一个重复删减的问题。当我们考虑$[V1,V2]$坐在一起的情况的时候，并没有限制其他人。那么假如在这里有一种情况是$[E1, E2]$也坐在了一起，那么当我们枚举到了$[E1, E2]$坐在一起的时候，也会出现一种$[V1, V2]$也坐在一起的情况。而事实上，这两种情况是一样的，但是我们删减了两遍。所以我们要再加上一遍这个情况。其实这个也就是容斥原理。那么最后我们可以得出总方程为：
> $\sum_{i = 0} ^ {N} C_{N}^{i} \times 2 ^ {i} \times (2 \times N - i - 1)! \times (-1) ^ {i}$

其中$C_{N}^{i}$是从中选出i个数有多少种方案。最后的-1就是为了加上多减的哪些方案数。然后关于组合数的递推式子是这样的：$C_{N}^{i} = C_{N}^{i - 1} * \frac{N - i}{i}$，当然，在这之中还要用到逆元。
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define Inf 0x7fffffff
#define LL long long
#define Mod 10000007
using namespace std ;
int Read(){
	int X = 0 ; char ch = getchar() ;
	while(ch > '9' || ch < '0') ch = getchar() ;
	while(ch >= '0' && ch <= '9')
	X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar() ;
	return X ;
}
int N, Ans ;
int Times(int A, int B){
	int Ans = 1 ;
	while(B){
		if(B % 2 == 1) Ans = Ans * A % Mod ;
		A = A * A % Mod ;
		B >>= 1 ;
	}
	return Ans ;
}
int main(){
	N = Read() ;
	if(N == 1){
		puts("0") ; return 0 ;
	}
	int Erh = 1, Cnh = 1, Nh2 = 1 ;
	for(int i = 1; i <= 2 * N - 1; i ++)
		Nh2 *= i ;
	for(int i = 1; i <= N; i ++){
		int A = Erh * Cnh % Mod * Nh2 % Mod ;
		if(A % 2 == 1) Ans -= A ;
		else Ans += A ; Ans %= Mod ;
		if(i == N) break ; Erh <<= 1 ;
		if(Erh >= Mod) Erh -= Mod ;
		Cnh = Cnh * (N - i) % Mod * Times(i + 1, Mod - 2) % Mod ;
		Nh2 = Nh2 * Times(2 * N - i - 1, Mod - 2) % Mod ;		
	}
	printf("%d\n", Ans) ; return 0 ;
}
```

### $T3$ $:$ $y$
> 给定两个长度分别为$N$, $M$的$S_{1}$和$S_{2}$的$01$串,下面有$K$个操作分为两类：
1. 询问$S_{2}$在$S_{1}$的区间为$[L,R]$的子串中出现了几次。（可重叠）。
2. 将$S_{1}$的$[L,R]$区间的$0$，$1$互换。

某线段树。嗯。
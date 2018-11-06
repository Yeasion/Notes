# 10.4 Morning

��ǩ���ո�ָ����� Test

---
### $T1$ $:$ $r$
>��һ����������T�Լ�T������1926-08-17�����ڣ����������ں�1926-08-17�Ĳ�ֵΪ��������0�����"Niubi"���������"Haixing"��

�������һ���Ͳ������� ģ�⡣���ˡ�
��֮�أ�������һ���ǽ����������бȽ�С����Ϊ�������ڡ�Ȼ��Ͱѽ�С������һ��һ���ӵ������������ȥ��
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
> ����һ����СΪ2N��Ȧ�ӣ�������N�����ǻ��У�Ҫ�������������е�λ�ò����ڣ��󷽰�����

���ǿ��Ժܿ�֪������һ����N���˵�Ȧ�ӿ����е�����˳��Ϊ$N!$��Ȼ�����ڻ���һЩ�ǿ��Ծ�������һЩ����תתȦ�����ģ���ô����������Եõ����ظ���Ȧ��������$2N!$��Ȼ��û���ظ���Ȧ������������$(2N - 1) !$����ô������Ҫ���ܵ�Ȧ�����������ȥһЩ���Ϸ������ࡣ��ô�������ȿ���������һ�Ի�������һ����������ô���ǿ��Խ���һ�Ի��п���һ������ô��ʣ����$(2N - 1)$���ˣ���ô�������$(2N - 2)!$�֣�Ȼ�����������п��Ի���λ�ã���ô����$2 * (2 * N - 2)!$�֡�
��ô�������ڳ������ǵ��ܷ��̺����������ģ�
$\sum_{i = 0} ^ {N} C_{N}^{i} 2 ^ {i}\times(2 * N -  i - 1)!$�֡���������Ҫ����һ���ظ�ɾ�������⡣�����ǿ���$[V1,V2]$����һ��������ʱ�򣬲�û�����������ˡ���ô������������һ�������$[E1, E2]$Ҳ������һ����ô������ö�ٵ���$[E1, E2]$����һ���ʱ��Ҳ�����һ��$[V1, V2]$Ҳ����һ������������ʵ�ϣ������������һ���ģ���������ɾ�������顣��������Ҫ�ټ���һ������������ʵ���Ҳ�����ݳ�ԭ����ô������ǿ��Եó��ܷ���Ϊ��
> $\sum_{i = 0} ^ {N} C_{N}^{i} \times 2 ^ {i} \times (2 \times N - i - 1)! \times (-1) ^ {i}$

����$C_{N}^{i}$�Ǵ���ѡ��i�����ж����ַ���������-1����Ϊ�˼��϶������Щ��������Ȼ�����������ĵ���ʽ���������ģ�$C_{N}^{i} = C_{N}^{i - 1} * \frac{N - i}{i}$����Ȼ������֮�л�Ҫ�õ���Ԫ��
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
> �����������ȷֱ�Ϊ$N$, $M$��$S_{1}$��$S_{2}$��$01$��,������$K$��������Ϊ���ࣺ
1. ѯ��$S_{2}$��$S_{1}$������Ϊ$[L,R]$���Ӵ��г����˼��Ρ������ص�����
2. ��$S_{1}$��$[L,R]$�����$0$��$1$������

ĳ�߶������š�
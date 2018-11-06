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

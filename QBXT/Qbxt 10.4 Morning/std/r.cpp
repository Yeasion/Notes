#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bool prime(int x)
{
	if (!x) return true;
	if (x==1) return false;
	for (int a=2;a*a<=x;a++)
		if (x%a==0) return false;
	return true;
}

int get_day(int y,int m)
{
	if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) return 31;
	if (m==4 || m==6 || m==9 || m==11) return 30;
	if (y%4!=0 || (y%100==0 && y%400!=0)) return 28;
	else return 29;
}

void work(int y1,int m1,int d1)
{
	int y2=1926,m2=8,d2=17;
	if (y2<y1 || (y2==y1 && m2<m1) || (y2==y1 && m2==m1 && d2<d1))
	{
		swap(y1,y2);
		swap(m1,m2);
		swap(d1,d2);
	}
	int cnt=0;
	while (y1<y2 || m1<m2 || d1<d2)
	{
		cnt++;
		d1++;
		if (d1>get_day(y1,m1))
		{
			d1=1;
			m1++;
		}
		if (m1>12)
		{
			m1=1;
			y1++;
		}
	}
	if (prime(cnt)) printf("Niubi\n");
	else printf("Haixing\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	for (;t--;)
	{
		int year,month,day;
		scanf("%d-%d-%d",&year,&month,&day);
		work(year,month,day);
	}

	return 0;
}

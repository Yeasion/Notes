#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int mo=1000000007;

int n;

int mul(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=(long long)ans*a%mo;
		a=(long long)a*a%mo;
		b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	if (n==1)
	{
		printf("0\n");
		return 0;
	}

	int erh=1;
	int cnh = 1;
	int nh2 = 1;
	for (int a=1;a<=2*n-1;a++)
		nh2 = (long long)nh2*a%mo;

	int ans=0;
	for (int a=0;a<=n;a++)
	{
		int v=(long long)erh * cnh % mo * nh2 % mo;
		if (a&1) ans=ans-v;
		else ans = ans+v;
		if (ans>=mo) ans-=mo;
		if (ans<0) ans+=mo;
		if (a==n) break;
		erh <<= 1;
		if (erh>=mo) erh -= mo;
		cnh = (long long)cnh * (n-a) % mo * mul(a+1,mo-2) % mo;
		nh2 = (long long)nh2 * mul(2*n-a-1,mo-2) % mo;
	}
	printf("%d\n",ans);

	return 0;
}

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=110;
const int maxk=1010;

int n,m,k,x[maxk],y[maxk],d[maxk],f[maxk],z[maxk],t;

bool alive[maxk];

int dx[4],dy[4];

void move(int p)
{
	x[p] += dx[d[p]];
	y[p] += dy[d[p]];
	if (x[p]<1 || x[p]>n || y[p]<1 || y[p]>m)
	{
		x[p] -= dx[d[p]];
		y[p] -= dy[d[p]];
		d[p] ^= 1;
	}
}

bool cmp(int a,int b)
{
	if (x[a]!=x[b]) return x[a]<x[b];
	else return y[a]<y[b];
}

int main()
{
	dx[0]=-1;dx[1]=1;dy[2]=-1;dy[3]=1;
	scanf("%d%d%d",&n,&m,&k);
	for (int a=1;a<=k;a++)
		scanf("%d%d%d%d",&x[a],&y[a],&d[a],&f[a]);
	for (int a=1;a<=k;a++)
	{
		alive[a]=true;
		z[a]=a;
	}
	scanf("%d",&t);

	for (;t--;)
	{
		for (int a=1;a<=k;a++)
			if (alive[a]) move(a);
		sort(z+1,z+k+1,cmp);

		for (int a=1;a<=k;)
		{
			int b=a,p=-1;
			while (x[z[b]]==x[z[a]] && y[z[b]]==y[z[a]] && b<=k)
			{
				if (alive[z[b]] && (p==-1 || f[z[b]]>f[z[p]])) p=b;
				b++;
			}
			for (int c=a;c<b;c++)
				if (p!=-1 && c!=p) alive[z[c]]=false;
			a=b;
		}
	}
	for (int a=1;a<=k;a++)
		printf("%d %d\n",x[a],y[a]);

	return 0;
}

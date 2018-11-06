#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

#define inc(a,b) {a+=b;if (a>=mo) a-=mo;}

const int mo=12345;

int s,cnt,num,multi[30],c,pos[30];

long long n;

char st[3];

vector<int> status[125],nowway,v[30];

map< vector <int> , int > id;

int m1[125][125],m2[125][125],m3[125][125];

void dfs(int now)
{
	if (now==cnt)
	{
		num++;
		status[num]=nowway;
		id[nowway]=num;
	}
	else
	{
		for (int a=0;a<multi[now];a++)
		{
			nowway.push_back(a);
			dfs(now+1);
			nowway.pop_back();
		}
	}
}

int gcd(int a,int b)
{
	if (a % b==0) return b;
	else return gcd(b,a % b);
}

int main()
{
	cin>>n;
	scanf("%d",&c);
	for (int a=1;a<=c;a++)
	{
		scanf("%s",st);
		int nowv;
		scanf("%d",&nowv);
		v[st[0]-'A'+1].push_back(nowv);
	}
	s=1;
	for (int a=1;a<=26;a++)
		if (v[a].size())
		{
			sort(v[a].begin(),v[a].end());
			v[a].resize(unique(v[a].begin(),v[a].end())-v[a].begin());
			int size=0;
			for (int b=0;b<(int)v[a].size();b++)
			{
				bool able=true;
				for (int c=0;c<b;c++)
					if (v[a][b]%v[a][c]==0) able=false;
				if (able)
				{
					v[a][size]=v[a][b];
					size++;
				}
			}
			v[a].resize(size);
			if (v[a].back()==1) continue;
			int lcm=1;
			for (int b=0;b<(int)v[a].size();b++)
				lcm=lcm*v[a][b]/gcd(v[a][b],lcm);
			s*=lcm;
			multi[cnt]=lcm;
			pos[a]=cnt;
			cnt++;
		}
	dfs(0);
	for (int a=1;a<=num;a++)
	{
		nowway=status[a];
		for (int b=1;b<=26;b++)
			if (v[b].size())
			{
				if (v[b].back()==1) m1[a][a]++;
				else
				{
					nowway[pos[b]]++;
					nowway[pos[b]]%=multi[pos[b]];
					int idx=id[nowway];
					m1[a][idx]++;
					nowway[pos[b]]+=multi[pos[b]]-1;
					nowway[pos[b]]%=multi[pos[b]];
				}
			}
	}
	m2[1][1]=1;
	while (n)
	{
		if (n&1)
		{
			memset(m3,0,sizeof(m3));
			for (int a=1;a<=s;a++)
			   for (int b=1;b<=s;b++)
				   for (int c=1;c<=s;c++)
					   inc(m3[a][c],m2[a][b]*m1[b][c]%mo);
			for (int a=1;a<=s;a++)
				for (int b=1;b<=s;b++)
					m2[a][b]=m3[a][b];
		}
		memset(m3,0,sizeof(m3));
		for (int a=1;a<=s;a++)
			for (int b=1;b<=s;b++)
				for (int c=1;c<=s;c++)
					inc(m3[a][c],m1[a][b]*m1[b][c]%mo);
		for (int a=1;a<=s;a++)
			for (int b=1;b<=s;b++)
				m1[a][b]=m3[a][b];
		n>>=1;
	}
	int ans=0;
	for (int a=1;a<=num;a++)
	{
		nowway=status[a];
		bool able=true;
		for (int b=1;b<=26;b++)
			if (v[b].size())
			{
				if (v[b].back()==1) continue;
				bool fail=true;
				for (int c=0;c<(int)v[b].size();c++)
					if (nowway[pos[b]]%v[b][c]==0)
					{
						fail=false;
						break;
					}
				if (fail)
				{
					able=false;
					break;
				}
			}
		if (able) ans=(ans+m2[1][a])%mo;
	}
	printf("%d\n",ans);

	return 0;
}


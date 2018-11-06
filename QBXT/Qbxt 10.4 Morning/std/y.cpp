#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn=100010;
const int maxm=25;

int n,m,k,v,inv,up;

char s1[maxn],s2[maxm];

struct node
{
	int pre[maxm],suf[maxm];
	int ans,invans;
	bool rev;

	node()
	{
		memset(pre,-1,sizeof(pre));
		memset(suf,-1,sizeof(suf));
		rev = false;
		ans=invans=0;
	}
}z[maxn<<2|1];

node operator+(const node &l,const node &r)
{
	node c;
	for (int a=1;a<m;a++)
		if (l.pre[a] == -1)
		{
			a--;
			for (int b=1;a+b<m;b++)
				if (r.pre[b]!=-1) c.pre[a+b] = (l.pre[a]<<b)|r.pre[b];
				else break;
			break;
		}
		else c.pre[a] = l.pre[a];



	for (int a=1;a<m;a++)
		if (r.suf[a] == -1)
		{
			a--;
			for (int b=1;a+b<m;b++)
				if (l.suf[b]!=-1) c.suf[a+b] = (l.suf[b]<<a)|r.suf[a];
				else break;
			break;
		}
		else c.suf[a] = r.suf[a];

	c.ans = l.ans+r.ans;
	for (int a=1;a<m;a++)
		if (l.suf[a]!=-1 && r.pre[m-a]!=-1 && ((l.suf[a]<<(m-a))|r.pre[m-a])==v) c.ans++;

	c.invans = l.invans+r.invans;
	for (int a=1;a<m;a++)
		if (l.suf[a]!=-1 && r.pre[m-a]!=-1 && ((l.suf[a]<<(m-a))|r.pre[m-a])==inv) c.invans++;

	return c;
}

void update(int rt)
{
	z[rt] = z[rt<<1] + z[rt<<1|1];
}

void color(int rt)
{
	z[rt].rev ^= true;
	swap(z[rt].ans,z[rt].invans);
	for (int a=1;a<m;a++)
	{
		if (z[rt].suf[a]!=-1) z[rt].suf[a]^=(1<<a)-1;
		if (z[rt].pre[a]!=-1) z[rt].pre[a]^=(1<<a)-1;
	}
}

void push_col(int rt)
{
	if (z[rt].rev)
	{
		color(rt<<1);
		color(rt<<1|1);
		z[rt].rev=false;
	}
}

void build(int l,int r,int rt)
{
	if (l==r)
	{
		if (m==1)
		{
			if (s1[l]==v) z[rt].ans=1;
			else z[rt].invans=1;
		}
		z[rt].pre[1]=z[rt].suf[1]=s1[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(rt);
}

node query(int l,int r,int rt,int nowl,int nowr)
{
	if (nowl<=l && r<=nowr) return z[rt];
	push_col(rt);
	int m=(l+r)>>1;
	if (nowl<=m)
	{
		if (m<nowr) return query(lson,nowl,nowr)+query(rson,nowl,nowr);
		else return query(lson,nowl,nowr);
	}
	else return query(rson,nowl,nowr);
}

void modify(int l,int r,int rt,int nowl,int nowr)
{
	if (nowl<=l && r<=nowr)
	{
		color(rt);
		return;
	}
	push_col(rt);
	int m=(l+r)>>1;
	if (nowl<=m) modify(lson,nowl,nowr);
	if (m<nowr) modify(rson,nowl,nowr);
	update(rt);
}

int main()
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	for (int a=1;a<=n;a++)
		s1[a]-='0';
	for (int a=1;a<=m;a++)
		s2[a]-='0';
	for (int a=1;a<=m;a++)
		v=v<<1|s2[a];
	up = (1<<m)-1;
	inv = v^up;
	build(root);
	scanf("%d",&k);
	for (int a=1;a<=k;a++)
	{
		int opt,l,r;
		scanf("%d%d%d",&opt,&l,&r);
		if (opt==1) printf("%d\n",query(root,l,r).ans);
		else modify(root,l,r);
	}

	return 0;
}

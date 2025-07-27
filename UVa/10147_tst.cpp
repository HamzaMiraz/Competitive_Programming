#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int smap[755][755];

typedef struct p_node
{
	int xx,yy;
}point;
point p[755];

int dist(point a, point b)
{
	return (a.xx-b.xx)*(a.xx-b.xx)+(a.yy-b.yy)*(a.yy-b.yy);
}

typedef struct d_node
{
	int	point1;
	int	point2;
	int	weight;
}enode;
enode edge[565000];

//union_set
int par[755];
int rnk[755];

void set_inital(int a, int b)
{
	for (int i = a; i <= b; ++ i) {
		rnk[i] = 0;
		par[i] = i;
	}
}

int  findset(int a)
{
	if (a != par[a])
		par[a] = findset(par[a]);
	return par[a];
}

void makelink(int a, int b)
{
	if (rnk[a] < rnk[b])
		par[a] = b;
	else {
		if (rnk[a] == rnk[b])
			rnk[a] ++;
		par[b] = a;
	}
}
//end_union_set

int cmp_e(enode a, enode b)
{
	return a.weight < b.weight;
}

void kruskal(int n)
{
	set_inital(1, n);

	int r = 0,uni = 0;
	for (int i = 1; i <= n; ++ i)
        for (int j = 1; j < i; ++ j)
            if (!smap[i][j]) {
                edge[r].point1 = j;
                edge[r].point2 = i;
                edge[r].weight = dist(p[i], p[j]);
                r ++;
            }else {
                int A = findset(i);
                int B = findset(j);
                if (A != B) {
                    makelink(A, B);
                    uni ++;
                }
            }

	if (uni+1 == n) {
		printf("No new highways need\n");
		return;
	}

	sort(edge, edge+r, cmp_e);
	int add = 0;
	for (int i = 0; i < r; ++ i) {
		int A = findset(edge[i].point1);
		int B = findset(edge[i].point2);
		if (A != B) {
			makelink(A, B);
			printf("%d %d\n",edge[i].point1,edge[i].point2);
			if (uni++ == n-1) {
				printf("No new highways need\n");
				return;
			}
		}
	}
}

int main()
{
	int t,n,m,a,b;
	while (scanf("%d",&t) != EOF)
	while (t --) {
		scanf("%d",&n);
		for (int i = 1 ; i <= n; ++ i)
			scanf("%d%d",&p[i].xx,&p[i].yy);
		scanf("%d",&m);
		memset(smap, 0, sizeof(smap) );
		for (int i = 1 ; i <= m; ++ i) {
			scanf("%d%d",&a,&b);
			smap[a][b] = smap[b][a] = 1;
		}
		kruskal(n);
		if (t) printf("\n");
	}
	return 0;
}

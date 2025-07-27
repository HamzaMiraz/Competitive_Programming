#include<bits/stdc++.h>//Accepted MST problem solving using kruskal algorithm
#define MAXN 101
using namespace std;

struct krus
{
	int u,v;
	double w;
	bool operator < ( const krus& p ) const
	{
		return w < p.w;
	}
};
vector<krus>data;

int Find(int r,int par[])
{
    if(par[r]==r)
    {
        return r;
    }
    else
    {
        par[r]=Find(par[r],par);
        return Find(par[r],par);
    }
}

double mst(int n)
{
    int i,l,u,v,count=1;
    double c=0;
    int par[n+1];
    sort(data.begin(),data.end());

    l=data.size();
    for(i=1;i<=n;i++)
    {
        par[i]=i;
    }
    for(i=0;i<l;i++)
    {
        u=Find(data[i].u , par);
        v=Find(data[i].v , par);
        if(u!=v)
        {
            par[u]=v;
            ++count;
            c+=data[i].w;

            if(count==n)
            {
                break;
            }
        }
    }
    return c;
}

int main()
{
//    freopen("10034.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int i,j,n,T,c=0;
    double x,y,w;
    vector<double>X,Y;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&x,&y);//%lf to scan
            X.push_back(x);
            Y.push_back(y);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                w = (X[j]-X[i])*(X[j]-X[i]) + (Y[j]-Y[i])*(Y[j]-Y[i]);
                w=sqrt(w);

                krus o;
                o.u=i+1,o.v=j+1,o.w=w;
                data.push_back(o);
            }
        }
        if(c>0){printf("\n");}
        c++;

        printf("%.2f\n",mst(n));//%f to print
        X.clear();
        Y.clear();
        data.clear();
    }
    return 0;
}

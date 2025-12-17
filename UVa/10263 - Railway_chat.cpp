#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x,y;
};

// cross product
double cross(Point a,Point b){
    return (a.x*b.y) - (a.y*b.x);
}

// dot product
double dot(Point a,Point b){
    return (a.x*b.x)+(a.y*b.y);
}

// Euclidean distance between two points
double pdis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

// Returns {closest_point, distance}
pair<Point,double> dis(Point M,Point A,Point B){
    Point AM={M.x-A.x,M.y-A.y};
    Point AB={B.x-A.x,B.y-A.y};
    if(dot(AB,AM)<=0){
        return {A,pdis(M,A)};
    }
    Point BM={M.x-B.x,M.y-B.y};
    Point BA={A.x-B.x,A.y-B.y};
    if(dot(BA,BM)<=0){
        return {B,pdis(M,B)};
    }
    double len_AB=sqrt(AB.x*AB.x + AB.y*AB.y); // |AB|
    double dist = fabs(cross(AM,AB)/len_AB);// 1/2(vumi* height)=1/2(A X B)
    // Closest point on segment
    double t = dot(AM,AB)/dot(AB,AB);
    Point Q = {A.x + AB.x*t, A.y + AB.y*t};
    return {Q, dist};
}

void solve(double x, double y, int N){
    Point M={x,y};

    int n = N;
    n++; // number of points
    vector<Point> p(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }

    double mn = 1e18;
    Point bestPoint;
    for(int i=1;i<n;i++){
        Point A = p[i];
        Point B = p[i+1];
        auto res = dis(M,A,B);
        double d = res.second;
        if(d < mn){
            mn = d;
            bestPoint = res.first;
        }
    }

    cout << fixed << setprecision(4) << bestPoint.x << "\n" << bestPoint.y << "\n";
}

int main()
{
    double x, y;
    while(cin>>x>>y)
    {
        int N;
        if(!(cin>>N)) break;
        solve(x,y,N);
    }
    return 0;
}

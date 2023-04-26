#include <bits/stdc++.h>
using namespace std;

class Line{
public:
    int a,b,c;
    Line(int a,int b,int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

class Point{
public:
    int x,y;
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
};

double distance_calc(Point p1, Point p2){
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

double sumOfDist(vector<Point> arr, Line l, double x){
    double ans = 0;
    double y = -1*(l.c+l.a*x)/l.b;
    Point np(x,y);
    for(int i=0;i<arr.size();i++) ans += distance_calc(np,arr[i]);
    return ans;
}

double ternarySearcher(vector<Point> arr, Line l){
    double low = -1e6;
    double high = 1e6;
    
    while((high-low)>1e-6){
        double mid1 = low + (high-low)/3;
        double mid2 = high - (high-low)/3;
        double dist1 = sumOfDist(arr,l,mid1);
        double dist2 = sumOfDist(arr,l,mid2);
        if(dist1<dist2) high = mid2;
        else low = mid1;
    }
    return sumOfDist(arr,l,(high+low)/2);
}

int main(){
    Line line(1,-1,-3);
    int N = 5;
    int points[] = {-3,-2,-1,0,-1,2,1,2,3,4};
    vector<Point> pa;
    for(int i=0;i<2*N;i+=2){
        Point pnt(points[i],points[i+1]);
        pa.push_back(pnt);
    }
    cout<<ternarySearcher(pa,line);
    return 0;
}

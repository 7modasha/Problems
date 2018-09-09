#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <chrono>

using namespace std;

const double EPS = 1e-9;
const double PI = atan2(0, -1);

#define EQ(a, b) (fabs((a) - (b)) <= EPS)
#define NE(a, b) (fabs((a) - (b)) > EPS)
#define LT(a, b) ((a) < (b) - EPS)
#define GT(a, b) ((a) > (b) + EPS)
#define LE(a, b) ((a) <= (b) + EPS)
#define GE(a, b) ((a) >= (b) - EPS)

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

template<typename T>
struct Point{

    T x, y;

    Point() : x(0), y(0){}
    Point(T x, T y) : x(x), y(y){}
    Point(const Point<T> &p) : x(p.x), y(p.y){}
    Point(const pair<T, T> &p) : x(p.first), y(p.second){}

    double distance(const Point<T> &p) const { return hypot(p.x - x, p.y - y); }
    bool operator<(const Point<T> &p) const { return NE(p.x, x) ? LT(x, p.x) : LT(y, p.y); }

    double distanceToLine(const Point<T> &a, const Point<T> &b, bool isSegment) const {

        Point<T> v1 = b - a, v2 = (*this) - a, v3 = (*this) - b;

        if(isSegment){
            if(LE(v1.dot(v2), 0.0)) return distance(a);
            if(GE(v1.dot(v3), 0.0)) return distance(b);
        }

        return fabs(v1.cross(v2)) / v1.length();
    }

    Point<T> scale(double factor, const Point<T> &center) const {
        return center + ((*this)-center)*factor;
    }

    void rotation(double theta){
        T X = x, Y = y;
        x = X * cos(theta) - Y * sin(theta);
        y = X * sin(theta) + Y * cos(theta);
    }

    Point<T> operator-(const Point<T> &p) const { return Point<T>(x - p.x, y - p.y); }
    Point<T> operator+(const Point<T> &p) const { return Point<T>(x + p.x, y + p.y); }

    Point<T>& operator+=(const Point<T> &p){ x += p.x; y += p.y; return *this; }
    Point<T>& operator-=(const Point<T> &p){ x -= p.x; y -= p.y; return *this; }

    //op with a value
    Point<double> operator/(double val) const { return Point<double>(x / val, y / val); }
    Point<T> operator*(T val) const { return Point<T>(x * val, y * val); }
    Point<T> operator+(T val) const { return Point<T>(x + val, y + val); }
    Point<T> operator-(T val) const { return Point<T>(x - val, y - val); }

    Point<double>& operator/=(double val){ x /= val; y /= val; return *this; }
    Point<T>& operator*=(T val){ x *= val; y *= val; return *this; }
    Point<T>& operator+=(T val){ x += val; y += val; return *this; }
    Point<T>& operator-=(T val){ x -= val; y -= val; return *this; }

    T cross(const Point<T> &p) const { return x * p.y - y * p.x; }
    T dot(const Point<T> &p) const { return x * p.x + y * p.y; }

    Point<T> perp() const { return Point<T>(-y, x); }
    double length() const { return sqrt(x * x + y * y); }

    double angle() const {
        double angle = atan2(y, x);
        if(LT(angle, 0.0)) angle += 2.0 * PI;
        return angle;
    }

    friend ostream& operator<<(ostream &out, const Point<T> &p){
        return out << '(' << p.x << ", " << p.y << ')';
    }

    friend istream& operator>>(istream& in, Point<T> &p){
        return in >> p.x >> p.y;
    }
};

//0 collinear, 1 CCW, -1 CW
template<typename T>
int orientation(const Point<T> &a, const Point<T> &b, const Point<T> &c){
    T val = ((b - a).cross(c - a));

    if(EQ(val, 0)) return 0;
    return LT(val, 0) ? -1 : 1;
}

//points must be sorted CCW or CW
template<typename T>
double areaOfPolygon(const vector<Point<T> > &p){

    T ans = 0;
    for(int i = 0; i < p.size(); ++i)
        ans += (p[i].cross(p[(i+1)%p.size()]));

    return fabs(ans / 2.0);
}

//sort points in CCW manner
bool cmp(const Point<int> &a, const Point<int> &b){
    if(EQ(a.cross(b), 0))
        return LT(a.length(), b.length());
    return LT(a.angle(), b.angle());
}

inline Point<double> polarToCar(double r, double theta){
    return Point<double>(r * cos(theta), r * sin(theta));
}

//parametric equation P(t) = p + t * u;
template<typename T>
struct Line{

    Point<T> p, u;
    bool isSegment;

    Line(): isSegment(false){}
    Line(const Point<T> &p0, const Point<T> &p1, bool isSegment)
        : p(p0), u(p1 - p0), isSegment(isSegment){}

    bool isParallel(const Line<T> &l) const {
        Point<T> ut = u.perp(), v = l.u;
        return EQ(ut.dot(v), 0);
    }

    //lines only
    bool operator==(const Line<T> &l) const {
        Point<T> wt = (p - l.p).perp(), v = l.u;
        return isParallel(l) and EQ(wt.dot(v), 0);
    }

    bool operator!=(const Line<T> &l) const { return !(*this == l); }

    //lines and segments only
    bool intersection(const Line<T> &l, Point<double> &res) const {
        if(isParallel(l)) return false;

        Point<T> w = p - l.p, vt = l.u.perp();
        double s = (-1.0 * vt.dot(w)) / (vt.dot(u)); //for this line

        Point<T> ut = u.perp(), v = l.u;
        double t = (1.0 * ut.dot(w)) / ut.dot(v); //for the l line

        if(l.isSegment)
            if(LT(t, 0) or GT(t, 1)) return false;

        if(isSegment)
            if(LT(s, 0) or GT(s, 1)) return false;

        res.x = p.x + s * u.x;
        res.y = p.y + s * u.y;
        return true;
    }

    double distanceToPoint(const Point<T> &p0){
        return p0.distanceToLine(p, p+u, isSegment);
    }
};
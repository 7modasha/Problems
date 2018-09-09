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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const double EPS = 1e-9;
const ld PI = atan2(0, -1);

#define EQ(a, b) (fabs((a) - (b)) <= EPS)
#define NE(a, b) (fabs((a) - (b)) > EPS)
#define LT(a, b) ((a) < (b) - EPS)
#define GT(a, b) ((a) > (b) + EPS)
#define LE(a, b) ((a) <= (b) + EPS)
#define GE(a, b) ((a) >= (b) - EPS)

#define all(x) (x).begin(), (x).end()

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

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << setprecision(12) << fixed;

    Point<double> dummy;
    Point<int> s, e, lt, rb;

    int t;
    cin >> t;
    while(t-- > 0){

        int xleft, xright, ytop, ybottom;
        cin >> s >> e >> xleft >> ytop >> xright >> ybottom;

        if(xleft>xright) swap(xleft,xright);
        if(ybottom>ytop) swap(ybottom,ytop);

        Point<int> lt(xleft, ytop), rb(xright, ybottom), t1(rb.x, lt.y), t2(lt.x, rb.y);

        bool chk1 = EQ(lt.distanceToLine(s, e, true), 0)
                || EQ(t1.distanceToLine(s, e, true), 0)
                || EQ(rb.distanceToLine(s, e, true), 0)
                || EQ(t2.distanceToLine(s, e, true), 0);

        Line<int> l1(lt, t1, true), l2(lt, t2, true), l3(t1, rb, true), l4(t2, rb, true), se(s, e, true);
        bool chk2 = l1.intersection(se, dummy) || l2.intersection(se, dummy) 
                 || l3.intersection(se, dummy) || l4.intersection(se, dummy);

        bool chk3 = lt.x <= s.x and rb.x >= s.x 
                and lt.x <= e.x and rb.x >= e.x
                and rb.y <= s.y and lt.y >= s.y
                and rb.y <= e.y and lt.y >= e.y;

        cout << (chk1 or chk2 or chk3 ? "T": "F") << "\n";
    }

    return 0;
}
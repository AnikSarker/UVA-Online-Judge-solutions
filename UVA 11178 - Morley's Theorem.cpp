#include <bits/stdc++.h>
using namespace std;

#define MAX 105
#define EPS 1e-6

typedef pair<int,int> pii;
const double pi = 4 * atan(1);
const double eps = 1e-6;

inline int dcmp (double x) { if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }
inline double getDistance (double x, double y) { return sqrt(x * x + y * y); }
inline double torad(double deg) { return deg / 180 * pi; }

struct Point {
    double x, y;
    Point (double x = 0, double y = 0): x(x), y(y) {}
    void read () { scanf("%lf%lf", &x, &y); }
    void write () { printf("%lf %lf", x, y); }

    bool operator == (const Point& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
    bool operator != (const Point& u) const { return !(*this == u); }
    bool operator < (const Point& u) const { return dcmp(x - u.x) < 0 || (dcmp(x-u.x)==0 && dcmp(y-u.y) < 0); }
    bool operator > (const Point& u) const { return u < *this; }
    bool operator <= (const Point& u) const { return *this < u || *this == u; }
    bool operator >= (const Point& u) const { return *this > u || *this == u; }
    Point operator + (const Point& u) { return Point(x + u.x, y + u.y); }
    Point operator - (const Point& u) { return Point(x - u.x, y - u.y); }
    Point operator * (const double u) { return Point(x * u, y * u); }
    Point operator / (const double u) { return Point(x / u, y / u); }
    double operator * (const Point& u) { return x*u.y - y*u.x; }
};
typedef Point Vector;
typedef vector<Point> Polygon;

struct Line {
    double a, b, c;
    Line (double a = 0, double b = 0, double c = 0): a(a), b(b), c(c) {}
};

struct DirLine {
    Point p;
    Vector v;
    double ang;
    DirLine () {}
    DirLine (Point p, Vector v): p(p), v(v) { ang = atan2(v.y, v.x); }
    bool operator < (const DirLine& u) const { return ang < u.ang; }
};

struct Circle {
    Point o;
    double r;
    Circle () {}
    Circle (Point o, double r = 0): o(o), r(r) {}
    void read () { o.read(), scanf("%lf", &r); }
    Point point(double rad) { return Point(o.x + cos(rad)*r, o.y + sin(rad)*r); }
    double getArea (double rad) { return rad * r * r / 2; }
};


namespace Punctual {
    double getDistance (Point a, Point b) { double x=a.x-b.x, y=a.y-b.y; return sqrt(x*x + y*y); }
};


namespace Vectorial {
    double getDot (Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
    double getCross (Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
    double getLength (Vector a) { return sqrt(getDot(a, a)); }
    double getPLength (Vector a) { return getDot(a, a); }
    double getAngle (Vector u) { return atan2(u.y, u.x); }
    double getAngle (Vector a, Vector b) { return acos(getDot(a, b) / getLength(a) / getLength(b)); }
    Vector rotate (Vector a, double rad) { return Vector(a.x*cos(rad)-a.y*sin(rad), a.x*sin(rad)+a.y*cos(rad)); }
    Vector getNormal (Vector a) { double l = getLength(a); return Vector(-a.y/l, a.x/l); }
};

namespace ComplexVector {
    typedef complex<double> Point;
    typedef Point Vector;

    double getDot(Vector a, Vector b) { return real(conj(a)*b); }
    double getCross(Vector a, Vector b) { return imag(conj(a)*b); }
    Vector rotate(Vector a, double rad) { return a*exp(Point(0, rad)); }
};

namespace Linear {
    using namespace Vectorial;

    Line getLine (double x1, double y1, double x2, double y2) { return Line(y2-y1, x1-x2, y1*x2-x1*y2); }
    Line getLine (Point a,Point b) { return getLine(a.x,a.y,b.x,b.y); }
    Line getLine (double a, double b, Point u) { return Line(a, -b, u.y * b - u.x * a); }

    bool getIntersection (Line p, Line q, Point& o) {
        if (fabs(p.a * q.b - q.a * p.b) < eps)
            return false;
        o.x = (q.c * p.b - p.c * q.b) / (p.a * q.b - q.a * p.b);
        o.y = (q.c * p.a - p.c * q.a) / (p.b * q.a - q.b * p.a);
        return true;
    }

    bool getIntersection (Point p, Vector v, Point q, Vector w, Point& o) {
        if (dcmp(getCross(v, w)) == 0) return false;
        Vector u = p - q;
        double k = getCross(w, u) / getCross(v, w);
        o = p + v * k;
        return true;
    }

    double getDistanceToLine (Point p, Point a, Point b) { return fabs(getCross(b-a, p-a) / getLength(b-a)); }
    double getDistanceToSegment (Point p, Point a, Point b) {
        if (a == b) return getLength(p-a);
        Vector v1 = b - a, v2 = p - a, v3 = p - b;
        if (dcmp(getDot(v1, v2)) < 0) return getLength(v2);
        else if (dcmp(getDot(v1, v3)) > 0) return getLength(v3);
        else return fabs(getCross(v1, v2) / getLength(v1));
    }

    Point getPointToLine (Point p, Point a, Point b) { Vector v = b-a; return a+v*(getDot(v, p-a) / getDot(v,v)); }

    bool haveIntersection (Point a1, Point a2, Point b1, Point b2) {
        double c1=getCross(a2-a1, b1-a1), c2=getCross(a2-a1, b2-a1), c3=getCross(b2-b1, a1-b1), c4=getCross(b2-b1,a2-b1);
        return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
    }

    bool onSegment (Point p, Point a, Point b) { return dcmp(getCross(a-p, b-p)) == 0 && dcmp(getDot(a-p, b-p)) < 0; }
    bool onLeft(DirLine l, Point p) { return dcmp(l.v * (p-l.p)) >= 0; }
}

namespace Triangular {
    using namespace Vectorial;

    double getAngle (double a, double b, double c) { return acos((a*a+b*b-c*c) / (2*a*b)); }
    double getArea (double a, double b, double c) { double s =(a+b+c)/2; return sqrt(s*(s-a)*(s-b)*(s-c)); }
    double getArea (double a, double h) { return a * h / 2; }
    double getArea (Point a, Point b, Point c) { return fabs(getCross(b - a, c - a)) / 2; }
    double getDirArea (Point a, Point b, Point c) { return getCross(b - a, c - a) / 2; }
};

namespace Polygonal {
    using namespace Vectorial;
    using namespace Linear;

    double getArea (Point* p, int n) {
        double ret = 0;
        for (int i = 0; i < n-1; i++)
            ret += (p[i]-p[0]) * (p[i+1]-p[0]);
        return ret/2;
    }

    int getConvexHull (Point* p, int n, Point* ch) {
        sort(p, p + n);
        int m = 0;
        for (int i = 0; i < n; i++) {

            //while (m > 1 && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-1])) < 0) m--;
            while (m > 1 && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-1])) <= 0) m--;
            ch[m++] = p[i];
        }
        int k = m;
        for (int i = n-2; i >= 0; i--) {
            //while (m > k && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) < 0) m--;
            while (m > k && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
            ch[m++] = p[i];
        }
        if (n > 1) m--;
        return m;
    }

    int isPointInPolygon (Point o, Point* p, int n) {
        int wn = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (onSegment(o, p[i], p[j]) || o == p[i]) return 0;
            int k = dcmp(getCross(p[j] - p[i], o-p[i]));
            int d1 = dcmp(p[i].y - o.y);
            int d2 = dcmp(p[j].y - o.y);
            if (k > 0 && d1 <= 0 && d2 > 0) wn++;
            if (k < 0 && d2 <= 0 && d1 > 0) wn--;
        }
        return wn ? -1 : 1;
    }

    void rotatingCalipers(Point *p, int n, vector<pii>& sol) {
        sol.clear();
        int j = 1; p[n] = p[0];
        for (int i = 0; i < n; i++) {
            while (getCross(p[j+1]-p[i+1], p[i]-p[i+1]) > getCross(p[j]-p[i+1], p[i]-p[i+1]))
                j = (j+1) % n;
            sol.push_back(make_pair(i, j));
            sol.push_back(make_pair(i + 1, j + 1));
        }
    }

    void rotatingCalipersGetRectangle (Point *p, int n, double& area, double& perimeter) {
        p[n] = p[0];
        int l = 1, r = 1, j = 1;
        area = perimeter = 1e20;

        for (int i = 0; i < n; i++) {
            Vector v = (p[i+1]-p[i]) / getLength(p[i+1]-p[i]);
            while (dcmp(getDot(v, p[r%n]-p[i]) - getDot(v, p[(r+1)%n]-p[i])) < 0) r++;
            while (j < r || dcmp(getCross(v, p[j%n]-p[i]) - getCross(v,p[(j+1)%n]-p[i])) < 0) j++;
            while (l < j || dcmp(getDot(v, p[l%n]-p[i]) - getDot(v, p[(l+1)%n]-p[i])) > 0) l++;
            double w = getDot(v, p[r%n]-p[i])-getDot(v, p[l%n]-p[i]);
            double h = getDistanceToLine (p[j%n], p[i], p[i+1]);
            area = min(area, w * h);
            perimeter = min(perimeter, 2 * w + 2 * h);
        }
    }

    Polygon cutPolygon (Polygon u, Point a, Point b) {
        Polygon ret;
        int n = u.size();
        for (int i = 0; i < n; i++) {
            Point c = u[i], d = u[(i+1)%n];
            if (dcmp((b-a)*(c-a)) >= 0) ret.push_back(c);
            if (dcmp((b-a)*(d-c)) != 0) {
                Point t;
                getIntersection(a, b-a, c, d-c, t);
                if (onSegment(t, c, d))
                    ret.push_back(t);
            }
        }
        return ret;
    }

    int halfPlaneIntersection(DirLine* li, int n, Point* poly) {
        sort(li, li + n);

        int first, last;
        Point* p = new Point[n];
        DirLine* q = new DirLine[n];
        q[first=last=0] = li[0];

        for (int i = 1; i < n; i++) {
            while (first < last && !onLeft(li[i], p[last-1])) last--;
            while (first < last && !onLeft(li[i], p[first])) first++;
            q[++last] = li[i];

            if (dcmp(q[last].v * q[last-1].v) == 0) {
                last--;
                if (onLeft(q[last], li[i].p)) q[last] = li[i];
            }

            if (first < last)
                getIntersection(q[last-1].p, q[last-1].v, q[last].p, q[last].v, p[last-1]);
        }

        while (first < last && !onLeft(q[first], p[last-1])) last--;
        if (last - first <= 1) { delete [] p; delete [] q; return 0; }
        getIntersection(q[last].p, q[last].v, q[first].p, q[first].v, p[last]);

        int m = 0;
        for (int i = first; i <= last; i++) poly[m++] = p[i];
        delete [] p; delete [] q;
        return m;
    }

    Polygon simplify (const Polygon& poly) {
        Polygon ret;
        int n = poly.size();
        for (int i = 0; i < n; i++) {
            Point a = poly[i];
            Point b = poly[(i+1)%n];
            Point c = poly[(i+2)%n];
            if (dcmp((b-a)*(c-b)) != 0 && (ret.size() == 0 || b != ret[ret.size()-1]))
                ret.push_back(b);
        }
        return ret;
    }
};

Point P[MAX];
DirLine L[MAX];
Point X[MAX];

int main(){
    int t;
    scanf("%d",&t);
    using namespace Vectorial;
    using namespace Polygonal;

    Point A,B,C;
    Point D,E,F;
    for(int i=1;i<=t;i++){
        scanf("%lf %lf %lf %lf %lf %lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
        double a=getAngle(B-A,C-A);
        double b=getAngle(C-B,A-B);
        double c=getAngle(A-C,B-C);

        getIntersection(A,rotate(B-A,a/3),B,rotate(C-B,2*b/3),F);
        getIntersection(B,rotate(C-B,b/3),C,rotate(A-C,2*c/3),D);
        getIntersection(C,rotate(A-C,c/3),A,rotate(B-A,2*a/3),E);
        printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n",D.x,D.y,E.x,E.y,F.x,F.y);
    }
}

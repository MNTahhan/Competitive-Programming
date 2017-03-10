#include <iostream>
#include <cmath>
#include <complex>
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

const double EPS = 1e-8;

typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

point reflect(point p, point p0, point p1) {
  point z = p - p0, w = p1 - p0;
  return conj(z / w) * w + p0;  // Refelect point p1 around p0p1
}

#define all(v)      ((v).begin()), ((v).end())
#define sz(v)     ((int)((v).size()))
#define clr(v, d)   memset(v, d, sizeof(v))
#define rep(i, v)   for(int i=0;i<sz(v);++i)
#define lp(i, n)    for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)  for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)  for(int i=(j);i>=(int)(n);--i)


double polygonArea(vector<point>& points) {
    long double a = 0;
    rep(i, points)  a += cp(points[i], points[ (i+1) % sz(points) ]);
    return fabs(a/2.0);    // If area > 0 then points ordered ccw
}

bool intersectSegments(point a, point b, point c, point d, point & intersect) {
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false;  // Parllel || identical

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
    return false;  //e.g ab is ray, cd is segment ... change to whatever
  return true;
}

point a,b,c,f,d,e,r,p,q;

point get(point &a,point &b){
	double x,y;
	x=(1.0*b.X+2.0*a.X)/3.0;
	y=(1.0*b.Y+2.0*a.Y)/3.0;
	return point(x,y);
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		double ax,ay,bx,by,cx,cy;
		scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy);
		a=point(ax,ay); b=point(bx,by); c=point(cx,cy);
		f=get(b,a);
		e=get(a,c);
		d=get(c,b);
		assert(intersectSegments(f,c,a,d,r));
		assert(intersectSegments(a,d,b,e,p));
		assert(intersectSegments(f,c,b,e,q));
		vector<point>v;
		v.push_back(r);
		v.push_back(p);
		v.push_back(q);
		printf("%.0lf\n",polygonArea(v));
	}
	return 0;
}

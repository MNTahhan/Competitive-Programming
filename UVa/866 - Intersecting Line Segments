#include<stdio.h>
#include<vector>
#include<iostream>
#include<complex>
#include<cmath>
#include<math.h>
using namespace std;
typedef long long ll;

const double PI = acos(-1.0);

const double EPS = 1e-9;

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

bool isPointOnRay(point p0, point p1, point p2) {
    if(length(p2-p0) < EPS) return true;
    return same( normalize(p1-p0), normalize(p2-p0) );
}

bool isPointOnSegment(point a, point b, point c) {
	return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
}


int main(){
	freopen("a.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<pair<point,point> >v;
		for(int i=0;i<n;++i){
			int x,y,a,b;
			scanf("%d%d%d%d",&x,&y,&a,&b);
			v.push_back(make_pair(point(x,y),point(a,b)));
		}
		int ans=n;
		for(int i=0;i<v.size();++i){
			for(int j=0;j<v.size();++j){
				if(i==j)
					continue;
				point tmp;
				if(intersectSegments(v[i].first,v[i].second,v[j].first,v[j].second,tmp))
					ans+=isPointOnSegment(v[i].first,v[i].second,tmp);
			}
		}
		printf("%d\n",ans);
		if(t)
			puts("");
	}
	return 0;
}

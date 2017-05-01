/*
	The idea: consider each stick as a node, then connect the stick that is on top of each other using brute force, then use disjoint
		  set to check if two sticks are in the same component.
*/
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<complex>
#include<cmath>
#if !ONLINE_JUDGE
#include "inc.h"
#endif 
using namespace std;



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

int ccw(point a, point b, point c) {
  point v1(b - a), v2(c - a);
  double t = cp(v1, v2);

  if (t > +EPS)
	return +1;
  if (t < -EPS)
	return -1;
  if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
	return -1;
  if (norm(v1) < norm(v2) - EPS)
	return +1;
  return 0;
}

void ccw_testing() {
    point a(0, 0), b(10, 0);

    cout<<ccw(a, b, point(20, 10))<<"\n";     // +1 => c is ccw for a-b
    cout<<ccw(a, b, point(20, 0))<<"\n";      // +1 => Collinear after b

    cout<<ccw(a, b, point(20, -10))<<"\n";    // -1 => c is cw for a-b
    cout<<ccw(a, b, point(-20, 0))<<"\n";     // -1 => c is Collinear before a

    cout<<ccw(a, b, a)<<"\n";               // 0 => Collinear at a
    cout<<ccw(a, b, b)<<"\n";               // 0 => Collinear at b
    cout<<ccw(a, b, (a+b)/2.0)<<"\n";       // 0 => Collinear between a-b

    // one can design ccw to behave little differently
    // e.g. consider Collinear at b = +1 and at a = -1
  }

bool intersect(point p1, point p2, point p3, point p4) {
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3==p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
        ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
  }


int n,m,vis[100010],vs,p[100010];
int find(int x){
	if(x==p[x])
		return x;
	return p[x]=find(p[x]);
}
int link(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v)
		return 0;
	p[u]=v;
	return 1;
}

int main(){
#if !ONLINE_JUDGE
	freopen("a.txt","r",stdin);
#endif

	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;++i)
			p[i]=i;
		vector<pair<point,point> >v;
		for(int i=0;i<n;++i){
			int a,b,x,y;
			scanf("%d%d%d%d",&a,&b,&x,&y);
			v.push_back(make_pair(point(a,b),point(x,y)));
		}
		for(int i=0;i<v.size();++i)
			for(int j=i+1;j<v.size();++j)
				if(intersect(v[i].first,v[i].second,v[j].first,v[j].second))
					p[find(i)]=find(j);
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			--x;--y;
			puts(find(x)==find(y) ? "YES" : "NO");
		}
	}

	
	return 0;
}

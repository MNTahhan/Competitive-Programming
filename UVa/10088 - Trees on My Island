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
double polygonArea(vector<point>& poly) {
    int n=poly.size();
    long long S=0;
    
    for(int i=1;i<n;i++) S+=(long long)poly[i].X*(poly[i+1<n? i+1:i+1-n].Y-poly[i-1].Y);
    S+=(long long)poly[0].X*(poly[1].Y-poly[n-1].Y);
    
    if(S<0) return -S;
    return S;
}
long long gcd(int a,int b){
	while(a && b){
		if(a>=b) a%=b;
		else b%=a;
	}
	return a+b;
}
int main() {
	int n;
	while(scanf("%d",&n)>0 && n){
		vector<point>v;
		int a,b;
		long long cnt=n;
		for(int i=0;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			v.push_back(point(x,y));
			if(i){
				int t=abs(x-a);
				int r=abs(y-b);
				if(t==0) cnt+=r-1;
				else if(r==0) cnt+=t-1;
				else cnt+=gcd(t,r)-1;
			}
			a=x;b=y;
		}
		int t=abs(v[0].X-v[n-1].X);
		int r=abs(v[0].Y-v[n-1].Y);
		if(t==0) cnt+=r-1;
		else if(r==0) cnt+=t-1;
		else cnt+=gcd(t,r)-1;
		long long area=polygonArea(v);
		printf("%lld\n",(area - cnt + 2) / 2);
	}
	return 0;
}

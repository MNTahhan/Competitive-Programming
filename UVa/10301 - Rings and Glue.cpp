/*
  The idea: brute force + disjoint sets, I used the geometry library developed by coatch Mohammad Abdulwahab to check circle-circle intersection
*/

#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <set>
#include <time.h>
#include <assert.h>
#include <sstream>
#include <unordered_map>
#include <bitset>
#include <utility>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <math.h>
#include <cmath>
#include <complex>
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

typedef complex<long double> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a) (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine
enum STATE {
	IN, OUT, BOUNDRY
};

long double cosRule(long double a, long double b, long double c) {
	// Handle denom = 0
	long double res = (b * b + c * c - a * a) / (2 * b * c);
	if (res > 1)
		res = 1;
	if (res < -1)
		res = -1;
	return acos(res);
}
int circleCircleIntersection(const point &c1, const long double&r1,
							 const point &c2, const long double&r2, point &res1, point &res2) {
	if (same(c1, c2) && fabs(r1 - r2) < EPS) {
		res1 = res2 = c1;
		return fabs(r1) < EPS ? 1 : OO;
	}
	long double len = length(vec(c1, c2));
	if (fabs(len - (r1 + r2)) < EPS || fabs(fabs(r1 - r2) - len) < EPS) {
		point d, c;
		long double r;
		if (r1 > r2)
			d = vec(c1, c2), c = c1, r = r1;
		else
			d = vec(c2, c1), c = c2, r = r2;
		res1 = res2 = normalize(d) * r + c;
		return 1;
	}
	if (len > r1 + r2 || len < fabs(r1 - r2))
		return 0;
	long double a = cosRule(r2, r1, len);
	point c1c2 = normalize(vec(c1, c2)) * r1;
	res1 = rotate(c1c2, a) + c1;
	res2 = rotate(c1c2, -a) + c1;
	return 2;
}
int p[110], sz[110];
int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}
void link(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	p[a] = b;
	sz[b] += sz[a];
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	decTime;
#endif

	int n;
	while (scanf("%d", &n) > 0 && n != -1) {
		for (int i = 0; i <= n; ++i)
			p[i] = i, sz[i] = 1;
		vector<pair<point, double> >v;
		for (int i = 0; i < n; ++i) {
			double a, b, c;
			scanf("%lf%lf%lf", &a, &b, &c);
			v.push_back({point(a,b), c});
		}
		point x(-1, -1);
		point y(-1, -1);
		for (int i = 0; i < v.size(); ++i)
			for (int j = i + 1; j < v.size(); ++j)
				if (circleCircleIntersection(v[i].first, v[i].second, v[j].first, v[j].second, x, y))
					link(i, j);
		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (i == p[i])
				ans = max(ans, sz[i]);
		printf("The largest component contains %d ring%s.\n", ans, ans == 1 ? "" : "s");
	}



#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}


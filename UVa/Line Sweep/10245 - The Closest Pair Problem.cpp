/*
  The idea: line sweep, explained here https://www.youtube.com/watch?v=2vhS72FeMks&index=36&list=PLPt2dINI2MIY7l5zyFd1W28rei3b-AXaJ
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
#include <time.h>
#include <assert.h>
#include <sstream>
//#include <unordered_map>
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
typedef complex<double> point;

#define X real()
#define Y imag()
#define EPS 1e-9

struct cmpX {
	inline bool operator()(const point &a, const point &b) const {
		if(fabs(a.X - b.X) > EPS)
			return a.X + EPS < b.X;
		return a.Y + EPS < b.Y;
	}
};
struct cmpY {
	inline bool operator()(const point &a, const point &b) const {
		if(fabs(a.Y - b.Y) > EPS)
			return a.Y + EPS < b.Y;
		return a.X + EPS < b.X;
	}
};
double dis(point a, point b) {
	return sqrt((a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y));
}


int main() {
#ifndef ONLINE_JUDGE
	FILE *file__r = fopen("header.txt", "r"); 
	char __[110]; while(fgets(__, sizeof __, file__r) != NULL) printf("%s", __);
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int n;
	while(scanf("%d", &n) > 0 && n) {
		vector<point>v(n);
		for(int i = 0; i < n; ++i) {
			double x, y;
			scanf("%lf %lf\n", &x, &y);
			v[i] = point(x, y);
		}
		sort(v.begin(), v.end(), cmpX());
		multiset<point, cmpY>st;
		int l = 0;
		double ans = 1e300;
		for(int r = 0; r < n; ++r) {
			while(l<r && v[r].X - v[l].X > ans)
				st.erase(st.find(v[l++]));
			auto its = st.lower_bound(point(-1e300, v[r].Y - ans));
			auto ite = st.upper_bound(point(-1e300, v[r].Y + ans));
			while(its != ite) {
				ans = min(ans, dis(v[r], *its));
				++its;
			}
			st.insert(v[r]);
		}
		if(ans > 10000)
			puts("INFINITY");
		else
			printf("%.4lf\n", ans);
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

/*
  The idea: just find any one of the closest pair of points, then print the point in the middle between them.
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
#ifdef MYDEF
#include "inc.h"
#endif
using namespace std;
typedef long long ll;
typedef complex<double> point;

struct Point {
	int x, y;
	Point() { }
	Point(int x, int y):x(x), y(y) { }
};
const int N = 1e5 + 10;
bool cmpX(const Point &a, const Point &b) {
	if(a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}
struct cmpY {
	inline bool operator()(const Point &a, const Point &b)const {
		if(a.y != b.y)
			return a.y < b.y;
		return a.x < b.x;
	}
};
int n, l[N], r[N];
int dis(Point a, Point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}


int main() {
#ifdef MYDEF
	FILE *file__r = fopen("header.txt", "r"); 
	char __[110]; while(fgets(__, sizeof __, file__r) != NULL) printf("%s", __);
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		vector<Point>v(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &v[i].x, &v[i].y);
		}
		sort(v.begin(), v.end(), cmpX);
		multiset<Point, cmpY>st;
		int l = 0;
		int mn = 1e9;
		double x, y;
		for(int r = 0; r < n; ++r) {
			while(l < r && v[r].x - v[l].x > mn)
				st.erase(st.find(v[l++]));
			auto it1 = st.lower_bound(Point(-1e9, v[r].y - mn));
			auto it2 = st.upper_bound(Point(-1e9, v[r].y + mn));
			for(auto it = it1; it != it2; ++it) {
				if(mn > dis(v[r], *it)) {
					mn = dis(v[r], *it);
					x = (v[r].x + it->x) / 2.;
					y = (v[r].y + it->y) / 2.;
				}
				mn = min(mn, dis(v[r], *it));
			}
			st.insert(v[r]);
		}
		printf("%.3lf %.3lf\n", x, y);
		if(t)
			puts("");
	}

#ifdef MYDEF
	printTime;
#endif
	return 0;
}

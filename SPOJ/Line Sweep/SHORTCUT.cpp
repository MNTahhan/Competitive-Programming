/*
  The idea: line sweep
    make two sweeps, one for the horizantal and the other for the vertical shortcuts.
    the main observation that: if you put the points in an array, then two points with the same x (or y) and the index difference
    between them is more than 1 cant be on the same segment.
*/
#define _CRT_SECURE_NO_WARNINGS
#ifdef MYDEF
//#pragma optimize( "/Od", off )  
//#pragma optimize( "/Oa", off )  
//#pragma optimize( "/Og", off )  
//#pragma optimize( "/Oi", off )  
#endif
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
 
const int N = 3e5 + 10;
string dir = "EWNS";
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n, ans, l, r;
char s[N], c;
struct point {
	int x, y, idx;
	point() { }
	point(int x, int y, int idx):x(x), y(y), idx(idx) { }
};
vector<point>p, points;
struct cmpX {
	inline bool operator()(const point &a, const point &b) {
		if(a.x != b.x)
			return a.x < b.x;
		return a.y < b.y;
	}
};
struct cmpY {
	inline bool operator()(const point &a, const point &b) {
		if(a.y != b.y)
			return a.y < b.y;
		return a.x < b.x;
	}
};
char direction(int l, int r) {
	char c;
	if(points[l].x == points[r].x) {
		if(points[l].y < points[r].y)
			c = 'N';
		else
			c = 'S';
	}
	else {
		if(points[l].x < points[r].x)
			c = 'E';
		else
			c = 'W';
	}
	return c;
}
void calcX() {
	for(int i = 1; i < p.size(); ++i) {
		if(p[i].x == p[i - 1].x && abs(p[i].idx - p[i - 1].idx) > 1) {
			int cur = p[i].y - p[i - 1].y;
			int ff = min(p[i].idx, p[i - 1].idx);
			int ss = max(p[i].idx, p[i - 1].idx);
			if(cur < ans) {
				ans = cur;
				l = ff;
				r = ss;
			}
			else if(cur == ans) {
				if(ff < l) {
					l = ff;
					r = ss;
				}
				else if(ff == l) {
					r = max(r, ss);
				}
			}
		}
	}
}
void calcY() {
	for(int i = 1; i < p.size(); ++i) {
		if(p[i].y == p[i - 1].y && abs(p[i].idx - p[i - 1].idx) > 1) {
			int cur = p[i].x - p[i - 1].x;
			int ff = min(p[i].idx, p[i - 1].idx);
			int ss = max(p[i].idx, p[i - 1].idx);
			if(cur < ans) {
				ans = cur;
				l = ff;
				r = ss;
			}
			else if(cur == ans) {
				if(ff < l) {
					l = ff;
					r = ss;
				}
				else if(ff == l) {
					r = max(r, ss);
				}
			}
		}
	}
}
 
 
int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif
 
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%s", &n, s + 1);
		p.clear();
		p.resize(n + 1);
		p[0] = point(0, 0, 0);
		ans = 1e9;
		int x = 0, y = 0;
		for(int i = 1; i <= n; ++i) {
			int d = dir.find(s[i]);
			x += dx[d];
			y += dy[d];
			p[i] = point(x, y, i);
		}
		points = p;
		sort(p.begin(), p.end(), cmpX());
		calcX();
		sort(p.begin(), p.end(), cmpY());
		calcY();
		c = direction(l, r);
		printf("%d %d %d %c\n", ans, l, r, c);
	}
 
 
#ifdef MYDEF
	printTime;
#endif
	return 0;
} 

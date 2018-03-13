/*
    line sweep in O(N^2)
    traverse each vertical edge by increasing x, get the x difference, then make another line sweep on the y edge of rectangles by 
    increasing y, get the sum of y spaces that should be considered, then update the answer with the current area.
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

struct rect {
	int x, y, a, b;
	rect() { }
	rect(int x, int y, int a, int b):x(x), y(y), a(a), b(b) { fix(); }
	void fix() {
		if(x > a)
			swap(x, a);
		if(y > b)
			swap(y, b);
	}
};
struct e {
	int type, idx;
	e() { }
	e(int type, int idx):type(type), idx(idx) { };
};
const int N = 5e3 + 10;
vector<rect>r;
vector<e>v1, v2;
int in[2 * N];
bool cmpX(const e &a, const e &b) {
	int x1 = !a.type ? r[a.idx].x : r[a.idx].a;
	int x2 = !b.type ? r[b.idx].x : r[b.idx].a;
	return x1 < x2;
}
bool cmpY(const e &a, const e &b) {
	int y1 = !a.type ? r[a.idx].b : r[a.idx].y;
	int y2 = !b.type ? r[b.idx].b : r[b.idx].y;
	return y1 > y2;
}

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int n;
	scanf("%d", &n);
	r.resize(n);
	v1.resize(2 * n);
	v2.resize(2 * n);
	for(int i = 0; i < n; ++i) {
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		r[i] = rect(x, y, a, b);
		v1[2 * i] = v2[2 * i] = e(0, i);
		v1[2 * i + 1] = v2[2 * i + 1] = e(1, i);
	}
	sort(v1.begin(), v1.end(), cmpX);
	sort(v2.begin(), v2.end(), cmpY);
	int ans = 0;
	in[v1[0].idx] = 1;
	for(int i = 1; i < 2 * n; ++i) {
		e cur = v1[i];
		e prv = v1[i - 1];
		int x1 = !cur.type ? r[cur.idx].x : r[cur.idx].a;
		int x2 = !prv.type ? r[prv.idx].x : r[prv.idx].a;
		int x = x1 - x2;
		if(x == 0) {
			in[cur.idx] = !cur.type;
			continue;
		}
		int last = -1, cnt = 0;
		for(int j = 0; j < 2 * n; ++j) {
			if(!in[v2[j].idx])
				continue;
			if(v2[j].type == 0) {
				++cnt;
				if(cnt == 1)
					last = j;
			}
			else if(--cnt == 0) {
				int y = r[v2[last].idx].b - r[v2[j].idx].y;
				ans += x * y;
			}
		}
		in[cur.idx] = !cur.type;
	}
	printf("%d\n", ans);


#ifdef MYDEF
	printTime;
#endif
	return 0;
}

/*
  The idea: line sweep, consider event(l,r) as point(x,y),  now at every point, insert its y in the active set, and pop the points that 
            have y value less than the current x, if at any point the active set size is more than 2, the answer is no.
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
int n, l[N], r[N];


int main() {
#ifdef MYDEF
	FILE *file__r = fopen("header.txt", "r"); 
	char __[110]; while(fgets(__, sizeof __, file__r) != NULL) printf("%s", __);
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	scanf("%d", &n);
	vector<Point>v(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &v[i].x, &v[i].y);
	}
	sort(v.begin(), v.end(), cmpX);
	multiset<int>st;
	int l = 0;
	for(int r = 0; r < n; ++r) {
		while(l < r && *st.begin() < v[r].x) {
			st.erase(st.begin());
			++l;
		}
		st.insert(v[r].y);
		if(st.size() > 2)
			return 0 * puts("NO");
	}
	puts("YES");


#ifdef MYDEF
	printTime;
#endif
	return 0;
}

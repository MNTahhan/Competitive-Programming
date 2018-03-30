/*
  sort the points DESC by Y, then ASC by X, then brute force the solution.
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

struct node {
	char c;
	int x, y;
}a[30];
int n;

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int T = 1;
	while(scanf("%d", &n) > 0 && n) {
		for(int i = 0; i < n; ++i)
			scanf(" %c%d%d", &a[i].c, &a[i].x, &a[i].y);
		sort(a, a + n, [&](const node &n1, const node &n2) {
			if(n1.y != n2.y)
				return n1.y > n2.y;
			return n1.x < n2.x;
		});
		vector<string>v;
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j)
				for(int k = j + 1; k < n; ++k)
					for(int d = k + 1; d < n; ++d) {
						if(i == j || i == k || i == d || j == k || j == d || k == d)
							continue;
						string rec = "";
						if(a[i].x == a[k].x && a[j].x == a[d].x && a[i].y == a[j].y && a[k].y == a[d].y) {
							rec += a[i].c;
							rec += a[j].c;
							rec += a[d].c;
							rec += a[k].c;
							v.push_back(rec);
						}
							
					}
		sort(v.begin(), v.end());
		printf("Point set %d:", T++);
		if(!v.size())
			printf(" No rectangles");
		else
			puts("");
		for(int i = 0; i < v.size(); ++i) {
			printf(" %s", v[i].c_str());
			if(i + 1 < v.size() && (i + 1) % 10 == 0)
				puts("");
		}
		puts("");
	}

#ifdef MYDEF
	printTime;
#endif
	return 0;
}

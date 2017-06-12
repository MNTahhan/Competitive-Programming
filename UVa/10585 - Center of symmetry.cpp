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



int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		double sx = 0, sy = 0;
		map<pair<int, int>, int>m;
		vector<pair<int, int> >v;
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			m[{x, y}] = 1;
			v.push_back({x,y});
			sx += x;
			sy += y;
		}
		double x = sx / n;
		double y = sy / n;
		int flag = 1; 
		for (int i = 0; flag && i < n; ++i) {
			double a = 2 * x - v[i].first;
			double b = 2 * y - v[i].second;
			flag = m[make_pair(a, b)];
		}
		puts(flag ? "yes" : "no");
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}


/*
  The idea: brute force, we have 12 walls that can be made, try to make them all, and in each try use masks to put all the points 
            in all possibilities to make a wall.
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

int n, dp[20][1 << 16], vis[20][1 << 16], vs;
vector<pair<int, int> >v, g; // v has the points of the current wall we try to make, g is the original points
int dis(int i, int j) {
	return abs(v[i].first - g[j].first) + abs(v[i].second - g[j].second);
}
int calc(int at, int msk) {
	if (at == n)
		return 0;
	int &ret = dp[at][msk];
	if (vis[at][msk] == vs)
		return ret;
	vis[at][msk] = vs;
	ret = 1 << 20;
	for (int i = 0; i < n; ++i)
		if (!((msk >> i) & 1))
			ret = min(ret, dis(at, i) + calc(at + 1, msk | (1 << i)));
	return ret;
}
void fix() {
	v.clear();
	++vs;
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int h = 1;
	while (scanf("%d", &n) > 0 && n) {
		g.clear();
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x; --y;
			g.push_back({x,y});
		}
		int ans = 1 << 20;
		fix();
		for (int i = 0; i < n; ++i)
			v.push_back({i,i});
		ans = min(ans, calc(0, 0));
		fix();
		for (int i = 0; i < n; ++i)
			v.push_back({i,n - i - 1});
		ans = min(ans, calc(0, 0));
		for (int i = 0; i < n; ++i) {
			fix();
			for (int j = 0; j < n; ++j)
				v.push_back({i,j});
			ans = min(ans, calc(0, 0));
			fix();
			for (int j = 0; j < n; ++j)
				v.push_back({j,i});
			ans = min(ans, calc(0, 0));
		}
		printf("Board %d: %d moves required.\n\n", h++, ans);
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}


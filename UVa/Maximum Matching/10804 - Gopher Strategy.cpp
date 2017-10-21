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
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

int n, m, vis[55], vs, match[55], k;
vector<int>adj[55];
vector<pair<double, double> >g, h;
int findMatch(int u) {
	vis[u] = vs;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (match[v] == -1) {
			match[v] = u;
			return 1;
		}
	}
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (vis[match[v]] != vs && findMatch(match[v])) {
			match[v] = u;
			return 1;
		}
	}
	return 0;
}
bool check(double mid) {
	for (int i = 0; i < 55; ++i)
		adj[i].clear();
	for (int i = 0; i < g.size(); ++i) {
		for (int j = 0; j < h.size(); ++j) {
			double x = g[i].first;
			double y = g[i].second;
			double a = h[j].first;
			double b = h[j].second;
			double d = sqrt((x - a)*(x - a) + (y - b)*(y - b));
			if (d <= mid)
				adj[i].push_back(j);
		}
	}
	memset(match, -1, sizeof match);
	int ans = 0;
	for (int i = 0; i < g.size(); ++i) {
		++vs;
		if (findMatch(i))
			++ans;
	}
	return m - ans <= k;
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	int T = 1;
	while (t--) {
		scanf("%d%d%d", &m, &n, &k);
		g.clear();
		h.clear();
		for (int i = 0; i < m; ++i) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			g.push_back(make_pair(x, y));
		}
		for (int i = 0; i < n; ++i) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			h.push_back(make_pair(x, y));
		}
		double lo = 0, hi = 1e9, ans = -1;
		while (hi - lo > 1e-7) {
			double mid = (lo + hi) / 2.0;
			if (check(mid))
				ans = hi = mid;
			else
				lo = mid;
		}
		printf("Case #%d:\n", T++);
		if (ans < 0)
			puts("Too bad.");
		else
			printf("%.3lf\n", ans);
		puts("");
	}

#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

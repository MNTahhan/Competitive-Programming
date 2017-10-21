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

int n, q[111], vis[111], p[111], cap[111][111], vs;
vector<int>adj[111];
bool bfs(int str, int tar) {
	++vs;
	vis[str] = vs;
	p[str] = -1;
	int l, f;
	q[l = f = 0] = str;
	while (f <= l) {
		int e = q[f++];
		for (int i = 0; i < adj[e].size(); ++i) {
			int u = adj[e][i];
			if (vis[u] == vs || cap[e][u] <= 0)
				continue;
			vis[u] = vs;
			p[u] = e;
			q[++l] = u;
			if (u == tar)
				return true;
		}
	}
	return false;
}
int maxFlow(int str, int tar) {
	int flow = 0;
	while (bfs(str, tar)) {
		int mn = 1e9;
		for (int i = tar; p[i] != -1; i = p[i])
			mn = min(mn, cap[p[i]][i]);
		flow += mn;
		for (int i = tar; p[i] != -1; i = p[i]) {
			cap[p[i]][i] -= mn;
			cap[i][p[i]] += mn;
		}
	}
	return flow;
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int T = 1;
	while (scanf("%d", &n) > 0 && n) {
		for (int i = 0; i < 111; ++i)
			adj[i].clear();
		memset(cap, 0, sizeof cap);
		int s, t, c;
		scanf("%d%d%d", &s, &t, &c);
		--s; --t;
		while (c--) {
			int u, v, e;
			scanf("%d%d%d", &u, &v, &e);
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			cap[u][v] += e;
			cap[v][u] += e;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", T++, maxFlow(s, t));
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

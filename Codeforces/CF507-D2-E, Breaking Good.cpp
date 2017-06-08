/*
	The idea: similar to the auther's solution, only implemented using dijkstra
	tutorial: http://codeforces.com/blog/entry/15975
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
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

struct node {
	int v, c, r;
	node() { }
	node(int v, int c, int r):v(v), c(c), r(r) { }
	inline bool operator<(const node &e)const {
		if (c == e.c) 
			return r > e.r;
		return c > e.c;
	}
};
struct node2 { // 
	int u, v, c;
	node2() { }
	node2(int u, int v, int c):u(min(u, v)), v(max(u, v)), c(c) { }
	inline bool operator==(const node2 &e)const {
		return u == e.u && v == e.v;
	}
	inline bool operator<(const node2 &e)const {
		return u < e.u;
	}
};
const int N = 1e5 + 10;
int n, m, vis[N], p[N];
vector<pair<int,int> >adj[N];
pair<int, int> cost[N];
map<int, int>e[N];
void dijkstra() {
	for (int i = 0; i < N; ++i)
		cost[i] = {1e9,1e9}; // minimize c & r in the state
	priority_queue<node>q;
	q.push(node(0,0,0)); // (the node, the cost, the total repaired edges till now)
	cost[0] = {0,0};
	while (q.size()) {
		node e = q.top();
		q.pop();
		if (e.v == n - 1)
			return;
		for (int i = 0; i < adj[e.v].size(); ++i) {
			int u = adj[e.v][i].first;
			int c = e.c + 1;
			int r = !adj[e.v][i].second + e.r;
			if (cost[u].first < c || cost[u].second <= r)
				continue;
			p[u] = e.v;
			cost[u] = {c,r};
			q.push(node(u, c, r));
		}
	}
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	scanf("%d%d", &n, &m);
	vector<node2>edge;
	for (int i = 0, u, v, c; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &c);
		--u; --v;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
		e[u][v] = e[v][u] = i;
		edge.push_back(node2(u, v, c));
	}
	p[0] = -1;
	dijkstra();
	vector<node2>ans;
	for (int i = n - 1; i != 0; i = p[i]) { // go through the path and mark the path of dijkstra and add them to the answer only 
		int idx = e[i][p[i]];           // if it broken
		if (edge[idx].c == 0)
			ans.push_back(node2(i, p[i], 1));
		edge[idx].c = -1;
	}
	for (int i = 0; i < m; ++i) 
		if (edge[i].c == 1) // non-path edge & working, so distroy it
			ans.push_back(node2(edge[i].u, edge[i].v, 0));
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i)
		printf("%d %d %d\n", ans[i].u + 1, ans[i].v + 1, ans[i].c);
	

#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}


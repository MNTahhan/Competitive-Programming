/*
 * The idea: max flow with ford fulkerson algorithm, then get the answer by running DFS to find the edges that you will cut
 */
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

const int N = 550;
int n, m, vis[N], vs, q[N], l, r, p[N], mp[N];
ll cost[N][N];
vector<int> adj[N];
vector<pair<int, int> > ans, edges;
bool BFS(int str, int tar) {
	q[l = r = 0] = str;
	vis[str] = ++vs;
	p[str] = -1;
	while (l <= r) {
		int fr = q[l++];
		for (int i = 0; i < adj[fr].size(); ++i) {
			int u = adj[fr][i];
			if (vis[u] == vs || cost[fr][u] <= 0)
				continue;
			vis[u] = vs;
			q[++r] = u;
			p[u] = fr;
			if (u == tar)
				return true;
		}
	}
	return false;
}
ll maxFlow(int str, int tar) {
	ll flow = 0;
	while (BFS(str, tar)) {
		ll mn = 1e17;
		int idx;
		for (int i = tar; p[i] != -1; i = p[i])
			mn = min(mn, cost[p[i]][i]);
		for (int i = tar; p[i] != -1; i = p[i]) {
			cost[p[i]][i] -= mn;
			cost[i][p[i]] += mn;
		}
		flow += mn;
	}
	return flow;
}
void DFS(int u) {
	mp[u] = 2;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (cost[u][v] && mp[v] == 1)
			DFS(v);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
//	freopen("a.txt", "w", stdout);
	decTime;
#endif

	while (scanf("%d%d", &n, &m) > 0 && (n || m)) {
		for (int i = 0; i <= n; ++i) {
			adj[i].clear();
			mp[i] = 1;
		}
		edges.clear();
		while (m--) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u;
			--v;
			edges.push_back( { u, v });
			adj[u].push_back(v);
			adj[v].push_back(u);
			cost[u][v] = cost[v][u] = c;
		}
		maxFlow(0, 1);
		DFS(0);
		for (int i = 0; i < edges.size(); ++i)
			if (mp[edges[i].first] != mp[edges[i].second])
				printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
		puts("");
	}

#ifndef ONLINE_JUDGE
	printTime;
#endif
	return 0;
}


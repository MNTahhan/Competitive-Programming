/*
  The idea: for the shortest hieght -> the middle of the diameter is the answer, if the diameter length is odd, then the two nodes in the middle are the answer
            for the longest hieght -> pre calculate the distance from all nodes to the ends of the diameter, then check every node, if the distance from it to any end is equal the diameter, then this nodes gives us the worst height
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

int n, node1, node2, mx, p[5050], mark[5050][5050], d[2][5050];
vector<int>adj[5050];
void dfs(int u, int par, int c, int &node, int &dis) {
	if (c > dis) {
		dis = c;
		node = u;
	}
	p[u] = par;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		//print2(u, v);
		if (v == par)
			continue;
		dfs(v, u, c + 1, node, dis);
	}
}
void calc(int u, int p, int c, int bit) {
	d[bit][u] = c;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == p)
			continue;
		calc(v, u, c + 1, bit);
	}
}


int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	while (scanf("%d", &n) > 0) {
		memset(mark, 0, sizeof mark);
		for (int i = 0; i <= n; ++i)
			adj[i].clear();
		for (int i = 0; i < n; ++i) {
			int k;
			scanf("%d", &k);
			while (k--) {
				int u;
				scanf("%d", &u);
				--u;
				if (!mark[i][u]) {
					adj[i].push_back(u);
					mark[i][u] = 1;
				}
				if (!mark[u][i]) {
					adj[u].push_back(i);
					mark[u][i] = 1;
				}
			}
		}
		mx = -1;
		dfs(0, -1, 0, node1, mx);
		mx = -1;
		dfs(node1, -1, 0, node2, mx);
		vector<int>v, best, worst;
		for (int i = node2; i != -1; i = p[i])
			v.push_back(i);
		if (v.size() & 1)
			best.push_back(v[v.size() / 2]);
		else {
			best.push_back(v[v.size() / 2]);
			best.push_back(v[v.size() / 2 - 1]);
		}
		calc(node1, -1, 0, 0);
		calc(node2, -1, 0, 1);
		for (int i = 0; i < n; ++i)
			if (d[0][i] == mx || d[1][i] == mx)
				worst.push_back(i);
		sort(best.begin(), best.end());
		sort(worst.begin(), worst.end());
		printf("Best Roots  :");
		for (int i = 0; i < best.size(); ++i)
			printf(" %d", best[i] + 1);
		putchar('\n');
		printf("Worst Roots :");
		for (int i = 0; i < worst.size(); ++i)
			printf(" %d", worst[i] + 1);
		putchar('\n');
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}


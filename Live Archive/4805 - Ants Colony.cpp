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

const int N = 1e5 + 10;
int n, dp[N][22], d[N];
ll len[N][22];
vector<pair<int, int> >adj[N];
void dfs(int u, int p) {
	dp[u][0] = p;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i].first;
		int c = adj[u][i].second;
		if (v == p)
			continue;
		d[v] = 1 + d[u];
		len[v][0] = c;
		dfs(v, u);
	}
}
ll LCA(int a, int b) {
	if (d[a] < d[b])
		swap(a, b);
	ll res = 0;
	for (int i = 20; i >= 0; --i) 
		if (d[a] - (1 << i) >= d[b]) {
			res += len[a][i];
			a = dp[a][i];
		}
	if (a == b)
		return res;
	for (int i = 20; i >= 0; --i) 
		if (dp[a][i] != dp[b][i]) {
			res += len[a][i] + len[b][i];
			a = dp[a][i];
			b = dp[b][i];
		}
	res += len[a][0] + len[b][0];
	return res;
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	while (scanf("%d", &n) > 0 && n) {
		for (int i = 0; i <= n; ++i)
			adj[i].clear();
		for (int i = 1; i < n; ++i) {
			int v, c;
			scanf("%d%d", &v, &c);
			adj[i].push_back({ v,c });
			adj[v].push_back({ i,c });
		}
		dfs(0, -1);
		for (int k = 1; (1 << k) < n; ++k)
			for (int i = 0; i < n; ++i) {
				if (dp[i][k - 1] == -1) {
					dp[i][k] = -1;
					len[i][k] = 0;
				}
				else {
					dp[i][k] = dp[dp[i][k - 1]][k - 1];
					len[i][k] = len[dp[i][k - 1]][k - 1] + len[i][k - 1];
				}
			}
		int q;
		scanf("%d", &q);
		bool flag = false;
		while (q--) {
			int u, v;
			scanf("%d%d", &u, &v);
			if (flag)
				putchar(' ');
			flag = true;
			printf("%lld", LCA(u, v));
		}
		puts("");
	}



#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

/*
  The idea: the same idea in this solution
*/
#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
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
#include <complex>
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

const int N = 330;
const int off = 110;
int n, m, vis[N], dp[110][N];
vector<int>adj[N], col[2], ans[2]; // col[0] white, col[1] black
vector<vector<int> >white, black;
void dfs(int u, int p, int bit) {
	col[bit].push_back(u);
	vis[u] = bit;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (vis[v] == vis[u]) {
			puts("IMPOSSIBLE");
			exit(0);
		}
		if (vis[v] == -1)
			dfs(v, u, !bit);
	}
}
int calc(int at, int sum) {
	if (at == white.size())
		return !sum;
	auto &ret = dp[at][sum + off];
	if (~ret)
		return ret;
	int x = (signed) white[at].size() - (signed) black[at].size();
	return ret = calc(at + 1, sum + x) | calc(at + 1, sum - x);
}
void path(int at, int sum) {
	if (at == white.size())
		return;
	int op = calc(at, sum);
	int x = (signed) white[at].size() - (signed) black[at].size();
	if (op == calc(at + 1, sum + x)) {
		for (int i = 0; i < white[at].size(); ++i)
			ans[0].push_back(white[at][i]);
		for (int i = 0; i < black[at].size(); ++i)
			ans[1].push_back(black[at][i]);
		path(at + 1, sum + x);
		return;
	}
	for (int i = 0; i < black[at].size(); ++i)
		ans[0].push_back(black[at][i]);
	for (int i = 0; i < white[at].size(); ++i)
		ans[1].push_back(white[at][i]);
	path(at + 1, sum - x);
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	memset(vis, -1, sizeof vis);
	memset(dp, -1, sizeof dp);
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < 2 * n; ++i)
		if (vis[i] == -1) {
			dfs(i, -1, 0);
			white.push_back(col[0]);
			black.push_back(col[1]);
			col[0].clear();
			col[1].clear();
		}
	if (!calc(0, 0))
		return 0 * puts("IMPOSSIBLE");
	path(0, 0);
	printf("%d", ans[0][0] + 1);
	for (int i = 1; i < ans[0].size(); ++i)
		printf(" %d", ans[0][i] + 1);
	printf("\n%d", ans[1][0] + 1);
	for (int i = 1; i < ans[1].size(); ++i)
		printf(" %d", ans[1][i] + 1);
	puts("");


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

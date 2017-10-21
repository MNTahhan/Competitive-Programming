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

int n, vis[101 * 101], vs, a[101][101], b[101][101], q[101 * 101], f, l, cap[5010 * 2][5010 * 2];
int p[101 * 101], flag[2][5010], fl, N;
char s[111][111];
vector<int>adj[111 * 111];
bool bfs(int str, int tar) {
	++vs;
	q[f = 0] = str;
	l = 1;
	vis[str] = vs;
	p[str] = -1;
	while (f < l) {
		int e = q[f++];
		for (int i = 0; i < adj[e].size(); ++i) {
			int u = adj[e][i];
			if (vis[u] == vs || cap[e][u] <= 0)
				continue;
			p[u] = e;
			if (u == tar)
				return true;
			vis[u] = vs;
			q[l++] = u;
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

	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		++fl;
		int row = 0, col = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (s[i][j] != 'X')
					a[i][j] = row, flag[0][row] = fl;
				else
					a[i][j] = -1, row += flag[0][row] == fl;

				if (s[j][i] != 'X')
					b[j][i] = col, flag[1][col] = fl;
				else
					b[j][i] = -1, col += flag[1][col] == fl;
			}
			if (flag[0][row] == fl)
				++row;
			if (flag[1][col]==fl)
				++col;
		}
		N = row + col + 2;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == -1 || b[i][j] == -1)
					continue;
				adj[a[i][j]].push_back(b[i][j] + row);
				adj[b[i][j] + row].push_back(a[i][j]);
				cap[a[i][j]][b[i][j] + row] = 1;
				cap[b[i][j] + row][a[i][j]] = 0;
			}
		for (int i = 0; i < row; ++i) {
			adj[N - 2].push_back(i);
			adj[i].push_back(N - 2);
			cap[N - 2][i] = 1;
			cap[i][N - 2] = 0;
		}
		for (int i = 0; i < col; ++i) {
			adj[i + row].push_back(N - 1);
			adj[N - 1].push_back(i + row);
			cap[i + row][N - 1] = 1;
			cap[N - 1][i + row] = 0;
		}
		printf("%d\n", maxFlow(N - 2, N - 1));
		for (int i = 0; i < row + col + 2; ++i)
			adj[i].clear();
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

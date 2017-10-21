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

const int N = 111 * 111;
int n, a[111][111], b[111][111], vis[N], vs, match[N];
char s[111][111];
vector<int>adj[N];
int findMatch(int u) {
	vis[u] = vs;
	random_shuffle(adj[u].begin(), adj[u].end());
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

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		int row = 1, col = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (s[i][j] != 'X')
					a[i][j] = row;
				else
					++row, a[i][j] = 0;
				if (s[j][i] != 'X')
					b[j][i] = col;
				else
					++col, b[j][i] = 0;
			}
			++row;
			++col;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == 0 || b[i][j] == 0)
					continue;
				adj[a[i][j]].push_back(b[i][j]);
			}
		}
		memset(match, -1, sizeof match);
		int ans = 0;
		for (int i = 1; i <= row; ++i) {
			++vs;
			if (findMatch(i))
				++ans;
		}
		printf("%d\n", ans);
		for (int i = 1; i <= row; ++i)
			adj[i].clear();
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

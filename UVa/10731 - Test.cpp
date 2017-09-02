/*
  The idea: build a directed graph then get the SCC in it
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

const int N = 33;
vector<vector<int> >ans;
vector<int>adj[N];
vector<int>s;
int vis[N], low[N], idx[N], dfs;
void DFS(int u) {
	low[u] = idx[u] = dfs++;
	s.push_back(u);
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!idx[v])
			DFS(v);
		if(vis[v])
			low[u] = min(low[u], low[v]);
	}
	if (low[u] == idx[u]) {
		vector<int>cur;
		while (true) {
			int v = s.back();
			s.pop_back();
			vis[v] = 0;
			cur.push_back(v);
			if (v == u)
				break;
		}
		sort(cur.begin(), cur.end());
		ans.push_back(cur);
	}
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int n, flag = 0;
	while (scanf("%d", &n) > 0 && n) {
		if (flag)
			puts("");
		flag = 1;
		for (int i = 0; i < N; ++i)
			adj[i].clear();
		ans.clear();
		set<char>all;
		while (n--) {
			vector<char>c(5);
			for (int i = 0; i < 5; ++i) {
				scanf(" %c", &c[i]);
				all.insert(c[i]);
			}
			char r;
			scanf(" %c", &r);
			for (int i = 0; i < c.size(); ++i)
				adj[r - 'A'].push_back(c[i] - 'A');
		}
		dfs = 1;
		memset(idx, 0, sizeof idx);
		for (auto it = all.begin(); it != all.end(); ++it)
			if (!idx[(*it) - 'A'])
				DFS((*it) - 'A');
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i, puts(""))
			for (int j = 0; j < ans[i].size(); ++j)
				printf("%c%s", ans[i][j] + 'A', j + 1 == ans[i].size() ? "" : " ");
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

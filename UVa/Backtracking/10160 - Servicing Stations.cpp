/*
  Backtracking with pruning
  if we represent the nodes as bitmask, and the nodes that is served by at least one station is set to 1 and others to 0, then to reduce
  the amount of states we have, we should know that if we add a station in the current node, then there must be at least one way to 
  cover all the other nodes, at least by adding a station to every node we reach to the end of the nodes.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
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
#ifdef MYDEF
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

int n, m;
ll all, adj[40], cover[40];
int DFS(int u, int cnt, ll msk, int limit) {
	if(msk == all)
		return 1;
	if(cnt >= limit)
		return 0;
	for(int i = u; i < n; ++i) {
		if((cover[i] | msk) != all)
			break;
		if((msk | adj[i]) == msk)
			continue;
		if(DFS(i + 1, cnt + 1, msk | adj[i], limit))
			return 1;
	}
	return 0;
}

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	while(scanf("%d%d", &n, &m), n || m) {
		memset(adj, 0, sizeof adj);
		all = (1LL << n) - 1;
		while(m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			adj[u] |= 1LL << v;
			adj[v] |= 1LL << u;
		}
		for(int i = 0; i < n; ++i)
			adj[i] |= 1LL << i;
		cover[n - 1] = adj[n - 1];
		for(int i = n - 2; i >= 0; --i)
			cover[i] = cover[i + 1] | adj[i];
		int ans = n;
		for(int i = 1; i <= n; ++i)
			if(DFS(0, 0, 0, i)) {
				ans = i;
				break;
			}
		printf("%d\n", ans);
	}
	
	

#ifdef MYDEF
	printTime;
#endif
	return 0;
}

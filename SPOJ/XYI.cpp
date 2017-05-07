/*
  The idea: if the graph is Y shaped, then there must only one node with degree = 3, and 3 nodes with degree = 1 (the end of lines), 
            and the rest has degree = 2
            if it is X shaped, then there must be one node with degree = 4, 4 nodes with degree = 1, and the rest with degree = 2
            if it is I shaped, then all the nodes has degree = 2 except both ends has degree = 1
*/
#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <cstring>
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
#include <numeric>
#include <iomanip>
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

vector<int>adj[550];
int cnt[550], n, m;

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int t, h = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; ++i) {
			adj[i].clear();
			cnt[i] = 0;
		}
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i <= n; ++i)
			++cnt[adj[i].size()];
		printf("Case %d: ", h++);
		if (cnt[3]) {
			if (cnt[3] != 1)
				puts("NotValid");
			else {
				bool flag = true;
				for (int i = 4; i <= m; ++i)
					flag &= cnt[i] == 0;
				if (!flag || cnt[1] != 3)
					puts("NotValid");
				else
					puts("Y");
			}
		} else if (cnt[4]) {
			if (cnt[4] != 1)
				puts("NotValid");
			else {
				bool flag = cnt[3] == 0;
				for (int i = 5; i <= m; ++i)
					flag &= cnt[i] == 0;
				if (!flag || cnt[1] != 4)
					puts("NotValid");
				else
					puts("X");
			}
		} else if (cnt[1]) {
			if (cnt[1] != 2)
				puts("NotValid");
			else {
				bool flag = true;
				for (int i = 3; i <= m; ++i)
					flag &= cnt[i] == 0;
				if (!flag)
					puts("NotValid");
				else
					puts("I");
			}
		} else
			puts("NotValid");
	}




#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

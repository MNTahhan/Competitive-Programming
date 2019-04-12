/* bfs,grid */
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

const int N = 200;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n, m;
char a[N][N];
int ans[N][N], vis[N][N];


int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while(t--) {
		memset(vis, 0, sizeof vis);
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf(" %c", a[i] + j);
		queue<int>q;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(a[i][j] == '1') {
					q.push(i);
					q.push(j);
					vis[i][j] = 1;
					ans[i][j] = 0;
				}
		int lev = 1;
		while(q.size()) {
			int sz = q.size() / 2;
			while(sz--) {
				int x = q.front(); q.pop();
				int y = q.front(); q.pop();
				for(int k = 0; k < 4; ++k) {
					int tx = x + dx[k];
					int ty = y + dy[k];
					if(tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty])
						continue;
					q.push(tx);
					q.push(ty);
					vis[tx][ty] = 1;
					ans[tx][ty] = ans[x][y] + 1;
				}
			}
			++lev;
		}
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				printf("%d%s", ans[i][j], j + 1 == m ? "\n" : " ");
	}


#ifdef MYDEF
	printTime;
#endif
	return 0;
}

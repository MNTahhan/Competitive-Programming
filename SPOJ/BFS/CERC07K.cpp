/* bfs,bitmask,grid */
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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n, m;
char s[110][110];
int vis[110][110][1 << 4], mp[130];
int BFS(int x, int y) {
	queue<int>q;
	q.push(x);
	q.push(y);
	q.push(0);
	vis[x][y][0] = 1;
	int lev = 1;
	while(q.size()) {
		int sz = q.size() / 3;
		while(sz--) {
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			int msk = q.front(); q.pop();
			for(int k = 0; k < 4; ++k) {
				int tx = dx[k] + x;
				int ty = dy[k] + y;
				int nmsk = msk;
				if(tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty][nmsk] || s[tx][ty] == '#')
					continue;
				if(s[tx][ty] == 'X')
					return lev;
				if(isupper(s[tx][ty]) && ((msk >> mp[s[tx][ty]]) & 1) == 0)
					continue;
				if(islower(s[tx][ty]))
					nmsk |= 1 << mp[s[tx][ty]];
				vis[tx][ty][nmsk] = 1;
				q.push(tx);
				q.push(ty);
				q.push(nmsk);
			}
		}
		++lev;
	}
	return -1;
}

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	mp['R'] = mp['r'] = 0;
	mp['Y'] = mp['y'] = 1;
	mp['B'] = mp['b'] = 2;
	mp['G'] = mp['g'] = 3;
	while(scanf("%d%d", &n, &m) > 0 && (n || m)) {
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		int x, y;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(s[i][j] == '*') {
					x = i, y = j;
					break;
				}
		int res = BFS(x, y);
		if(res == -1)
			puts("The poor student is trapped!");
		else
			printf("Escape possible in %d steps.\n", res);
	}

#ifdef MYDEF
	printTime;
#endif
	return 0;
}
 

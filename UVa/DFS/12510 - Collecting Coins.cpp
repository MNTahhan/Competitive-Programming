/*
  The idea: brute force, try to push the stones in every possible direction, then calculate the new coins collected
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
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;
typedef complex<double> point;

int n, m;
int vis[22][22], q[110], l, r;
char s[22][22];
int ans;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void DFS(int x, int y, int cnt) {
	int vis[22][22] = {0};
	q[l = r = 0] = x;
	q[++r] = y;
	vis[x][y] = 1;
	vector<pair<int, int> >save;
	while(r - l + 1) {
		int curx = q[l++];
		int cury = q[l++];
		for(int i = 0; i < 4; ++i) {
			int tx = dx[i] + curx;
			int ty = dy[i] + cury;
			if(tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty] || s[tx][ty] == 'X' || s[tx][ty] == '1' || s[tx][ty] == 'O')
				continue;
			vis[tx][ty] = 1;
			if(s[tx][ty] == '.') {
				q[++r] = tx;
				q[++r] = ty;
			}
			else if(s[tx][ty] == 'C') {
				++cnt;
				s[tx][ty] = '.';
				save.push_back({tx,ty});
				q[++r] = tx;
				q[++r] = ty;
			}
		}
	}
	ans = max(ans, cnt);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(s[i][j] == 'O') {
				for(int k = 0; k < 4; ++k) {
					int tx = dx[k] + i;
					int ty = dy[k] + j;
					if(tx < 0 || ty < 0 || tx >= n || ty >= m || !vis[tx][ty])
						continue;
					int nx = dx[(k + 2) % 4] + i;
					int ny = dy[(k + 2) % 4] + j;
					if(nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] != '.')
						continue;
					s[i][j] = '.';
					s[nx][ny] = '1';
					DFS(i, j, cnt);
					s[i][j] = 'O';
					s[nx][ny] = '.';
				}
			}
	for(int i = 0; i < save.size(); ++i)
		s[save[i].first][save[i].second] = 'C';
}

int main() {
#if !ONLINE_JUDGE
	FILE *file__r = fopen("header.txt", "r"); 
	char __[110]; while(fgets(__, sizeof __, file__r) != NULL) printf("%s", __);
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		int x, y;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				scanf(" %c", s[i] + j);
				if(s[i][j] == 'S') {
					x = i;
					y = j;
					s[i][j] = '.';
				}
			}
		ans = 0;
		DFS(x, y, 0);
		printf("%d\n", ans);
	}
	


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

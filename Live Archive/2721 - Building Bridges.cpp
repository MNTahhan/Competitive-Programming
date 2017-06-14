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
#include <unordered_map>
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

struct edge {
	int a, b, c;
	edge() { }
	edge(int a, int b, int c):a(a), b(b), c(c) { }
	inline bool operator<(const edge &e)const {
		return c<e.c;
	}
};
int dx[] = {1,-1,0,0,0};
int dy[] = {0,0,1,-1,0};
vector<edge>v;
int n, m, p[110 * 110], id[110][110], cmp;
char s[110][110];
int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}
int link(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return 0;
	p[a] = b;
	--cmp;
	return 1;
}
inline bool valid(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	//srand(time(0));
	//for (int k = 0; k < 4; ++k) {
	//	cout << 100 << " " << 100 << endl;
	//	for (int i = 0; i < 100; ++i, puts(""))
	//		for (int j = 0; j < 100; ++j)
	//			cout << (rand() % 5 != 0 ? '.' : '#');
	//}
	//return 0;
	freopen("b.txt", "w", stdout);
	decTime;
#endif

	int h = 1;
	while (scanf("%d%d", &n, &m) > 0 && (n || m)) {
		if (h > 1)
			puts("");
		memset(id, -1, sizeof id);
		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		for (int i = 0; i < 110 * 110; ++i)
			p[i] = i;
		v.clear();
		int idx = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (id[i][j] == -1 && s[i][j] == '#')
					id[i][j] = idx++;
		cmp = idx;
		int mx = max(n, m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (s[i][j] == '#') {
					for (int d = 1; d <= mx; ++d) {
						for (int k = 0; k < 4; ++k) {
							int tx = d * dx[k] + i;
							int ty = d * dy[k] + j;
							if (!valid(tx, ty))
								continue;
							for (int k2 = 0; k2 < 5; ++k2) {
								int tx2 = dx[k2] + tx;
								int ty2 = dy[k2] + ty;
								if (!valid(tx2, ty2) || tx2 == i && ty2 == j || s[tx2][ty2] != '#' || k2 == k) // (k2==k) to ignore the same direction, it will be covered in the next iteration of d
									continue;
								if (id[i][j] < id[tx2][ty2])
									v.push_back(edge(id[i][j], id[tx2][ty2], d - 1)); // we connect #'s of the same component with cost 0
							}
						}

					}
				}
		sort(v.begin(), v.end());
		int len = 0, cnt = 0;
		for (int i = 0; i < v.size(); ++i)
			if (link(v[i].a, v[i].b)) {
				len += v[i].c;
				cnt += v[i].c > 0; 
			}
		printf("City %d\n", h++);
		if (cnt == 0) {
			if (cmp <= 1)
				printf("No bridges are needed.\n");
			else {
				printf("No bridges are possible.\n");
				printf("%d disconnected groups\n", cmp);
			}
		} else {
			if (cnt >= 2)
				printf("%d bridges of total length %d\n", cnt, len);
			else
				printf("%d bridge of total length %d\n", cnt, len);
			if (cmp != 1)
				printf("%d disconnected groups\n", cmp);
		}
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

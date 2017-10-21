/*
 * The idea: dynamic programming, the state of dp is[positionX][positionY][msk for previous row], if we put vertical piece in the 
             previous row we set its position to 1 in the mask else it will be 0
 */
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

int n, m, dp[44][15][1 << 11];
char g[44][15];
int calc(int x, int y, int msk) {
	if (x >= n)
		return 0;
	if (y >= m)
		return calc(x + 1, 0, msk);
	int &ret = dp[x][y][msk];
	if (~ret)
		return ret;
	ret = 1e9;
	if (g[x][y] == 'o') {
		msk &= ~(1 << y);
		ret = calc(x, y + 1, msk);
	} else {
		ret = min(ret, 1 + calc(x, y + 1, msk & ~(1 << y)));
		int tmpMsk = msk & ~(1 << y);
		tmpMsk &= ~(1 << (y + 1));
		ret = min(ret, 1 + calc(x, y + 2, tmpMsk)); // because we jump two positions so we must remove the current and the next bit
		ret = min(ret, 1 + calc(x, y + 1, msk | (1 << y)));
		if ((msk >> y) & 1)
			ret = min(ret, calc(x, y + 1, msk & ~(1 << y)));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
//	freopen("a.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", g[i]);
			for (int j = 0; j <= m; ++j)
				cnt += g[i][j] == '*';
		}
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0, 0));
	}

#ifndef ONLINE_JUDGE
	printTime;
#endif
	return 0;
}


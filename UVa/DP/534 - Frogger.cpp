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


int n;
double dp[202][202];

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int h = 1;
	while (scanf("%d", &n) > 0 && n) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				dp[i][j] = 1e5;
		vector<pair<int, int> > v;
		while (n--) {
			int x, y;
			scanf("%d%d", &x, &y);
			v.push_back({ x,y });
		}
		for (int i = 0; i < v.size(); ++i)
			for (int j = 0; j < v.size(); ++j) {
				int x = v[i].first;
				int y = v[i].second;
				int a = v[j].first;
				int b = v[j].second;
				double d = sqrt((a - x)*(a - x) + (y - b)*(y - b));
				dp[i][j] = d;
			}
		for (int k = 0; k < v.size(); ++k)
			for (int i = 0; i < v.size(); ++i)
				for (int j = 0; j < v.size(); ++j)
					dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", h++, dp[0][1]);
	}

#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

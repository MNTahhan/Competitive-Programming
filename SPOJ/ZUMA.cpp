/*
  The same idea mentioned here: https://stackoverflow.com/questions/12018949/finding-the-dp-state-zuma-spoj
*/

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
 
int n, k, a[110], dp[110][110][110];
int calc(int l, int r, int p) {
	if (l > r)
		return 0;
	if (l == r)
		return k - p - 1;
	auto &ret = dp[l][r][p];
	if (~ret)
		return ret;
	ret = 1e9;
 
 ////////////
 // in this part we add as many marbles as we need to destroy the set starting from position l
	if (p + 1 < k)
		ret = 1 + calc(l, r, p + 1); // add k-1 marbles, the kth one is at index l
  if (p + 1 == k)
		ret = calc(l + 1, r, 0);
 ////////////////
 
 // solve the problem as mentioned in point 2 in the solution link
	for (int i = l + 1; i <= r; ++i) {
		if (a[i] != a[l])
			continue;
		ret = min(ret, calc(l + 1, i - 1, 0) + calc(i, r, min(k - 1, p + 1)));
	}
	return ret;
}
 
 
int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif
 
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	memset(dp, -1, sizeof dp);
	printf("%d\n", calc(0, n - 1, 0));
 
 
#if !ONLINE_JUDGE
	//printTime;
#endif
	return 0;
}

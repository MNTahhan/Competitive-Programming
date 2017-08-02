/*
  The idea: straightforward KMP
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

int f[10010];
char w[10010], t[1000010];

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int x;
	scanf("%d", &x);
	while (x--) {
		scanf("%s%s", w, t);
		int n = strlen(w);
		int m = strlen(t);
		for (int i = 1, k = 0; i < n; ++i) {
			while (k && w[k] != w[i])
				k = f[k - 1];
			if (w[k] == w[i])
				f[i] = ++k;
			else
				f[i] = k;
		}
		int ans = 0;
		for (int i = 0, k = 0; i < m; ++i) {
			while (k && w[k] != t[i])
				k = f[k - 1];
			if (w[k] == t[i])
				++k;
			if (k == n) {
				++ans;
				k = f[k - 1];
			}
		}
		printf("%d\n", ans);
	}
	


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

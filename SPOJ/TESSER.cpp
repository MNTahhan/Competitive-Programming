/* 
  The idea: replace the array with corresponding string, then do a standard KMP search
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
 
const int N = 1e5 + 10;
char s[N], r[N];
int f[N];
 
int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif
 
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int x, y;
		scanf("%d", &x);
		for (int i = 1; i < n; ++i) {
			scanf("%d", &y);
			if (y > x)
				r[i - 1] = 'G';
			else if (y < x)
				r[i - 1] = 'L';
			else
				r[i - 1] = 'E';
			x = y;
		}
		scanf("%s", s);
		int m = strlen(s);
		for (int i = 1, k = 0; i < m; ++i) {
			while (k && s[k] != s[i])
				k = f[k - 1];
			if (s[k] == s[i])
				f[i] = ++k;
			else
				f[i] = k;
		}
		int ans = 0;
		for (int i = 0, k = 0; i + 1 < n; ++i) {
			while (k && r[i] != s[k])
				k = f[k - 1];
			if (r[i] == s[k])
				++k;
			if (k == m) {
				ans = 1;
				break;
			}
		}
		puts(ans ? "YES" : "NO");
	}
 
 
#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
} 

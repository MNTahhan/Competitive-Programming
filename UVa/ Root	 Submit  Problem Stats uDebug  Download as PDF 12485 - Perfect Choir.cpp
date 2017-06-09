/*
  The idea: we add 1 in one index and subtract 1 from another one, so the sum of all numbers does not differ in the final solution. 
            so the number that all numbers must be equal to is sum/n, if sum%n != 0 then there is no solution.
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


int n;
map<int, int>m;

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	decTime;
#endif

	while (scanf("%d", &n) > 0) {
		vector<int>v(n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
			sum += v[i];
		}
		if (sum%n) {
			puts("-1");
			continue;
		}
		sum /= n;
		int ans = 1;
		for (int i = 0; i < n; ++i)
			ans += max(0, v[i] - sum);
		printf("%d\n", ans);
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}


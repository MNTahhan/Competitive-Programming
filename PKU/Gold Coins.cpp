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

int ans[100010];

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int last = 1;
	int loop = 1;
	int cur = 1;
	for (int i = 1; i < 100010; ++i) {
		if (!loop) {
			++last;
			loop = last;
			++cur;
		}
		ans[i] = cur + ans[i - 1];
		--loop;
	}
	int n;
	while (scanf("%d", &n) > 0 && n)
		printf("%d %d\n", n, ans[n]);
	

#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}


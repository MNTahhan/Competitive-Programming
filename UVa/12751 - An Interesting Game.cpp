#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <cstring>
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
#include <numeric>
#include <iomanip>
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;


int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	int h = 1;
	while (t--) {
		int n, k, x;
		scanf("%d%d%d", &n, &k, &x);
		int sum = 0;
		for (int i = 1; i < x; ++i)
			sum += i;
		for (int i = x + k; i <= n; ++i)
			sum += i;
		printf("Case %d: %d\n", h++,sum);
	}



#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

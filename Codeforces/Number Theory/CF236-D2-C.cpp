/* 
  The idea: it is enough to check the largest 10 numbers with O(n^3)
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

ll gcd(ll a, ll b) {
	if (!b)
		return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b)*b;
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int n;
	scanf("%d", &n);
	int mn = max(1, n - 10);
	ll ans = -1;
	for (int i = n; i >= mn; --i)
		for (int j = n; j >= mn; --j)
			for (int k = n; k >= mn; --k)
				ans = max(ans, lcm(i, lcm(j, k)));
	printf("%lld\n", ans);


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

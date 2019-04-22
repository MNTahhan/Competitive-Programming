/* The idea: The same idea in the tutorial */
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

ll gcd(ll a, ll b) {
	if (!b) return a;
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

	int n, k;
	scanf("%d%d", &n, &k);
	ll ans = 1;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		ans = gcd(k, lcm(x, ans));
	}
	puts(ans == k ? "Yes" : "No");
	


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

/* gcd, lcm, adhoc */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
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
#ifdef MYDEF
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

int n, t;
vector<ll>v;
ll GCD(ll a, ll b) {
	if(!b)
		return a;
	return GCD(b, a%b);
}
ll LCM(ll a, ll b) {
	return a*b/ GCD(a, b);
}

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	decTime;
#endif

	int y = 1;
	while(scanf("%d%d", &n, &t) && (n || t)) {
		v.clear(); v.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%lld", &v[i]);
		ll lcm = 1e18;
		vector<ll>all;
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j)
				for(int k = j + 1; k < n; ++k)
					for(int e = k + 1; e < n; ++e) {
						lcm = LCM(LCM(v[i], v[j]), LCM(v[k], v[e]));
						all.push_back(lcm);
					}
		sort(all.begin(), all.end());
		all.resize(unique(all.begin(), all.end()) - all.begin());
		while(t--) {
			ll x;
			scanf("%lld", &x);
			ll mx = 0;
			for(int i = 0; i < all.size(); ++i) {
				mx = max(mx, x / all[i] * all[i]);
				if(all[i] <= x)
					mx = max(mx, all[i]);
			}
			ll mn = 1e18;
			for(int i = 0; i < all.size(); ++i) {
				mn = min(mn, (x / all[i] + (x % all[i] > 0)) * all[i]);
				if(all[i] >= x)
					mn = min(mn, all[i]);
			}
			printf("%lld %lld\n", mx, mn);
		}
	}


#ifdef MYDEF
	//printTime;
#endif
	return 0;
}
 

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

int n, m;
ll GCD(ll a, ll b) {
	if(!b)
		return a;
	return GCD(b, a%b);
}
ll LCM(ll a, ll b) {
	return a*b/ GCD(a, b);
}
vector<int>v;

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	while(scanf("%d%d", &n, &m) > 0) {
		v.clear(); v.resize(m);
		for(int i = 0; i < m; ++i)
			scanf("%d", &v[i]);
		ll ans = 0;
		for(int i = 0; i < (1 << m); ++i) {
			ll lcm = 1;
			int cnt = 0;
			for(int j = 0; j < m; ++j) {
				if(!((i >> j) & 1))
					continue;
				++cnt;
				lcm = LCM(lcm, v[j]);
			}
			if(cnt & 1)
				ans -= n / lcm;
			else
				ans += n / lcm;
		}
		printf("%lld\n", ans);
	}


#ifdef MYDEF
	//printTime;
#endif
	return 0;
}

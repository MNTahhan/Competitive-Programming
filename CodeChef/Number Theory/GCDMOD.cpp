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

/*
GCD(A, B) = GCD(A % B, B)
GCD(A % M, B % M) != GCD(A, B) % M
*/
const int M = 1e9 + 7;
ll a, b, n;
ll gcd(ll a, ll b) {
	if(!b)
		return a;
	return gcd(b, a%b);
}
ll prod(ll a, ll b, ll MOD) {
	ll x = 0, y = a;
	while(b) {
		if(b & 1)
			x = (x + y) % MOD;
		y = (y + y) % MOD;
		b >>= 1;
	}
	return x;
}
ll powe(ll x, ll y, ll MOD) {
	if(!y)
		return 1;
	ll z = powe(x, y >> 1, MOD) % MOD;
	z = prod(z, z, MOD) % MOD;
	if(y & 1)
		z = prod(x, z, MOD) % MOD;
	return z;
}

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld%lld%lld", &a, &b, &n);
		ll MOD = a == b ? M : abs(a - b);
		ll x = (powe(a, n, MOD) + powe(b, n, MOD)) % MOD; 
		printf("%lld\n", gcd(x, abs(a - b)));
	}
	
#ifdef MYDEF
	printTime;
#endif
	return 0;
}

/* number of spanning trees in complete graph = n^(n-2) */
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

const int M = 2000000011;
int n;

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i) {
		scanf("%d", &n);
		ll res = n < 3 ? 1 : n;
		for(int i = 1; i < n - 2; ++i)
			res = res * n%M;
		printf("Case #%d: %d\n", i, res);
	}
	
	
#ifdef MYDEF
	printTime;
#endif
	return 0;
}

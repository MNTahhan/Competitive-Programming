/*
  The idea: try every possibility with dp.
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

char s[100];
int n, dp[5][5][5][5][5][5];
int v[10];
int calc(int t) {
	int sum = 0;
	for (int i = 1; i <= 6; ++i)
		sum += (4 - v[i]) * i;
	if (sum > 31)
		return t;
	int &ret = dp[v[1]][v[2]][v[3]][v[4]][v[5]][v[6]];
	if (~ret)
		return ret;
	ret = !t;
	for (int i = 1; i <= 6 && ret == !t; ++i)
		if (v[i]) {
			--v[i];
			if (calc(t ^ 1) != !t)
				ret = t;
			++v[i];
		}
	return ret;
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	while (scanf("%s", s) > 0) {
		memset(dp, -1, sizeof dp);
		for (int i = 1; i <= 6; ++i)
			v[i] = 4;
		n = strlen(s);
		for (int i = 0; i < n; ++i) 
			--v[s[i] - '0'];
		printf("%s %c\n", s, calc(n & 1) ? 'B' : 'A');
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

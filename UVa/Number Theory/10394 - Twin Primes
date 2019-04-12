/* primes, sieve */

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

const int N = 50000010;
bool num[N];

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	vector<int>v;
	for(ll i = 2; i < N; ++i)
		if(!num[i]) {
			v.push_back(i);
			for(ll j = i * i; j < N; j += i)
				num[j] = 1;
		}
	vector<int>ans;
	for(int i = 1; i < v.size(); ++i) {
		if(v[i] - v[i - 1] == 2)
			ans.push_back(v[i]);
	}
	int n;
	while(scanf("%d", &n) > 0) {
		printf("(%d, %d)\n", ans[n - 1] - 2, ans[n - 1]);
	}


#ifdef MYDEF
	printTime;
#endif
	return 0;
}

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
	num[1] = 1;
	for(ll i = 2; i < N; ++i)
		if(!num[i]) {
			v.push_back(i);
			for(ll j = i * i; j < N; j += i)
				num[j] = 1;
		}
	int n;
	while(scanf("%d", &n) > 0) {
		if(n <= 7) {
			puts("Impossible.");
			continue;
		}
		int a, b, c, d;
		if(n & 1) {
			a = 3;
			b = 2;
			n -= 5;
		}
		else {
			a = b = 2;
			n -= 4;
		}
		for(int i = 2; i < n; ++i)
			if(!num[i] && !num[n - i]) {
				c = i;
				d = n - i;
				break;
			}
		printf("%d %d %d %d\n", a, b, c, d);
	}


#ifdef MYDEF
	printTime;
#endif
	return 0;
}

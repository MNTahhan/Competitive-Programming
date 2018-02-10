/*
  The idea: line sweep. if one tower is less than two towers surrounding it, then it will increase the number of components when its
            flooded, if it is larger than them, then it will decrease the number of components when it is flooded, the first and last
            tower will decrease the components it they were larger than surrounding towers. maintain a line that moves vertically 
            to the top, increase & decrease the answer depending on the flooded tower.
*/
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
typedef complex<double> point;

const int N = 1e6 + 10;
vector<pair<int, int> >v;
int n, d, a[N], t[N];

int main() {
#ifdef MYDEF
	FILE *file__r = fopen("header.txt", "r"); 
	char __[110]; while(fgets(__, sizeof __, file__r) != NULL) printf("%s", __);
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int T;
	scanf("%d", &T);
	while(T--) {
		v.clear();
		scanf("%d%d", &n, &d);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			if(i && a[i] == a[i - 1]) {
				--i;
				--n;
			}
		}
		for(int i = 0; i < d; ++i)
			scanf("%d", &t[i]);
		if(n > 1 && a[0] > a[1])
			v.push_back(make_pair(a[0], -1));
		else if(n == 1)
			v.push_back(make_pair(a[0], -1));
		for(int i = 1; i + 1 < n; ++i)
			if(a[i] < a[i - 1] && a[i] < a[i + 1])
				v.push_back(make_pair(a[i], 1));
			else if(a[i] > a[i - 1] && a[i] > a[i + 1])
				v.push_back(make_pair(a[i], -1));
		if(n > 1 && a[n - 1] > a[n - 2])
			v.push_back(make_pair(a[n - 1], -1));
		sort(v.begin(), v.end());
		int idx = 0;
		int ans = 1;
		for(int i = 0; i < d; ++i) {
			while(idx < v.size() && v[idx].first <= t[i])
				ans += v[idx++].second;
			printf("%d%s", ans, i + 1 == d ? "\n" : " ");
		}
	}

#ifdef MYDEF
	printTime;
#endif
	return 0;
}

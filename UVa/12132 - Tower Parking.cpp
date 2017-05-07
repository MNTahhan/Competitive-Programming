/*
	The idea: brute force.
	pos[i]: the level number of the car i
	when you wnat to get the i-th car, edit the numbers this level to represent the new positions of the cars
*/
#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <cstring>
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
#include <numeric>
#include <iomanip>
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

int n, h, l;
vector<vector<int> >v;
int pos[50 * 50 + 10];

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		n = 0;
		scanf("%d%d", &h, &l);
		v.clear();
		v.resize(h + 1);
		for (int i = 1; i <= h; ++i) {
			v[i].resize(l + 1);
			for (int j = 1; j <= l; ++j) {
				scanf("%d", &v[i][j]);
				if (v[i][j] == -1)
					continue;
				pos[v[i][j]] = i;
				n = max(n, v[i][j]);
			}
		}
		int ans = 0, mid = (l + 1) / 2;
		for (int i = 1; i <= n; ++i) {
			ans += 20 * (pos[i] - 1);
			for (int j = 1; j <= l; ++j)
				if (v[pos[i]][j] == i) {
					if (j <= mid) {
						ans += 5 * (j - 1);
						vector<int>tmp(l + 1);
						for (int e = 1; e <= l; ++e)
							tmp[e - (j - 1) <= 0 ? e - (j - 1) + l : e - (j - 1)] = v[pos[i]][e];
						v[pos[i]].swap(tmp);
					} else {
						ans += (l - j + 1) * 5;
						vector<int>tmp(l + 1);
						for (int e = 1; e <= l; ++e)
							tmp[e + (l - j + 1) > l ? (e + (l - j + 1)) - l : e + (l - j + 1)] = v[pos[i]][e];
						v[pos[i]].swap(tmp);
					}
					break;
				}
		}
		printf("%d\n", ans);
	}



#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

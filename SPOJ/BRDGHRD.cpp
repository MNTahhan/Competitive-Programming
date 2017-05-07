/*
	sort + LIS
	The idea: compine the two sides and sort according to one of them, then make LIS on the other
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

int n, a[100010], b[100010];

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		for (int i = 0; i < n; ++i)
			scanf("%d", b + i);
		vector<pair<int, int> >v;
		for (int i = 0; i < n; ++i)
			v.push_back({ a[i],b[i] });
		sort(v.begin(), v.end());
		vector<int>lis;
		for (int i = 0; i < n; ++i) {
			int idx = upper_bound(lis.begin(), lis.end(), v[i].second) - lis.begin();
			if (idx == lis.size())
				lis.push_back(v[i].second);
			else
				lis[idx] = v[i].second;
		}
		printf("%d\n", lis.size());
	}



#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
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
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

int n;
vector<pair<int, int> >v;

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	while (scanf("%d", &n) > 0 && n) {
		v.clear();
		for (int i = 0, x, y; i < n; ++i) {
			scanf("%d%d", &x, &y);
			v.push_back({ x,y });
		}
		int x = v[n / 2].first;
		int y = v[n / 2].second;
		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i].first > x && v[i].second > y || v[i].first < x && v[i].second < y)
				++ans1;
			else if(v[i].first < x && v[i].second > y || v[i].first > x && v[i].second < y)
				++ans2;
		}
		printf("%d %d\n", ans1, ans2);
	}



#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

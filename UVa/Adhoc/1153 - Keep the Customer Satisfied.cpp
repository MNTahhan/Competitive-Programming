/*
  The idea: sort the items by the nearest due time in the future, if two customers has the same due date, put the one with the lowest
            processing time first, then try to simulate the process, take every element in the previous order and add its processing 
            time to a priority queue, if the total processing time for all of the items is larger than the current due time, erase
            the customer who needs the largest processing time.
*/
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


int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		vector<pair<int, int> >v;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			v.push_back({y,x});
		}
		sort(v.begin(), v.end());
		int ans = 0;
		int ttl = 0;
		priority_queue<int>q;
		for (int i = 0; i < n; ++i) {
			ttl += v[i].second;
			q.push(v[i].second);
			if (ttl> v[i].first) {
				ttl -= q.top();
				q.pop();
			}
		}
		printf("%d\n", q.size());
		if (t)
			puts("");
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

/* 
  The idea: factoriaze the perfert squares numbers only, and save for each k the numbers that have k divisors
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

int n;
bool num[100010];
vector<int> p;
vector<ll> ans[10010];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
//	freopen("a.txt", "w", stdout);
	decTime;
#endif

	for (int i = 2; i * i < 100010; ++i)
		if (!num[i])
			for (int j = i * i; j < 100010; j += i)
				num[j] = 1;
	for (int i = 2; i < 100010; ++i)
		if (!num[i])
			p.push_back(i);
	vector<ll> v;
	for (int cur = 2; cur <= 100000; ++cur) {
		int x = cur; // there is a relation between factorazation of N and N^2
		int d = 1;
		for (int j = 0; j < p.size() && p[j] < x; ++j) {
			int cnt = 0;
			while (x % p[j] == 0) {
				++cnt;
				x /= p[j];
			}
			d *= 2 * cnt + 1;
		}
		if (x > 1)
			d *= 3;
		ans[d].push_back(cur * 1LL * cur);
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int k;
		ll lo, hi;
		scanf("%d%lld%lld", &k, &lo, &hi);
		lo = lower_bound(ans[k].begin(), ans[k].end(), lo) - ans[k].begin();
		hi = upper_bound(ans[k].begin(), ans[k].end(), hi) - ans[k].begin();
		printf("%d\n", hi - lo);
	}

#ifndef ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

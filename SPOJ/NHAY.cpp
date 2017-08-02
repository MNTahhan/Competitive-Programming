/*
  The idea: KMP
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

	int n, p = 0;
	while (scanf("%d", &n) > 0) {
		string s;
		cin >> s;
		vector<int>f(s.size());
		for (int i = 1, k = 0; i < n; ++i) {
			while (k && s[k] != s[i])
				k = f[k - 1];
			if (s[k] == s[i])
				f[i] = ++k;
			else
				f[i] = k;
		}
		int k = 0, i = -1;
		char c;
		vector<int>ans;
		cin.ignore();
		while ((c = getchar()) && c != '\n') {
			++i;
			while (k && s[k] != c)
				k = f[k - 1];
			if (s[k] == c)
				++k;
			if (k == s.size()) {
				ans.push_back(i - k + 1);
				k = f[k - 1];
			}
		}
		if (ans.size() && p)
			puts("");
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d\n", ans[i]);
			p = 1;
		}
	}
	
#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

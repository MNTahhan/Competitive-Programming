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
#include <complex>
#include <numeric>
#include <iomanip>
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

char s[1010];
int k;

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s%d",s, &k);
		int n = strlen(s);
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			int cur = 1;
			int tmp = k;
			for(int l = i - 1, r = i + 1; l >= 0 && r < n && (s[l] == s[r] || tmp--); ++r, --l)
				cur += 2;
			ans = max(ans, cur);
			cur = 0;
			tmp = k;
			for(int l = i, r = i + 1; l >= 0 && r < n && (s[l] == s[r] || tmp--); ++r, --l)
				++cur;
			ans = max(ans, cur * 2);
		}
		printf("%d\n", ans);
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

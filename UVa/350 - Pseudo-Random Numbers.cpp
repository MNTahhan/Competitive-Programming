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

int vis[10010];

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int L, M, Z, I, h = 1;
	while(scanf("%d%d%d%d", &Z, &I, &M, &L) > 0 && (M || L || Z || I)) {
		memset(vis, 0, sizeof vis);
		int cnt = 1, to = (Z*L + I) % M, x, last;
		while(!(x = vis[to])) {
			vis[to] = cnt++;
			last = vis[to];
			to = (Z*to + I) % M;
		}
		printf("Case %d: %d\n", h++, last - x + 1);
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

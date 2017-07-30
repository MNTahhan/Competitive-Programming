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

int cnt[100010];

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;++i) {
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	for(int i=1;i<=n;++i)
		printf("%.2lf%%\n", 1.0*cnt[i] / m * 100.0);


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

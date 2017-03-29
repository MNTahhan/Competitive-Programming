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

const int M = 2000000011;
int p(int x, int e) {
	if(e == 0)
		return 1;
	int z = p(x, e >> 1) % M;
	z = z*1LL*z%M;
	if(e & 1)
		z = z*1LL*x%M;
	return z;
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int t, h = 1;
	scanf("%d", &t);
	while(t--) {
		int x;
		scanf("%d", &x);
		printf("Case #%d: %d\n", h++, p(x, max(0, x - 2)));
	}



#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

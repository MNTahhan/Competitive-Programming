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


int n;
const int N = 1000010;
bitset<N>num, mark;
vector<int>v;


int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	num[0] = num[1] = 1;
	for(int i = 2; i * 1LL * i < N; ++i)
		if(!num[i])
			for(int j = i*i; j < N; j += i)
				num[j] = 1;
	for(int i = 0; i < 4; ++i)
		mark[i] = 1;
	for(int i = 4; i < N; ++i)
		if(num[i] && !mark[i]) {
			for(int j = i + i; j < N; j += i)
				mark[j] = 1;
		}
	while(scanf("%d", &n) > 0) {
		int ans = 0;
		while(n--) {
			int x;
			scanf("%d", &x);
			assert(x < N);
			ans += !mark[x] && num[x];
		}
		printf("%d\n", ans);
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

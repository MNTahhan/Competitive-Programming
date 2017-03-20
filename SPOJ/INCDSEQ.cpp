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

const int N = 1e4 + 10;
const int M = 5e6;
int n, a[N];
int BIT[55][N];
void add(int idx, int val,int *BIT) {
	while(idx < N) {
		BIT[idx] += val;
		if(BIT[idx] >= M)
			BIT[idx] -= M;
		idx += idx&-idx;
	}
}
int get(int idx,int *BIT) {
	int res = 0;
	while(idx) {
		res += BIT[idx];
		if(res >= M)
			res -= M;
		idx -= idx&-idx;
	}
	return res;
}


int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	vector<int>v;
	for(int i = 1; i <= n; ++i)
		v.push_back(a[i]);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for(int i = 1; i <= n; ++i)
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	for(int i = 1; i <= n; ++i) {
		if(get(a[i],BIT[1])-get(a[i]-1,BIT[1])==0)
			add(a[i], 1, BIT[1]);
		for(int j = 2; j <= k; ++j) {
			int v1 = get(a[i] - 1, BIT[j - 1]);
			int v2 = get(a[i], BIT[j]) - get(a[i] - 1, BIT[j]);
			if(v2 < 0)
				v2 = (v2 + M) % M;
			if(v1 - v2 >= 0)
				add(a[i], v1 - v2, BIT[j]);
			else
				add(a[i], v1 - v2 + M, BIT[j]);
		}
	}
	printf("%d\n", get(N - 1,BIT[k]));


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

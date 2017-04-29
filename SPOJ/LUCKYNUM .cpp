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

bool cmp(const pair<int,int> &a, const pair<int,int>&b){
	if (a.first + a.second != b.first + b.second)
		return a.first + a.second < b.first + b.second;
	return a.first <= b.first;
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d", &x);
		vector<pair<int,int> >v;
		for (int i = 0; i <= 200; ++i) {
			int mod = 0;
			for (int k = 0; k < i; ++k)
				mod = (mod * 10 + 8) % x;
			for (int j = 0; j + i <= 200; ++j) {
				int tmp = mod;
				for (int k = 0; k < j; ++k)
					tmp = (tmp * 10 + 6) % x;
				if (!tmp && i + j)
					v.push_back({ i,j });
			}
		}
		sort(v.begin(), v.end(), cmp);
		if (!v.size())
			puts("-1");
		else
			printf("%s%s\n", string(v[0].first, '8').c_str(),string(v[0].second,'6').c_str());
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

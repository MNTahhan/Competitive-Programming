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

char s[1 << 10];
int f[1 << 10];

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	decTime;
#endif

	vector<string>v;
	string s = "";
	char c;
	while((c = getchar()) && c != -1) {
		if(c == '\r' || c == '\n') {
			v.push_back(s);
			s = "";
			continue;
		}
		s += c;
	}
	if(s.size())
		v.push_back(s);
	for(int k = 0; k < v.size(); ++k) {
		memset(f, 0, sizeof f);
		int n = v[k].size();
		string s = v[k];
		for(int i = 0; i < n; ++i)
			++f[s[i]];
		vector<pair<int, int> >ans;
		for(int i = 0; i < 500; ++i)
			if(f[i])
				ans.push_back({ f[i],-i });
		sort(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); ++i)
			printf("%d %d\n", -ans[i].second, ans[i].first);
		if(k + 1 < v.size())
			puts("");
	}

	return 0;
#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

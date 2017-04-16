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

struct node {
	int r, g, b;
	node() { }
	node(int r, int g, int b):r(r), g(g), b(b) { }
};
vector<node>v;

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	for(int i = 0; i < 16; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v.push_back(node(a, b, c));
	}
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c) > 0 && (a != -1)) {
		double ans = 1 << 30;
		int idx = -1;
		for(int i = 0; i < v.size(); ++i) {
			double d = sqrt((v[i].r - a)*(v[i].r - a) + (v[i].g - b)*(v[i].g - b) + (v[i].b-c)*(v[i].b-c));
			if(d < ans) {
				ans = d;
				idx = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", a, b, c, v[idx].r, v[idx].g, v[idx].b);
	}
	


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

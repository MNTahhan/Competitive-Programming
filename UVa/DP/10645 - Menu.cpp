/*
  the state is: [the current day][the remaining cost][index of last selected item][how many times did we select it]
  in each state loop over the items and try each one, you must make sure that taking this item will lead to complete menu, that is why
  we return a pair, <flag it has reached the end, the value returned>
*/
#define _CRT_SECURE_NO_WARNINGS
#ifdef MYDEF
//#pragma optimize( "/Od", off )  
//#pragma optimize( "/Oa", off )  
//#pragma optimize( "/Og", off )  
//#pragma optimize( "/Oi", off )  
#endif
#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
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
#ifdef MYDEF
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

int n, m, k, vis[25][110][55][3];
pair<int,double> dp[25][110][55][3];
struct node {
	int first, second, idx;
	node() { }
	node(int first, int second, int idx):first(first), second(second), idx(idx) { }
	inline bool operator<(const node &e)const {
		if(first != e.first)
			return first < e.first;
		return second < e.second;
	}
};
vector<node>v;
vector<int>p;
pair<int,double> calc(int d, int rem, int last, int cnt) {
	if(d == k)
		return make_pair(1, 0);
	pair<int,double> &ret = dp[d][rem][last][cnt];
	int &vs = vis[d][rem][last][cnt];
	if(vs)
		return ret;
	vs = 1;
	ret = make_pair(0, 0);
	for(int i = 0; i < n; ++i) {
		if(v[i].first > rem)
			continue;
		int cur = 0;
		double ratio = 1;
		if(i == last) {
			cur = cnt;
			if(cur == 2)
				ratio = 0;
			else if(cur == 1) {
				ratio = .5;
				cur = 2;
			}
			else
				cur = 1;
		}
		else
			cur = 1;
		pair<int, double>tmp = calc(d + 1, rem - v[i].first, i, cur);
		if(tmp.first) {
			ret.first = 1;
			ret.second = max(ret.second, ratio * v[i].second + tmp.second);
		}
	}
	return ret;
}
void path(int d, int rem, int last, int cnt) {
	if(d == k)
		return;
	pair<int, double> op = calc(d, rem, last, cnt);
	for(int i = 0; i < n; ++i) {
		if(v[i].first > rem)
			continue;
		int cur = 0;
		double ratio = 1;
		if(i == last) {
			cur = cnt;
			if(cur == 2)
				ratio = 0;
			else if(cur == 1) {
				ratio = .5;
				++cur;
			}
			else
				cur = 1;
		}
		else
			cur = 1;
		pair<int, double>tmp = calc(d + 1, rem - v[i].first, i, cur);
		if(tmp.first) {
			tmp.second += ratio * v[i].second;
			if(tmp.first == op.first && fabs(tmp.second - op.second) < 1e-9) {
				p.push_back(v[i].idx);
				path(d + 1, rem - v[i].first, i, cur);
				return;
			}
		}
	}
}

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	while(scanf("%d%d%d", &k, &n, &m) > 0 && (k || n || m)) {
		v.clear();
		v.resize(n);
		p.clear();
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &v[i].first, &v[i].second), v[i].idx = i;
		sort(v.begin(), v.end());
		printf("%.1lf\n", calc(0, m, n, 0).second);
		path(0, m, n, 0);
		for(int i = 0; p.size() == k && i < p.size(); ++i)
			printf("%d%s", p[i] + 1, i + 1 == p.size() ? "" : " ");
		puts("");
	}
	

#ifdef MYDEF
	printTime;
#endif
	return 0;
}

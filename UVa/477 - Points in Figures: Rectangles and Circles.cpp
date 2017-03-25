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

typedef pair<double, double> pd;
vector<pair<int, pair<pd, pd> > >rec;
vector<pair<int, pair<double, pd> > >cir;

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	char c;
	int id = 1;
	while(scanf(" \n%c", &c) > 0 && c != '*') {
		if(c == 'r') {
			double x, y, a, b;
			scanf("%lf%lf%lf%lf", &x, &y, &a, &b);
			rec.push_back({ id++,{ {x,y},{a,b} } });
		} else {
			double r, x, y;
			scanf("%lf%lf%lf", &x, &y, &r);
			cir.push_back({ id++,{ r,{x,y}} });
		}
	}
	double x, y;
	int h = 1;
	while(scanf("%lf%lf", &x, &y) > 0 && (fabs(x - 9999.9) > 1e-9 || fabs(y - 9999.9) > 1e-9)) {
		bool flag = false;
		for(int i = 0; i < rec.size(); ++i) {
			double a = rec[i].second.first.first;
			double b = rec[i].second.first.second;
			double r = rec[i].second.second.first;
			double e = rec[i].second.second.second;
			if(x > a && x < r && y > e && y < b)
				printf("Point %d is contained in figure %d\n", h, rec[i].first), flag = true;
		}
		for(int i = 0; i < cir.size(); ++i) {
			double a = cir[i].second.second.first;
			double b = cir[i].second.second.second;
			double r = cir[i].second.first;
			if(sqrt((x - a)*(x - a) + (y - b)*(y - b)) < r)
				printf("Point %d is contained in figure %d\n", h, cir[i].first), flag = true;
		}
		if(!flag)
			printf("Point %d is not contained in any figure\n", h);
		++h;
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

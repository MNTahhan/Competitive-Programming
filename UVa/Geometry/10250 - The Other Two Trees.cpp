/*
  The idea is explained here: http://www.questtosolve.com/browse.php?pid=10250
*/
#define _CRT_SECURE_NO_WARNINGS
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

double a, b, x, y, mx, my, ax, ay, aa, ab, d;

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	while(scanf("%lf%lf%lf%lf", &x, &y, &a, &b) > 0) {
		mx = (x + a) / 2.;
		my = (y + b) / 2.;
		double dx = x - mx;
		double dy = y - my;
		ax = mx + dy;
		ay = my - dx;
		aa = mx - dy;
		ab = my + dx;
		printf("%.12lf %.12lf %.12lf %.12lf\n", ax, ay, aa, ab);
	}
	
	

#ifdef MYDEF
	printTime;
#endif
	return 0;
}

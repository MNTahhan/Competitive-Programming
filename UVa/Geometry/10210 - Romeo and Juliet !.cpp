/*
  The same solution explained here: http://uvacode.blogspot.com/2011/05/hints-for-uva-problem-set-10200.html
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

double x[2], y[2], d1, d2;
#define PI acos(-1)
double rad(double d) {
	return d * PI / 180.;
}

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	while(scanf("%lf%lf%lf%lf%lf%lf", x, y, x + 1, y + 1, &d1, &d2) > 0) {
		double dis = sqrt((x[0] - x[1])*(x[0] - x[1]) + (y[0] - y[1])*(y[0] - y[1]));
		printf("%.3lf\n", dis / tan(rad(d1)) + dis / tan(rad(d2)));
	}


#ifdef MYDEF
	printTime;
#endif
	return 0;
}

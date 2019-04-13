/*
let x = probability of choosing a cow then switch it to car
let y = probability of coosing a car then switch it to car
the answer = x + y
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


int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int cow, car, show;
	while(scanf("%d%d%d", &cow, &car, &show) > 0) {
		int total = cow + car;
		int a = cow * car;
		int b = (cow + car) * (cow + car - show - 1);
		int c = car * (car - 1);
		int d = (cow + car) * (cow + car - show - 1);
		double ans = 1.*a / b + 1.*c / d;
		printf("%.5lf\n", ans);
	}

#ifdef MYDEF
	printTime;
#endif
	return 0;
}

/*
  get the center of the polygon, then compare the distance with each point of the polygon
  https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/UVA/UVA_10005.txt
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

int n;
int x[110], y[110];
double r;
double dis(int a, int b, int idx) {
	return sqrt((a - x[idx])*(a - x[idx]) + (b - y[idx])*(b - y[idx]));
}

int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	while(scanf("%d", &n) > 0 && n) {
		double a = 0, b = 0;
		for(int i = 0; i < n; ++i)
			scanf("%d%d", x + i, y + i), a += x[i], b += y[i];
		scanf("%lf", &r);
		a /= 1.*n;
		b /= 1.*n;
		int flag = 1;
		for(int i = 0; flag && i < n; ++i)
			if(dis(a, b, i) > r)
				flag = 0;
		puts(flag ? "The polygon can be packed in the circle." : "There is no way of packing that polygon.");
	}
	
	

#ifdef MYDEF
	printTime;
#endif
	return 0;
}

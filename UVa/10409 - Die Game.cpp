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



int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int t;
	while(scanf("%d", &t) > 0 && t) {
		int top = 1, north = 2, west = 3, east = 4, south = 5, bottom = 6;
		while(t--) {
			char s[10];
			scanf("%s", s);
			int nnorth = north, nsouth = south, neast = east, nwest = west, ntop = top, nbottom = bottom;
			if(strcmp(s, "north") == 0) {
				nnorth = top;
				nbottom = north;
				nsouth = bottom;
				ntop = south;
			} else if(strcmp(s, "south") == 0) {
				nsouth = top;
				nbottom = south;
				nnorth = bottom;
				ntop = north;
			} else if(strcmp(s, "east") == 0) {
				neast = top;
				nbottom = east;
				nwest = bottom;
				ntop = west;
			} else {
				nwest = top;
				nbottom = west;
				neast = bottom;
				ntop = east;
			}
			east = neast;
			west = nwest;
			south = nsouth;
			north = nnorth;
			top = ntop;
			bottom = nbottom;
		}
		printf("%d\n", top);
	}

#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

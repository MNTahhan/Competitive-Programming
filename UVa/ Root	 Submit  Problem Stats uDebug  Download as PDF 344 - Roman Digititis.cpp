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

int val[] = { 1,4,5,9,10,40,50,90,100 };
string cur[] = { "i","iv","v","ix","x","xl","l","xc","c" };

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int sz = sizeof(val) / sizeof(int);
	int in;
	while(scanf("%d", &in) > 0 && in) {
		int y = in;
		int i = 0, v = 0, c = 0, x = 0, l = 0;
		string s = "";
		for(int k = 1; k <= in; ++k) {
			int tmp = k;
			while(tmp) {
				for(int i = sz - 1; i >= 0; --i)
					if(val[i] <= tmp) {
						s += cur[i];
						tmp -= val[i];
						break;
					}
			}
		}
		for(int j = 0; j < s.size(); ++j) {
			i += s[j] == 'i';
			v += s[j] == 'v';
			c += s[j] == 'c';
			x += s[j] == 'x';
			l += s[j] == 'l';
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", y, i, v, x, l, c);
	}

#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

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
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	string s;
	while(getline(cin, s)) {
		string res = "";
		for(int i = 0; i < s.size(); ++i) {
			if(!isalpha(s[i])) {
				res += s[i];
				continue;
			}
			int j;
			string tmp = "";
			for(j = i; j < s.size() && isalpha(s[j]); ++j)
				tmp += s[j], i = j;
			if((tmp[0] | 32) == 'a' || (tmp[0] | 32) == 'e' || (tmp[0] | 32) == 'i' || (tmp[0] | 32) == 'o' || (tmp[0] | 32) == 'u') {
				tmp += "ay";
				res += tmp;
				continue;
			}
			tmp += tmp[0];
			tmp.erase(0, 1);
			tmp += "ay";
			res += tmp;
		}
		puts(res.c_str());
	}


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

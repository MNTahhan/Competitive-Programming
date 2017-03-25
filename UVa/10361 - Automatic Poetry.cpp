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

string s, r;

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	cin.ignore();
	while(t--) {
		getline(cin, s);
		getline(cin, r);
		string s1 = "", s2 = "", s3 = "", s4 = "", s5 = "";
		for(int i = r.size() - 1; i >= 0; --i)
			if(r[i] == '.')
				r.erase(i, 1);
		int i = 0;
		while(s[i] != '<') {
			s1 += s[i];
			++i;
		}
		++i;
		while(s[i] != '>') {
			s2 += s[i];
			++i;
		}
		++i;
		while(s[i] != '<') {
			s3 += s[i];
			++i;
		}
		++i;
		while(s[i] != '>') {
			s4 += s[i];
			++i;
		}
		++i;
		while(i < s.size()) {
			s5 += s[i];
			++i;
		}
		r += s4;
		r += s3;
		r += s2;
		r += s5;
		for(int i = 0; i < s.size(); ++i)
			if(s[i] != '<' && s[i] != '>')
				printf("%c", s[i]);
		puts("");
		puts(r.c_str());
	}

#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

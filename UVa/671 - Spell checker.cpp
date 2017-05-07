/*
	The idea: brute force, first try to the find the word as is, if it not exist then try to match the word with every dictionary
		  word after each one of the following operations:
		  1) delete a letter from the current word.
		  2) delete a letter from the dictionary-word (equivilant to inserting that letter in the current word)
		  3) match the words if they have the same length and there is one character differs between them. (replace operation)
*/
#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <cstring>
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

char s[20];

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		vector<string>v;
		while (scanf("%s", s) > 0 && strcmp(s, "#"))
			v.push_back(s);
		while (scanf("%s", s) > 0 && strcmp(s, "#")) {
			printf("%s", s);
			int n = strlen(s);
			string ans = "";
			bool r = true;
			for (int i = 0; i < v.size(); ++i)
				if (strcmp(s, v[i].c_str()) == 0) {
					ans = " is correct";
					r = false;
					break;
				}
			if (r)
				putchar(':');
			for (int i = 0; i < v.size() && r; ++i) {
				bool flag = false;
				int cnt = 0;
				for (int j = 0; j < n && n == v[i].size(); ++j)
					cnt += s[j] != v[i][j];
				if (n == v[i].size() && cnt == 1) {
					ans += " " + v[i];
					continue;
				}
				for (int del = 0; del < v[i].size(); ++del) {
					string tmp = v[i]; tmp.erase(del, 1);
					if (strcmp(s, tmp.c_str()) == 0) {
						ans += " " + v[i];
						flag = true;
						break;
					}
				}
				if (flag)
					continue;
				for (int del = 0; del < n; ++del) {
					string tmp = s; tmp.erase(del, 1);
					if (tmp == v[i]) {
						ans += " " + v[i];
						break;
					}
				}
			}
			puts(ans.c_str());
		}
		if (t)
			puts("");
	}



#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

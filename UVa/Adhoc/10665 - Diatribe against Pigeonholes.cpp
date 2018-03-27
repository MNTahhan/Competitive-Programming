/*
  first, sort them in desc. order, then try to put the heaviest two items in most far position from each other, when you put the left
  one get the instance of it which have the smallest letter, and for the right one get the instance with the largest letter.
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

char s[110];
int n, w, f[30];


int main() {
#ifdef MYDEF
	HEAD;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%s", &w, s);
		n = strlen(s) - 1;
		memset(f, 0, sizeof f);
		for(int i = 0; i < n; ++i)
			++f[s[i] - 'A'];
		vector<pair<int, char> >v;
		for(int i = 0; i < w; ++i)
			v.push_back({f[i],i + 'A'});
		sort(v.rbegin(), v.rend());
		vector<pair<int, char> >ans(w);
		for(int k = 0; k < w && v.size(); ++k) {
			if(v.size() == 1) {
				ans[k] = v[0];
				break;
			}
			int x = v[0].first;
			int y = v[1].first;
			char c = 'Z' + 1;
			int idx = -1;
			int flag = -1;
			for(int i = 0; i < v.size(); ++i) {
				if(v[i].first == x && v[i].second < c) {
					c = v[i].second;
					idx = i;
					flag = 0;
				}
				if(v[i].first == y && v[i].second < c) {
					c = v[i].second;
					idx = i;
					flag = 1;
				}
			}
			ans[k] = v[idx];
			v.erase(v.begin() + idx);
			if(flag == 0)
				x = -1;
			else if(flag == 1)
				y = -1;
			c = 'A' - 1;
			idx = -1;
			for(int i = 0; i < v.size(); ++i) {
				if((v[i].first == x || v[i].first == y) && v[i].second > c) {
					c = v[i].second;
					idx = i;
				}
			}
			ans[w - k - 1] = v[idx];
			v.erase(v.begin() + idx);
		}
		for(int i = 0; i < w; ++i)
			printf("%c%s", ans[i].second, i + 1 == w ? "\n" : " ");
		for(int i = 0; i < w; ++i)
			printf("%d%s", ans[i].first, i + 1 == w ? "\n" : " ");
	}



#ifdef MYDEF
	printTime;
#endif
	return 0;
}

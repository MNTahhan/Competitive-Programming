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

int n;
char s[11][11];
char r[11][11];
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1 };

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif

	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		for(int i = 0; i < n; ++i)
			scanf("%s", r[i]);
		bool flag = false;
		for(int i = 0; i < n && !flag; ++i)
			for(int j = 0; j < n && !flag; ++j)
				if(r[i][j] == 'x' && s[i][j] == '*')
					flag = true;
		for(int i = 0; i < n; ++i, puts(""))
			for(int j = 0; j < n; ++j)
				if(flag && s[i][j] == '*')
					printf("*");
				else if(!flag && s[i][j] == '*')
					printf(".");
				else if(r[i][j] == 'x') {
					int cnt = 0;
					for(int k = 0; k < 8; ++k) {
						int tx = dx[k] + i;
						int ty = dy[k] + j;
						if(tx < 0 || ty < 0 || tx >= n || ty >= n)
							continue;
						cnt += s[tx][ty] == '*';
					}
					printf("%d", cnt);
				} else
					printf(".");
		if(t)
			puts("");
	}
	


#if !ONLINE_JUDGE
	printTime;
#endif
	return 0;
}

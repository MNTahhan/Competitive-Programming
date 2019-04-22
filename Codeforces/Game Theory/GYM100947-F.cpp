// problem link: http://codeforces.com/gym/100947/problem/F

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
using namespace std;
typedef long long ll;

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
#endif
	
	int t;
	scanf("%d",&t);
	while(t--){
		int n,w,b;
		scanf("%d%d%d",&n,&w,&b);
		if((abs(w-b)-1)&1)
			puts("Steven");
		else
			puts("Mikael");
	}

	return 0;
}

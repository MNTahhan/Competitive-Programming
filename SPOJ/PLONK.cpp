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
#define print(x) cout<<#x<<" = "<<(x)<<endl

const int N = 100010;
int n;
ll cnt[2][N], sum[2][N];
void add(int idx,int val,ll *BIT){
	while(idx<N){
		BIT[idx]+=val;
		idx+=idx&-idx;
	}
}
ll get(int idx,ll *BIT){
	ll res=0;
	while(idx){
		res+=BIT[idx];
		idx-=idx&-idx;
	}
	return res;
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
#endif
	
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ll ans = 1LL<<60;
		memset(cnt,0,sizeof cnt);
		memset(sum,0,sizeof sum);
		vector<pair<int,int> >v;
		for(int i=0;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			++x;++y;
			v.push_back(make_pair(x,y));
			add(x,1,cnt[0]);
			add(y,1,cnt[1]);
			add(x,x,sum[0]);
			add(y,y,sum[1]);
		}
		for(int i=0;i<n;++i){
			int x = v[i].first;
			int y = v[i].second;
			ll cntL = get(x - 1,cnt[0]);
			ll sumL = get(x - 1,sum[0]);
			ll cntR = get(N - 1,cnt[0])-cntL-1;
			ll sumR = get(N,sum[0])-sumL-x;
			ll dis = cntL*x-sumL + sumR-cntR*x;
			cntL = get(y-1,cnt[1]);
			sumL = get(y-1,sum[1]);
			cntR = get(N-1,cnt[1])-cntL-1;
			sumR=get(N-1,sum[1])-sumL-y;
			dis+=cntL*y-sumL+sumR-cntR*y;
			ans=min(ans,dis);
		}
		printf("%lld\n",ans);
	}

	
	return 0;
}

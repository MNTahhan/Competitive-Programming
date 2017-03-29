/*
The idea: first sort the box's dimention, then sort the boxes according to their dimentions, then make the classical 0-1 dp.
*/


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

int k,n,dp[33][33],vis[33][33],vs;

// v is the array of boxes
// v[i].first is array of dimention for each box
// v[i].second is the index of the box
vector<pair<vector<int>, int> >v;

vector<int>ans;
int fit(int last,int at){
	for(int i=0;i<n;++i)
		if(v[at].first[i]<=v[last].first[i])
			return 0;
	return 1;
}
int calc(int at,int last){
	if(at==k)
		return 0;
	int &ret=dp[at][last];
	int &mem=vis[at][last];
	if(mem==vs)
		return ret;
	mem=vs;
	ret=calc(at+1,last);
	if(last==k || fit(last,at))
		ret=max(ret,1+calc(at+1,at));
	return ret;
}
void path(int at,int last){
	if(at==k)
		return;
	int op=calc(at,last);
	if(op==calc(at+1,last)){
		path(at+1,last);
		return;
	}
	ans.push_back(v[at].second);
	path(at+1,at);
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
#endif
	
	while(scanf("%d%d",&k,&n)>0){
		v.clear();
		for(int i=0;i<k;++i){
			vector<int>tmp;
			for(int j=0;j<n;++j){
				int x;
				scanf("%d",&x);
				tmp.push_back(x);		
			}
			sort(tmp.begin(),tmp.end());
			v.push_back(make_pair(tmp,i));
		}
		sort(v.begin(),v.end());
		++vs;
		printf("%d\n",calc(0,k));
		ans.clear();
		path(0,k);
		for(int i=0;i<ans.size();++i)
			printf("%d%s",ans[i]+1,i+1==ans.size()?"\n":" ");
	}

	
	return 0;
}

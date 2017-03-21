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

const int N = 2e5 + 10;
int n,m,vis[N],vs;
vector<int>adj[N];
int DFS(int u,int no){
	if(vis[u]==vs || u == no)
		return 0;
	vis[u]=vs;
	int cnt=1;
	for(int i=0;i<adj[u].size();++i)
		cnt+=DFS(adj[u][i],no);
	return cnt;
}

int main() {
#if !ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
#endif

	for(int t=0;t<10;++t){
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;++i)
			adj[i].clear();
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			--u;--v;
			adj[u].push_back(v);
		}
		++vs;
		int len=DFS(0,-1);
		vector<int>ans;
		for(int i=0;i<n;++i){
			++vs;
			if(DFS(0,i)+1!=len)
				ans.push_back(i);
		}
		sort(ans.begin(),ans.end());
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i)
			printf("%d%s",ans[i]+1,i+1==ans.size()?"\n":" ");
	}

	return 0;
}

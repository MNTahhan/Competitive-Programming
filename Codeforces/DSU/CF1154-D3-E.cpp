#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k, a[N], ans[N], nxt[N], prv[N];
set<pair<int,int> >st;
int find(int x, int *p) {
	if(p[x] == x)
		return x;
	return p[x] = find(p[x], p);
}
int main() {
  //freopen("input.txt", "r", stdin);
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;++i)
		nxt[i] = prv[i] = i;
	for(int i=0;i<n;++i) {
		scanf("%d",a+i);
		st.insert(make_pair(a[i],i));
	}
	int cur = 1;
	int e = 0;
	while(st.size()) {
		auto it = --st.end();
		pair<int,int>mx = *it;
		st.erase(it);
		prv[mx.second] = find(mx.second-1, prv);
		nxt[mx.second] = find(mx.second+1, nxt);
		ans[mx.second] = cur;
		for(int i=find(mx.second-1, prv),j=0;j<k && i>=0;i=find(i-1, prv),++j) {
			auto it = st.lower_bound(make_pair(a[i], -1));
			if(it == st.end() || it->second != i)
				break;
			ans[it->second] = cur;
			prv[it->second] = find(it->second-1, prv);
			nxt[it->second] = find(it->second+1, nxt);
			st.erase(it);
      if(i == 0)
        break;
		}
		for(int i=find(mx.second+1, nxt),j=0;j<k && i<n;i=find(i+1, nxt),++j) {
			auto it = st.lower_bound(make_pair(a[i], -1));
			if(it == st.end() || it->second != i)
				break;
			ans[it->second] = cur;
			nxt[it->second] = find(it->second+1, nxt);
			prv[it->second] = find(it->second-1, prv);
			st.erase(it);
		}
		cur = 3 - cur;
	}
	for(int i=0;i<n;++i)
		printf("%d", ans[i]);
	puts("");
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,m,sz[N],dp[N],comp[N],cmp,idx[N],low[N],dfs,vis[N];
vector<int>adj[N],g[N],s;
void DFS(int u){
	idx[u]=low[u]=dfs++;
	vis[u]=1;
	s.push_back(u);
	for(int i=0;i<adj[u].size();++i){
		int v=adj[u][i];
		if(idx[v]==0)
			DFS(v);
		if(vis[v])
			low[u]=min(low[u],low[v]);
	}
	if(idx[u]==low[u]){
		int cnt=0;
		while(true){
			int v=s.back();
			s.pop_back();
			vis[v]=0;
			comp[v]=cmp;
			++cnt;
			if(v==u)
				break;
		}
		sz[cmp]=cnt;
		++cmp;
	}
}
int calc(int u){
	if(dp[u]==-1){
		dp[u]=0;
		for(int i=0;i<g[u].size();++i)
			dp[u]=max(dp[u],calc(g[u][i]));
		dp[u]+=sz[u];
	}
	return dp[u];
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<N;++i){
			adj[i].clear();
			g[i].clear();
			dp[i]=-1;
			sz[i]=0;
			idx[i]=0;
			vis[i]=0;
		}
		cmp=dfs=1;
		s.clear();
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			--u;--v;
			adj[u].push_back(v);
		}
		for(int i=0;i<n;++i)
			if(idx[i]==0)
				DFS(i);
		for(int u=0;u<n;++u)
			for(int i=0;i<adj[u].size();++i){
				int v=adj[u][i];
				if(comp[u]==comp[v])
					continue;
				g[comp[u]].push_back(comp[v]);
			}
		int ans=0;
		for(int i=1;i<=cmp;++i)
			ans=max(ans,calc(i));
		printf("%d\n",ans);
	}
	return 0;
}

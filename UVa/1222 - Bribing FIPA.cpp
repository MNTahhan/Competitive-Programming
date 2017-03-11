#include <bits/stdc++.h>
using namespace std;
const int N = 220;
int n,m,sz[N],vis[N],vs,idx,cost[N],root[N],dp[N][N];
vector<int>adj[N];
map<string,int>id;
char s[N];
int dfs(int u){
	if(vis[u]==vs)
		return 0;
	vis[u]=vs;
	sz[u]=1;
	for(int i=0;i<adj[u].size();++i)
		sz[u]+=dfs(adj[u][i]);
	return sz[u];
}
void calc(int u){
	if(vis[u]==vs)
		return;
	vis[u]=vs;
	dp[u][0]=0;
	for(int i=0;i<adj[u].size();++i)
		calc(adj[u][i]);
	for(int i=0;i<adj[u].size();++i){
		int v=adj[u][i];
		for(int j=sz[u]-1;j>0;--j) // -1 to exclude the current node
			for(int k=0;k<=sz[v];++k)
				// dp[u][j] -> cost of taking j nodes from the subtree of u
				// dp[u][j-k] -> cost of leaving k nodes from the j nodes of the subtree of u
				// dp[v][k] -> cost of taking those k nodes from the current son
				if(dp[u][j]>dp[u][j-k]+dp[v][k])
					dp[u][j]=dp[u][j-k]+dp[v][k];
	}
	dp[u][sz[u]]=cost[u];
}
int main() {
	while(scanf("%d%d",&n,&m)>0){
		id.clear();
		memset(dp,0x7f,sizeof dp);
		memset(sz,0,sizeof sz);
		memset(root,0,sizeof root);
		for(int i=0;i<=n;++i)
			adj[i].clear();
		idx=1;
		cin.ignore();
		for(int i=0;i<n;++i){
			string s;
			getline(cin,s);
			istringstream iss(s);
			string tmp;
			int x;
			iss>>tmp>>x;
			if(id.find(tmp)==id.end())
				id[tmp]=idx++;
			int u=id[tmp];
			cost[u]=x;
			while(iss>>tmp){
				if(id.find(tmp)==id.end())
					id[tmp]=idx++;
				int v=id[tmp];
				adj[u].push_back(v);
				root[v]=1;
			}
		}
		for(int i=1;i<=n;++i)
			if(!root[i])
				adj[0].push_back(i);
		++vs;
		dfs(0);
		++vs;
		calc(0);
		int ans=INT_MAX;
		for(int i=m;i<=n;++i)
			ans=min(ans,dp[0][i]);
		printf("%d\n",ans);
	}
	return 0;
}

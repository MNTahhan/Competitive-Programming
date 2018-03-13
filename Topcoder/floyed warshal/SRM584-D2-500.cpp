/*
  calculate the minimum distance between every two friends, the answer is d * maximum_distance, if it is diconnected graph, the answer
  is -1
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[55][55],vis[55];
vector<int>adj[55];
void DFS(int u){
		vis[u]=1;
		for(int i=0;i<adj[u].size();++i)
			if(!vis[adj[u][i]])
				DFS(adj[u][i]);
}
class Egalitarianism{
public:
		int maxDifference(vector <string> f, int d){
			int n = f.size();
			memset(dp,0x3f,sizeof dp);
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					if(f[i][j]=='Y'){
						dp[i][j]=1;
						adj[i].push_back(j);
					}
			for(int k=0;k<n;++k)
				for(int i=0;i<n;++i)
					for(int j=0;j<n;++j)
						dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			DFS(0);
			for(int i=0;i<n;++i)
				if(!vis[i])
					return -1;
			long long ans=0;
			for(int i=0;i<n;++i)
				for(int j=i+1;j<n;++j)
					ans=max(ans,dp[i][j]*d);
			return ans;
		}
};

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
#define print(x) cout<<#x<<" = "<<x<<endl
#define print2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
vector<int>adj[333];
int n,m,prv[333][333],vis[333],vs,val[333][333];
int dfs(int u){
	vis[u]=vs;
	for(int i=0;i<adj[u].size();++i){
		int v=adj[u][i];
		if(vis[v]==vs+1)
			continue;
		if(vis[v]==vs || dfs(v))
			return 1;
	}
	vis[u]=vs+1;
	return 0;
}
int main(){
	//freopen("a.txt","r",stdin);
	int h=1;
	while(scanf("%d%d",&n,&m)>0 && (n||m)){
		for(int i=0;i<=n;++i){
			adj[i].clear();
			//memset(prv,0,sizeof prv);
		}
		memset(prv,0,sizeof prv);
		int ans=0;
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			if(prv[u][v]){
				ans+=val[u][v];
				continue;
			}
			adj[u].push_back(v);
			vs+=2;
			if(dfs(u)){
				adj[u].pop_back();
				val[u][v]=1;
			}else
				val[u][v]=0;
			ans+=val[u][v];
			prv[u][v]=1;
		}
		printf("%d. %d\n",h++,ans);
	}
	return 0;
}

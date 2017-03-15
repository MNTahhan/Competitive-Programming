#include <bits/stdc++.h>
using namespace std;
const int N = 22;
int n,m,vis[N],s,t,d;
vector<pair<int,int> >adj[N];
vector<pair<int,vector<int> > >ans;
vector<int>cur;
void dfs(int u,int c){
	if(vis[u])
		return;
	vis[u]=1;
	cur.push_back(u);
	if(u==t){
		if(c<=d)
			ans.push_back(make_pair(c,cur));
		vis[u]=0;
		cur.pop_back();
		return;
	}
	for(int i=0;i<adj[u].size();++i)
		dfs(adj[u][i].first,adj[u][i].second+c);
	vis[u]=0;
	cur.pop_back();
}
int main() {
	int h=1,flag=0;
	while(scanf("%d",&n)>0 && n!=-1){
		if(flag)
			puts("");
		flag=1;
		scanf("%d",&m);
		for(int i=0;i<=n;++i)
			adj[i].clear();
		for(int i=0,u,v,c;i<m;++i){
			scanf("%d%d%d",&u,&v,&c);
			adj[u].push_back(make_pair(v,c));
			adj[v].push_back(make_pair(u,c));
		}
		scanf("%d%d%d",&s,&t,&d);
		ans.clear();
		dfs(s,0);
		printf("Case %d:\n",h++);
		if(!ans.size())
			puts(" NO ACCEPTABLE TOURS");
		else{
			sort(ans.begin(),ans.end());
			for(int i=0;i<ans.size();++i){
				printf(" %d: ",ans[i].first);
				for(int j=0;j<ans[i].second.size();++j)
					printf("%d ",ans[i].second[j]);
				puts("");
			}
		}
	}
	return 0;
}

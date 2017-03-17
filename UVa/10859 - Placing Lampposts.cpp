#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,vis[N],vs;
vector<int>adj[N];
pair<int,int> calc(int u,int p,int flag){
	vis[u]=vs;
	pair<int,int>res(flag,0);
	for(int i=0;i<adj[u].size();++i){
		int v=adj[u][i];
		if(v==p)
			continue;
		pair<int,int> x=calc(v,u,0);
		pair<int,int> y=calc(v,u,1);
		if(flag==0){
			res.first+=y.first;
			res.second+=y.second;
		}else{
			res.first+=min(x.first,y.first);
			if(x.first==y.first)
				res.second+=max(x.second,y.second+1);
			else if(x.first<y.first)
				res.second+=x.second;
			else
				res.second+=y.second+1;
		}
	}
	return res;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;++i)
			adj[i].clear();
		for(int i=0;i<m;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		++vs;
		int a=0,b=0;
		for(int i=0;i<n;++i)
			if(vis[i]!=vs){
				pair<int,int>res1=calc(i,-1,0);
				pair<int,int>res2=calc(i,-1,1);
				if(res1.first<res2.first)
					a+=res1.first,b+=res1.second;
				else if(res1.first>res2.first)
					a+=res2.first,b+=res2.second;
				else
					a+=res1.first,b+=max(res2.second,res1.second);
			}
		printf("%d %d %d\n",a,b,m-b);
	}
	return 0;
}

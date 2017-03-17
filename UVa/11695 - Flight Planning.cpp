#include <bits/stdc++.h>
using namespace std;
int n,p[2510];
vector<int>adj[2510];
void dfs(int u,int p,int c,int &len,int &node,int no){
	//cout<<u<<" "<<p<<" "<<c<<endl;
	if(c>len){
		len=c;
		node=u;
	}
	::p[u]=p;
	for(int i=0;i<adj[u].size();++i){
		int v=adj[u][i];
		if(v==p || v==no) continue;
		dfs(v,u,c+1,len,node,no);
	}
}
int diameter(int u,int no,vector<int>&res){
	int len=-1,node1,node2;
	dfs(u,-1,0,len,node1,no);
	len=-1;
	dfs(node1,-1,0,len,node2,no);
	for(int i=node2;i!=-1;i=p[i])
		res.push_back(i);
	return len;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<=n;++i)
			adj[i].clear();
		for(int i=1;i<n;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			--u;--v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int>v,res;
		int ans=diameter(0,-1,v);
		for(int i=0;i+1<v.size();++i){
			int u=v[i];
			int e=v[i+1];
			vector<int>l,r;
			int res1=diameter(u,e,l);
			int res2=diameter(e,u,r);
			int tmp=(res1+1)/2+(res2+1)/2+1;
			tmp=max(tmp,max(res1,res2));
			if(l.size() && r.size() && tmp<ans){
				ans=tmp;
				res.clear();
				res.push_back(u);
				res.push_back(e);
				res.push_back(l[l.size()/2]);
				res.push_back(r[r.size()/2]);
			}
		}
		printf("%d\n",ans);
		for(int i=0;i<4;i+=2)
			printf("%d %d\n",res[i]+1,res[i+1]+1);
	}
	return 0;
}

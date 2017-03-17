#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >c;
int n;
vector<int>ans,adj[55];
void dfs(int u){
	for(int i=0;i<55;++i)
		if(c[u][i]){
			--c[u][i]; --c[i][u];
			dfs(i);
		}
	ans.push_back(u);
}
int main(){
	int t,h=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		c.clear();
		c.resize(55,vector<int>(55,0));
		ans.clear();
		int s=1,x=0;
		for(int i=0;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			++c[x][y];
			++c[y][x];
			s=x;
		}
		for(int i=0;i<55;++i){
			int sum=0;
			for(int j=0;j<55;++j)
				sum+=c[i][j];
			x|=sum&1;
		}
		printf("Case #%d\n",h++);
		if(x&1)
			puts("some beads may be lost");
		else{
			dfs(s);
			for(int i=0;i<55;++i)
			for(int j=0;j<55;++j)
				x|=c[i][j]>0;
			if(x&1)
				puts("some beads may be lost");
			else
				for(int i=1;i<ans.size();++i)
					printf("%d %d\n",ans[i-1],ans[i]);
		}
		if(t)
			puts("");
	}
	return 0;
}

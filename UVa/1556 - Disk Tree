#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<map>
#include<time.h>
using namespace std;
#define print(x) cout<<#x<<" = "<<(x)<<endl
struct node{
	map<string,int>adj;
	node(){
		adj.clear();
	}
};
int n;
char s[110];
vector<node>v;
map<string,int>::iterator it;
void dfs(int cur,int c){
	vector<pair<string,int> >r;
	for(it=v[cur].adj.begin();it!=v[cur].adj.end();++it)
		r.push_back(make_pair(it->first,it->second));
	for(int i=0;i<r.size();++i){
		printf("%s%s\n",string(c,' ').c_str(),r[i].first.c_str());
		dfs(r[i].second,c+1);
	}
}
//void dfs(int cur,int c){
//	for(it=v[cur].adj.begin();it!=v[cur].adj.end();++it){
//		printf("%s%s\n",string(c,' ').c_str(),it->first.c_str());
//		dfs(it->second, c+1);
//	}
//}
int main(){
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	//clock_t t = clock();
	while(scanf("%d",&n)>0){
		v.clear();
		v.push_back(node());
		for(int i=0;i<n;++i){
			int cur=0;
			scanf("%s",s);
			int len=strlen(s);
			s[len++]='\\';
			string tmp="";
			for(int j=0;j<len;++j){
				if(s[j]=='\\'){
					if(v[cur].adj.find(tmp)==v[cur].adj.end()){
						v[cur].adj[tmp]=v.size();
						v.push_back(node());
					}
					cur=v[cur].adj[tmp];
					tmp="";
					continue;
				}
				tmp+=s[j];
			}
		}
		dfs(0,0);
		puts("");
	}
	//printf("Time = %.20lf\n",(double)(clock()-t)/CLOCKS_PER_SEC);
	return 0;
}

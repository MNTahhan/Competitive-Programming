#include <bits/stdc++.h>
using namespace std;
map<vector<int>,bool>flag,no;
map<string,vector<int> >res;
char s[22];
int main() {
	vector<string>ans;
	while(scanf("%s",s)>0 && strcmp(s,"#")!=0){
		string tmp=s;
		for(int i=0;i<tmp.size();++i)
			tmp[i]|=32;
		vector<int>f(26,0);
		for(int i=0;i<tmp.size();++i)
			++f[tmp[i]-'a'];
		res[s]=f;
		if(!flag[f]){
			flag[f]=1;
			ans.push_back(s);
			continue;
		}
		no[f]=1;
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();++i)
		if(!no[res[ans[i]]])
			printf("%s\n",ans[i].c_str());
	return 0;
}

/*
  The same solution imoplemented in the editorial: https://apps.topcoder.com/wiki/display/tc/SRM+509
*/
#include<bits/stdc++.h>
using namespace std;

long long dp[55][55],add[256],rem[256],rep[256][256],ans[256][256];
string s;
char E = 'z' + 1;
int calc(string s){
	int x=0;
	for(int i=0;i<s.size();++i)
		x=x*10+(s[i]-'0');
	return x;
}
long long go(int i,int j){
	if(i>=j)
		return 0;
	auto &ret=dp[i][j];
	if(~ret)
		return ret;
	ret = 1e11;
	ret = min(ret,ans[s[i]][s[j]]+go(i+1,j-1));
	ret = min(ret,ans[E][s[i]]+go(i+1,j));
	ret = min(ret,ans[E][s[j]]+go(i,j-1));
	return ret;
}

class PalindromizationDiv1{
public:
	int getMinimumCost(string s, vector <string> v){
		::s = s;
		for(int i='a';i<=E;++i){
			add[i]=rem[i]=1e11;
			for(int j='a';j<=E;++j){
				rep[i][j]=1e11;
				ans[i][j]=1e11;
			}
			rep[i][i]=0;
		}
		for(int i=0;i<v.size();++i)
			if(v[i][0]=='a'){
				long long x = calc(v[i].substr(6));
				rep[E][v[i][4]] = x;
			}else if(v[i][0]=='e'){
				long long x = calc(v[i].substr(8));
				rep[v[i][6]][E] = x;
			}else{
				long long x = calc(v[i].substr(11));
				rep[v[i][7]][v[i][9]] = x;
			}
		for(int k='a';k<=E;++k)
		for(int i='a';i<=E;++i)
		for(int j='a';j<=E;++j)
			rep[i][j]=min(rep[i][j],rep[i][k]+rep[k][j]);
		for(int k='a';k<=E;++k)
		for(int i='a';i<=E;++i)
		for(int j='a';j<=E;++j)
			ans[i][j]=min(ans[i][j], rep[i][k]+rep[j][k]);
		memset(dp,-1,sizeof dp);
		return go(0,s.size()-1)>=1e11 ? -1 : go(0,s.size()-1);
	}
};

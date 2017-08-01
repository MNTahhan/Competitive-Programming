/*
  The same solution implemented in editorial: http://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm144
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long dp[110][110];
long long choose(int r, int c){
	if(!c || r==c)
		return 1;
	if(dp[r][c]!=-1)
		return dp[r][c];
	return dp[r][c]=choose(r-1,c-1)+choose(r-1,c);
}
long long fact[10];
class Lottery{
public:
	vector <string> sortByOdds(vector <string> r){
		vector<pair<long long,string> >v;
		vector<string>ans;
		fact[0]=1;
		for(int i=1;i<10;++i)
			fact[i]=i*fact[i-1];
		memset(dp,-1,sizeof dp);
		for(int i=0;i<r.size();++i){
			string cur="";
			while(r[i][0]!=':'){
				cur+=r[i][0];
				r[i].erase(0,1);
			}
			r[i].erase(0,1);
			istringstream iss(r[i]);
			int x,y;
			iss>>x>>y;
			char c1,c2;
			iss>>c1>>c2;
			if(c1=='F' && c2=='F')
				v.push_back(make_pair(pow(x,y),cur));
			if(c1=='F' && c2=='T')
				v.push_back(make_pair(choose(x,y)*fact[y],cur));
			if(c1=='T' && c2=='T')
				v.push_back(make_pair(choose(x,y),cur));
			if(c1=='T' && c2=='F')
				v.push_back(make_pair(choose(x+y-1,y),cur));
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();++i)
			ans.push_back(v[i].second);
		return ans;
	}
};

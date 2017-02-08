#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[55][55][2];
int vis[55][55][2];
vector<int>v;
ll calc(int l,int r,int t){
	if(l>r)
		return 0;
	ll &ret=dp[l][r][t];
	if(vis[l][r][t])
		return ret;
	vis[l][r][t]=1;
	if(!t){
		ret=-1e18;
		ret=max(ret,v[l]+calc(l+1,r,1));
		ret=max(ret,v[r]+calc(l,r-1,1));
	}else{
		ret=1e18;
		ret=min(ret,calc(l+1,r,0)-v[l]);
		ret=min(ret,calc(l,r-1,0)-v[r]);
	}
	return ret;
}
class BagsOfGold{
public:
	int netGain(vector <int> v){
		::v=v;
		return calc(0,(int)v.size()-1,0);
	}
};

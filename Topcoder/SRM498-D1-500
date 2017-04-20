#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9+9;
int n,m;
map<vector<int>,int>cnt;
vector<int>v[220][220];
ll dp[100010];
ll calc(int x){
	if(!x)
		return 1;
	if(dp[x])
		return dp[x];
	return dp[x]=x*1LL*calc(x-1)%M;
}
class FoxStones{
public:
	int getCount(int N, int M, vector <int> sx, vector <int> sy){
		n=M;
		m=N;
		for(int i=0;i<sx.size();++i)
			--sx[i],--sy[i];
		sx.swap(sy);
		for(int i=0;i<sx.size();++i)
		for(int j=0;j<n;++j)
		for(int k=0;k<m;++k)
			v[j][k].push_back(max(abs(sx[i]-j),abs(sy[i]-k)));
		for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			++cnt[v[i][j]];
		ll ans=1;
		for(auto it=cnt.begin();it!=cnt.end();++it){
			ans*=calc(it->second);
			ans%=::M;
		}
		return ans;
	}
};

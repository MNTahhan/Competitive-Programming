/*
  try each possibility for ? and calc the minimum answer
*/
#include<bits/stdc++.h>
using namespace std;

int win[10], n, ans = 1e9;
vector<string>t;
void calc(int at,int j){
		if(at == n){
			int cur=0;
			for(int i=0;i<n;++i)
				cur=max(cur,win[i]);
			ans=min(ans,cur);
			return;
		}
		if(j==n){
			calc(at+1,0);
			return;
		}
		else if(t[at][j]=='?'){
			++win[at];
			calc(at,j+1);
			--win[at];
			++win[j];
			calc(at,j+1);
			--win[j];
		}else
			calc(at,j+1);
}

class TheBasketballDivTwo{
public:
		int find(vector <string> t){
			n = t.size();
			::t = t;
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					if(t[i][j]=='W') ++win[i];
					else if(t[i][j]=='L') ++win[j];
			calc(0,0);
			return ans;
		}
};

/* 
  The idea: binary search the answer, for each day get the minimum cost among all meals
*/
#include<bits/stdc++.h>
using namespace std;

int get(char c){
	if(c>='0' && c<='9') return c-'0';
	if(c>='A' && c<='Z') return c-'A'+10;
	return c-'a'+36;
}
int check(int mid,vector<string>&v,int x){
	int m=v[0].size();
	for(int i=0;i<7;++i){
		int mn=1e9;
		for(int j=0;j<m;++j){
			int sum=0;
			for(int k=i;k<mid;k+=7)
				sum+=get(v[k][j]);
			mn=min(mn,sum);
		}
		x-=mn;
	}	
	return x>=0;
}	

class MysteriousRestaurant{
public:
	int maxDays(vector <string> prices, int budget){
		int lo=1,hi=prices.size(),ans=0;
		while(lo<=hi){
			int mid=(lo+hi)>>1;
			if(check(mid,prices,budget)){
				ans=mid;
				lo=mid+1;
			}else
				hi=mid-1;
		}
		return ans;
	}
};

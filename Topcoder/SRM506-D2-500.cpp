/*
  The idea: try to make each twon the final city, for each one, add to it size the sizes of all town less than or equal to it, then try
            to add to it the largest city that is less than its size, and so on, until all the towns are merged.
*/
#include<bits/stdc++.h>
using namespace std;

class SlimeXSlimesCity{
public:
	int merge(vector <int> v){
		int ans = 0;
		for(int i=0;i<v.size();++i){
			vector<pair<int,int> >cur;
			for(int j=0;j<v.size();++j)
				cur.push_back(make_pair(v[j],j));
			sort(cur.begin(),cur.end());
			int j=0;
			int cnt=0;
			while(cur[j].second!=i)
				++j;
			cnt=j+1;
			long long sz = 0;
			cur[j].second = -1;
			while(j>=0)
				sz+=cur[j--].first;
			while(cnt<cur.size()){
				j=cur.size()-1;
				int flag = 0;
				while(cur[j].second!=-1){
					if(cur[j].first<=sz){
						sz+=cur[j].first;
						cur[j].second=-1;
						flag=1;
						++cnt;
					}
					--j;
				}
				if(!flag)
					break;
			}
			ans+=cnt==cur.size();
		}
		return ans;
	}
};

/*
  Idea: first, the even-piles will never affect the state, the one who start taking from them will loose them.
        now both players will try to take treasures that lies under piles with 1's, because if he is in loose state then he will never get the
        chance to take any thing else, and if he is in win state, then he must take as much as he can from them to minimize the looser 
        player score, after all ones finished, the number of odd piles determines the winner, if this number is odd, then the current
        player will take it all, else he will not get anything.
*/

#include<bits/stdc++.h>
using namespace std;

class StoneGame{
public:
	int getScore(vector <int> t, vector <int> s){
		vector<int>v;
		for(int i=0;i<s.size();++i)
			if(s[i]==1)
				v.push_back(t[i]);
		sort(v.rbegin(),v.rend());
		int ans=0;
		for(int i=0;i<v.size();i+=2)
			ans+=v[i];
		int cnt=v.size()&1;
		for(int i=0;i<s.size();++i)
			if(s[i]>1)
				cnt+=s[i]&1;
			else
				t[i]=0;
		if(!(cnt&1))
			return ans;
		for(int i=0;i<s.size();++i)
			ans+=t[i];
		return ans;
	}
};

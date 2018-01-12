/*
  The idea: start checking from the beginning of the string, if you found incorrect closed brase, replace it
            do the same from the end to the start and do the same
*/
#include<bits/stdc++.h>
using namespace std;

class ParenthesesDiv2Medium{
public:
	vector <int> correct(string s){
		vector<int>v;
		int cnt=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='(')
				++cnt;
			else 
				--cnt;
			if(cnt<0){
				v.push_back(i);
				cnt+=2;
			}
		}
		cnt=0;
		for(int i=s.size()-1;i>=0;--i){
			if(s[i]==')')
				++cnt;
			else
				--cnt;
			if(cnt<0){
				v.push_back(i);
				cnt+=2;
			}
		}
		return v;
	}
};

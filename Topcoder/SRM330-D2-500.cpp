/*
  The idea: brute force
*/
#include<bits/stdc++.h>
using namespace std;

class Arrows{
public:
	int longestArrow(string s){
		int ans=-1;
		for(int i=0;i<s.size();++i)
			if(s[i]=='<'){
				ans=max(ans,1);
				for(int j=i+1;j<s.size() && s[j]=='-';++j)
					ans=max(ans,j-i+1);
				for(int j=i+1;j<s.size() && s[j]=='=';++j)
					ans=max(ans,j-i+1);
			}else if(s[i]=='>'){
				ans=max(ans,1);	
				for(int j=i-1;j>=0 && s[j]=='-';--j)
					ans=max(ans,i-j+1);
				for(int j=i-1;j>=0 && s[j]=='=';--j)
					ans=max(ans,i-j+1);
			}
		return ans;
	}
};

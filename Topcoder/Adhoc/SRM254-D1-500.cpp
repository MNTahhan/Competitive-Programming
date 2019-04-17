/*
  try to put the initial one in each position, then make backtraking to put the others in the same way, the optimal way to put a pig 
  is to choose the longest and left-most empty sequence and put the pig in the middle of it.
*/
#include<bits/stdc++.h>
using namespace std;
string s;
int mx, ans;
void calc(int at, int cnt, int rem){
	if(rem==0 || s[at-1]=='p' && s[at+1]=='p'){
		if(cnt > mx){
			mx=cnt;
			ans=at;
		}
		return;
	}
	int c = -1, m = -1;
	for(int i=0;i<s.size();++i)
		if(s[i]=='-'){
			int cur=0;
			for(int j=i;j<s.size() && s[j] == '-';++j)
				++cur;
			if(cur > m){
				m=cur;
				c=i+(cur+1)/2-1;
			}
		}
	s[c]='p';
	calc(at,cnt+1,rem-1);
	s[c]='-';
}
class Piglets{
public:
	int choose(string S){
		s = S;
		if(s[0]=='-')
			return 0;
		int cnt=0;
		for(int i=0;i+1<s.size();++i)
			cnt += s[i]=='-';
		mx=ans=-1;
		for(int i=0;i<s.size();++i)	
			if(s[i] == '-'){
				s[i]='p';
				calc(i, 0, cnt);
				s[i]='-';
			}
		if(s[0] != '-' && s[s.size()-1]=='-')
			ans=s.size()-1;
		return ans;
	}
};


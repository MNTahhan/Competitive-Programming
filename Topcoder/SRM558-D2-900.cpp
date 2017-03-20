#include<bits/stdc++.h>
using namespace std;

class CatAndRabbit{
public:
	string getWinner(string s){
		vector<int>v;
		bool flag=0;
		for(int i=0;i<s.size();++i){
			int cnt=0;
			for(int j=i;j<s.size() && s[j]=='.';++j,i=j)
				++cnt;
			v.push_back(cnt);
		}
		for(int i=0;i<s.size();++i)
			flag|=s[i]=='#';
		int ans=0;
		for(int i=0;i<v.size();++i)
			ans^=v[i];
		return ans && flag?"Cat":"Rabbit";
	}
};

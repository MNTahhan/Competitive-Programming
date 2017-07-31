#include<bits/stdc++.h>
using namespace std;
int cur[256];
class Dating{
public:
	string dates(string s, int k){
		int last=0;
		string ans="";
		while(s.size()>1){
			int x = (k+last-1)%s.size();
			char mn='z'+1, idx=-1;
			int upper = s[x]>='A' && s[x]<='Z';
			for(int i=0;i<s.size();++i)
				if(upper && s[i]>'Z'){
					if(mn>s[i]){
						mn=s[i];
						idx=i;
					}
				}else if(!upper && s[i]<='Z'){
					if(mn>s[i]){
						mn=s[i];
						idx=i;
					}
				}
			if(idx==-1)
				break;
			if(ans.size())
				ans+=" ";
			ans+=s[x];
			ans+=mn;
			last=x;
			last-=x<last;
			last-=idx<last;
			if(x>idx){
				s.erase(x,1);
				s.erase(idx,1);
			}else{
				s.erase(idx,1);
				s.erase(x,1);
			}
		}
		return ans;
	}
};

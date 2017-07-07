// The idea: the same as misof's comment here https://apps.topcoder.com/forums//?module=Thread&threadID=743163&start=0
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class ImportantSequence{
public:
	int getCount(vector <int> b, string o){
		ll mx=0,mn=1e14;
		ll cur=0;
		int s=1;
		for(int i=0;i<b.size();++i){
			if(o[i]=='+'){
				cur=b[i]-cur;
				s*=-1;
			}else{
				cur=cur-b[i];
			}
			if(s==-1)
				mn=min(mn,cur);
			else
				mx=max(mx,-cur);
		}
		if(mn==1e14) return -1;
		if(mn<=mx) return 0;
		return mn-mx-1;
	}
};

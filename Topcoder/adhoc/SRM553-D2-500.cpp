/*
  The idea: first replace -1 with 0, then check
            then, simulate the process and replace -1 with 0 (as a value)
            then the result is wantedResult - the top of the stack
            we must check that this value is correct, other wise we get WA
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Suminator{
public:
	int findMissing(vector <int> p, int w){
		int n = p.size();
		int idx = -1;
		for(int i=0;i<p.size();++i)
			if(p[i]==-1){
				p[i]=0;
				idx = i;
			}
		vector<ll>v;
		for(int i=0;i<n;++i)
			if(p[i]==0){
				ll sum=0;
				if(v.size()) sum += v.back(), v.pop_back();
				if(v.size()) sum += v.back(), v.pop_back();
				v.push_back(sum);
			}else
				v.push_back(p[i]);
		ll top = v.size() ? v.back() : 0;
		if(top == w)
			return 0;
		if(idx == n - 1)
			return w;
		v.clear();
		int nidx = -1;
		int flag = 0;
		for(int i=0;i<n;++i)
			if(i==idx || p[i]!=0){
				v.push_back(p[i]);
				cout<<p[i]<<endl;
				if(i==idx) nidx=v.size() ? v.size()-1 : 0;
			}else{
				ll sum=0;
				if(v.size()) flag |= v.size() - 1 == nidx, sum += v.back(), v.pop_back();
				if(v.size()) flag |= v.size() - 1 == nidx, sum += v.back(), v.pop_back();
				v.push_back(sum);
			}
		if(!v.size()) v.push_back(0);
		if(!flag || w <= v.back())
			return -1;
		p[idx] = w - v.back();
		v.clear();
		for(int i=0;i<n;++i)
			if(p[i]==0){
				ll sum=0;
				if(v.size()) sum += v.back(), v.pop_back();
				if(v.size()) sum += v.back(), v.pop_back();
				v.push_back(sum);
			}else
				v.push_back(p[i]);
		if(!v.size()) v.push_back(0);
		if(v.back() == w)
			return p[idx];
		return -1;
	}
};

#include<bits/stdc++.h>
using namespace std;

class EmployManager{
public:
	int maximumEarnings(vector <int> v, vector <string> e){
		int ans=0;
		int n=v.size();
		for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			ans-=e[i][j]-'0';
		for(int i=0;i<n;++i){
			int cur=0;
			for(int j=0;j<n;++j)
				cur+=e[j][i]-'0';
			if(cur>v[i])
				ans+=cur-v[i];
		}
		return ans;
	}
};

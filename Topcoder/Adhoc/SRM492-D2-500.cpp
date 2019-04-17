/*
  The idea: there is two cases: 1) all of them are of the same length
                                2) fix two of them each time and try to make the others collinear with the resulting line
*/
#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-9

class TimeTravellingGardener{
public:
	int determineUsage(vector <int> d, vector <int> h){
		for(int i=1;i<d.size();++i)
			d[i]+=d[i-1];
		int ans=d.size();
		for(int i=0;i<h.size();++i)
			for(int j=i+1;j<h.size();++j){
				double x1=!i?0:d[i-1];
				double y1=h[i];
				double x2=d[j-1];
				double y2=h[j];
				double dx=x2-x1;
				double dy=y2-y1;
				double m=dy/dx;
				int cur=0;
				for(int k=0;k<h.size();++k){
					double x=!k?0:d[k-1];
					double y=h[k];
					double val=m*(x-x1)+y1;
					if(y+EPS<val || val<-EPS){
						cur=100;
						break;
					}else if(y>val+EPS)
						++cur; 
				}
				ans=min(ans,cur);
			}
		return ans;
	}
};

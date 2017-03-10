/* 
  The same approach in the editorial
*/

#include<bits/stdc++.h>
using namespace std;

class RightTriangle{
public:
	long long triangleCount(int places, int points, int a, int b, int c){
		vector<int>p(places,0);
		for(int i=0;i<points;++i)
			++p[(a*1LL*i*i + b*1LL*i + c) % places];
		int cnt=0;
		for(int j=0;j<2;++j)
		for(int i=0;i<places;++i)
			if(p[i]>1){
				cnt+=p[i]-1;
				p[i]=1;
			}else if(p[i]==0 && cnt){
				p[i]=1;
				--cnt;
			}
		for(int i=0;i<places;++i)
			assert(p[i]<=1);
		assert(cnt==0);
		long long ans=0;
		for(int i=0;i<places;++i)
			if(p[i] && p[(i+places/2)%places])
				ans+=points-2;
		return places%2==0?ans/2:0;
	}
};

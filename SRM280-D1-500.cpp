/*
  The same solution mentioned in the tutorial here: http://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm280
*/
#include<bits/stdc++.h>
using namespace std;

class GridCut{
public:
	int cutLength(int w, int h, int n){
		if(w*h==n)
			return 0;
		int ans=1e9;
		ans=min(ans,w+(n%w!=0));
		ans=min(ans,h+(n%h!=0));
		cout<<ans<<endl;
		for(int i=0;i<=w;++i)
		for(int j=0;j<=h;++j)
		if(i*j>=n)
			ans=min(ans,i+j);
		n=h*w-n;
		ans=min(ans,w+(n%w!=0));
		ans=min(ans,h+(n%h!=0));
		cout<<ans<<endl;
		for(int i=0;i<=w;++i)
		for(int j=0;j<=h;++j)
		if(i*j>=n)
			ans=min(ans,i+j);
		return ans;
	}
};

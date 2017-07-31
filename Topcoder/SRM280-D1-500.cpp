/*
  The same solution mentioned in the tutorial here: https://www.google.com.sa/?gfe_rd=cr&ei=aG1_WYGpK47Y8geygLyADw&gws_rd=ssl
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

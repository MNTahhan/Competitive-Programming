#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100010],l[100010],r[100010],n;
pair<int,int> seg[4*100010];
void build(int n,int s,int e){
	if(s==e){
		seg[n]=make_pair(a[s],s);
		return;
	}
	build(n*2,s,(s+e)/2);
	build(n*2+1,(s+e)/2+1,e);
	seg[n]=min(seg[n*2],seg[n*2+1]);
}
pair<int,int>get(int n,int s,int e,int l,int r){
	if(s>r || e<l)
		return make_pair(1<<30,-1);
	if(s>=l && e<=r)
		return seg[n];
	return min(get(n*2,s,(s+e)/2,l,r),get(n*2+1,(s+e)/2+1,e,l,r));
}
ll calc(int l,int r){
	if(l>r)
		return 0;
	pair<int,int>x = get(1,1,n,l,r);
	ll ans=(r-l+1)*1LL*x.first;
	ans=max(ans,calc(l,x.second-1));
	ans=max(ans,calc(x.second+1,r));
	return ans;
}
class BuildingAdvertise{
public:
	long long getMaxArea(vector <int> h, int n){
		::n=n;
		int j=0;
		for(int i=1;i<=n;++i){
			a[i]=h[j];
			int s=(j+1)%h.size();
			h[j]=((h[j]^h[s])+13)%835454957;
			j=s;
		}
		build(1,1,n);
		return calc(1,n);
	}
};
